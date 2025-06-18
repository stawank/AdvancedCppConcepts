#include<iostream>
#include<chrono>
#include<algorithm>
#include<thread>
#include<mutex>
#include<string>
using namespace std::chrono;
using namespace std;



/*
Timed Mutex:alignas
-   std::timed_mutex is blocked till timeout_time or the lock is acquired and returns true if success otherwise false.
-   Member functions
    1. lock
    2. unlock
    3. try_lock
    4. try_lock_for
    5. try_lock_untill
- Point 4 and 5 Makes it different from std::mutex




*/
int MyMoney = 0;
std::timed_mutex m;
void increament(int i){
    
    if(m.try_lock_for(std::chrono::seconds(3))){                        //Tweak these timings
        // critical section
        MyMoney++;
        std::this_thread::sleep_for(std::chrono::seconds(2));           //Tweak these timings
        cout<< "Thread "<< i<< "Entered "<< endl;
    }
    else{
        cout<< "Thread "<< i << "coudnt entered "<< endl;
    }
    m.unlock();
    
}

int main(){

    std::thread t1(increament, 1);
    std::thread t2(increament, 2);

    t1.join();
    t2.join();

    cout<< "Number of threads entered critical section: "<< MyMoney<< endl;



    return 0;
}