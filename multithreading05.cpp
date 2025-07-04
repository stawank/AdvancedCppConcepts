/*
SYNTAX -> std::try_lock(m1, m2, m3, m4, ...., mn)

-   std::try_lock()tries to lock akk the lockable objects passed in it one by one in given order. 
-   On success this function returns -1 otherwise it returns 0 based mutex index number which it could not lock.
-   If it fails to lock any of the mutex then it will release all the mutex locked before.
-   If a call to try_lock results in an exception, unlock is called for any locked objects before rethrowing

Notes
-   This is useful when we have multiple mutexes used in codebase and we need to lock all of them
    So, it is better to use 
    std::try_lock(m1, m2, m3, m4, m5)
    Rather than,
    m1.try_lock()
    m2.try_lock()
    m3.try_lock()
    m4.try_lock()
    m5.try_lock()


*/

#include<iostream>
#include<chrono>
#include<algorithm>
#include<thread>
#include<mutex>
#include<string>
using namespace std::chrono;
using namespace std;

std::mutex m1 , m2;
int X = 0;
int Y = 0;
void doSomeWorkForSeconds(int seconds){

    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}
void incrementXY(int& XorY, std::mutex& m, const char* desc){
    
    for (int i=0; i<5; ++i){
        m.lock();
            ++XorY;
            cout<< desc<< XorY<< endl;
        m.unlock();
        doSomeWorkForSeconds(2);
    }

}

void consumeXY(){
	int useCount = 5;
	int XplusY = 0;
	while(1){
		int lockResult = std::try_lock(m1,m2);
		if(lockResult == -1){
			if(X!=0 && Y!=0){
				--useCount;
				XplusY+=X+Y;
				X = 0;
				Y = 0;
				cout << "XplusY " << XplusY << '\n';
			}
			m1.unlock();
			m2.unlock();
			if(useCount == 0) break;
		}
	}

}

int main(){
    std::thread t1(incrementXY, std::ref(X), std::ref(m1), "X ");
	std::thread t2(incrementXY, std::ref(Y), std::ref(m2), "Y ");
	std::thread t3(consumeXY);

	t1.join();
	t2.join();
	t3.join();
	return 0;
}