#include<iostream>
#include<chrono>
#include<algorithm>
#include<thread>
#include<mutex>
#include<string>
using namespace std::chrono;
using namespace std;



/*

Recursive Mutex
1.  It is same as mutex but, same thread can lock one mutex multiple times using recursive mutex. 
    If thread T1 first call lock/try_lock on recursive mutex m1, then m1 is locked by T1. 
    Now, as long as T1 is running in recursion T1 can call lock/try_lock any number of times there is no issue. 
2.  But if T1 have acquired 10 times lock/try_lock on mutex m1 then thread T1 will have to unlock it 10 times otherwise no other thread
    will be able to lock mutex m1.
    That means recursive mutex keeps count how many times it was locked so that many times it should be unlocked. 
3.  How many times we can lock recursive mutex is not defined but when that number reaches and if we were calling lock()
    it will return std::system_error OR if we were calling try_lock()then it will return false. 

Notes
-   It is same mutex but have extra facility that it can be locked multiple time by same thread.
-   If we can avoid recursive mutex then we should because it brings overhead to the system.
-   It can be used in loops also. 



*/
std::recursive_mutex m1;
int buffer =0;
void recursion(char c, int loopFor){

    if(loopFor<0){
        return;
    }
    m1.lock();
    cout<< c <<" "<< buffer++<< endl;
    recursion(c, --loopFor);
    m1.unlock();
}


int main(){
    std::thread T1(recursion, '1', 5);
    std::thread T2(recursion, '2', 5 );
    T1.join();
    T2.join();

    return 0;
}