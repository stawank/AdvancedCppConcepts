#include<iostream>
#include<chrono>
#include<algorithm>
#include<thread>
#include<mutex>
#include<string>
using namespace std::chrono;
using namespace std;


/*
Unique Lock

SYNTAX: std::unique_lock<mutex> lock(m1)

-   The class unique_lock is a mutex ownership wrapper. 
-   It allows:
    a. Can have different locking strategies
    b. time-constrained attempts at locking (try_lock_for, try_lock_untill)
    c. recursive locking
    d. transfer of lock ownership (move not copy)
    e. condition variables

- Locking strategies:
    TYPE                        EFFECTS
1.  defer_lock                  do not acquire ownership of the mutex
2.  try_to_lock                 try to acquire ownership of the mutex without blocking
3.  adopt_lock                  assume the calling thread already has ownership of the mutex


*/

std::mutex m1;
int buffer = 0;


void task(const char* threadNumber, int loopFor){
    // Normal Working of Unique lock
    // std::unique_lock<mutex> lock (m1);
    // for(int i=0; i<loopFor;++i){
    //     buffer++;
    //     cout<< threadNumber<< " "<< buffer << endl;
    // }


    // Defer lock
    std::unique_lock<mutex> lock (m1, defer_lock);
    // We need to explicitely lock the mutex
    lock.lock();
    for(int i=0; i<loopFor;++i){
        buffer++;
        cout<< threadNumber<< " "<< buffer << endl;
    }
    // unlock is not needed as it will be unlocked in destructor of unique_lock
}

int main(){
    std::thread T1 (task, "T1", 5);
    std::thread T2 (task, "T2", 5);
    T1.join();
    T2.join();
    return 0;
}