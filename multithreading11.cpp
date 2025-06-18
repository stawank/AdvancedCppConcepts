#include<iostream>
#include<chrono>
#include<algorithm>
#include<thread>
#include<mutex>
#include<string>
using namespace std::chrono;
using namespace std;

/*
Deadlocks

*/
std::mutex m1;
std::mutex m2;

void Process1(){
m1.lock();
std::this_thread::sleep_for(std::chrono::seconds(2));
m2.lock();
cout<< "Critical section of process 1."<< endl;
m1.unlock();
m2.unlock();


}

void Process2(){
m2.lock();
m1.lock();
cout<< "Critical section of process 2."<< endl;
m2.unlock();
m1.unlock();


}

// To avoid deadlock comment above process2 and uncomment following

// void Process2(){
// m1.lock();
// m2.lock();
// cout<< "Critical section of process 2."<< endl;
// m1.unlock();
// m2.unlock();


// }
int main(){
    std::thread T1(Process1);
    std::thread T2(Process2);

    T1.join();
    T2.join();

    return 0;
}