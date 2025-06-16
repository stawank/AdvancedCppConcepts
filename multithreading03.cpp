#include<iostream>
#include<chrono>
#include<algorithm>
#include<thread>
using namespace std::chrono;
using namespace std;

/*
Mutex : Mutual Exclusion

Race Condition: 
-   Race condition is a situation where two or more threads/processes happened to change a commom data at the same time. 
-   If there is a race condition then we have to protect it and the protected section is called as critical section/region. 

MUTEX:
-   Mutex is used to avoid race condition. 
-   We use lock(), unlock() on mutex to avoid race conditions. 
*/

int MyMoney = 0;
std::mutex m;
void addMoney(){
    
    m.lock();
    // critical section
    MyMoney++;
    m.unlock();
    
}

int main(){

    std::thread t1(addMoney);
    std::thread t2(addMoney);

    t1.join();
    t2.join();

    cout<< MyMoney<< endl;



    return 0;
}