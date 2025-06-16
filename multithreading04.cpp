#include<iostream>
#include<chrono>
#include<algorithm>
#include<thread>
using namespace std::chrono;
using namespace std;

/*
mutex::try_lock()

-   try_lock() Tries to lock the mutex. Returns immediately. On successful lock acquisition returns true otherwise returns false. 
-   If try_lock() is not able to lock mutex, then it doesnt get blocked thats why it is called non-blocking. 
-   If try_lock()is called again by the same thread which owns the mutex, the behaviour is undefined. 
    It os a dead lock situation with undefined behaviour. (If you want to be able to lock the same mutex by the same thread more than one time
    then go for recursive_mutex)

-   There are so many types of try_lock functions
    1. std::try_lock
    2. std::mutex::try_lock
    3. std::shared_lock::try_lock
    4. std::timed_mutex::try_lock
    5. std::unique_lock::try_lock
    6. std::shared_mutex::try_lock
    7. std::recursive_mutex::try_lock
    8. std::shared_timed_mutex::try_lock
    9. std::recursive_timed_mutex::try_lock

*/

int counter = 0;
std::mutex mtx;

void increaseCounterBy100000(){
    for(int i=0; i< 100000; i++){
        if(mtx.try_lock()){
            counter++;
            mtx.unlock();
        }
    }
}

int main(){
    std::thread t1(increaseCounterBy100000);
    std::thread t2(increaseCounterBy100000);

    t1.join();
    t2.join();

    cout<< "Counter could increase upto: "<< counter<< endl;
    /*
    If we compile and run, we get everytime different counter values if wqe use try lock
    We would get exact 200000 value when we use mtx.lock()   !! Interesting
    */

    return 0;
}