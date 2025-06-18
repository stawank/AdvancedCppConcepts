#include<iostream>
#include<chrono>
#include<algorithm>
#include<thread>
#include<mutex>
#include<string>
using namespace std::chrono;
using namespace std;

/*
Lock Guard

SYNTAX : std::lock_guard<mutex> object_name(mutex_object)

1.  It is light weight wrapper for owning mutex on scoped basis.
2.  It acquires mutex lock the moment you create the object of lock_guard. 
3.  It automatically removes the lock while it goes out of scope. 
4.  You cannot exxplicitely unlock the lock guard. 
5.  You cannot copy lock guard. 
*/


std::mutex m1;
int buffer = 0;

void task(const char* threadNumber, int loopFor){
    // Example with mutex
    // m1.lock();
    // for(int i = 0; i< loopFor; ++i){
    //     buffer++;
    //     cout<< threadNumber <<" "<< buffer << endl;
    // }
    // m1.unlock();

    // Example with lock guard
    std::lock_guard<mutex> lock(m1);
    for(int i = 0; i< loopFor; ++i){
        buffer++;
        cout<< threadNumber <<" "<< buffer << endl;
    }
    
}


int main(){
    std::thread T1(task, "T1", 10);
    std::thread T2(task, "T2", 10);
    T1.join();
    T2.join();

    return 0;
}