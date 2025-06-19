#include <iostream> 
#include <thread>   
#include <mutex>  
#include<future>
#include<chrono>
#include<condition_variable>
#include<deque>


using namespace std;


/*
Producer Consumer Problem
Interview Question

Producer is a thread
Consumer is a thread

Common buffer -> Both threads try to modify this resource

Avoid race conditions

producer notify consumer -> using cv
consumer contify producer -> using cv



*/
using namespace std;

std::mutex m1;
std::condition_variable cv;
const unsigned int maxBufferSize = 50;
std::deque<int>  buffer;

void producer(int val){
    while(val){
        std::unique_lock<mutex> lock(m1);
        cv.wait(lock, []{return buffer.size()< maxBufferSize ;});
        buffer.push_back(val);
        cout<< "Produced: "<< val<< endl;
        val--;
        m1.unlock();
        cv.notify_one();
    }

}

void consumer(){
    while(1){
        std::unique_lock<mutex> lock(m1);
        cv.wait(lock, []{return buffer.size()> 0; });
        int val = buffer.back();
        buffer.pop_back();
        cout<< "Consumed: "<< val<< endl;
        m1.unlock();
        cv.notify_one();
    }

}

int main(){
    std::thread T1(producer, 100);
    std::thread T2(consumer);

    T1.join();
    T1.join();
    return 0;
}
