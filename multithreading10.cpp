#include<iostream>
#include<chrono>
#include<algorithm>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<string>
using namespace std::chrono;
using namespace std;


/*
Condition Variable in C++ Threading

Conditional variables are used for 2 purposes
A. Notify other threads
B  Waiting for some conditions

-   Conditional variable allows running threads to wait on some conditions and once those conditions are met waiting thread is notified
    using:
        a. notify_one()
        b. notify_all()
-   You need mutex to use condition variable
-   If some thread want to wait on some condition then it has to so these things:
    a. Acquire the mutex lock using std::unique_lock<std::mutex> lock(m)
    b. Execute wait, wait for, or wait_until. The wait operations automatically release the mutex 
        and suspend the execution of the thread.
    c. When the condition variable is notified, the thread is awakened, and the mutex is automatically reacquired.
        The thread should then check the condition and resume waiting if the wake up wass spurious. 


Note:
1.  Condition variables are used to synchronise two or more threads. 
2.  Best use case of condition variable is Producer/COnsumer problem. 

*/

std::condition_variable cv;
std::mutex m;

long balance = 0;

void addMoney(int money){
    std::lock_guard<mutex> lg(m);
    balance += money;
    cout<< "Amount added, current balance: "<< balance<< endl;
    cv.notify_one();
}

void withdrawMoney(int money){
    std::unique_lock<mutex> ul(m);
    cv.wait(ul, []{return (balance!=0) ? true: false; });
    if(balance>= money){
        balance-=money;
        cout<< "Amount deducted "<< money << endl;

    }else{
        cout<<" Amount cant be deducted, current balance is less than "<< money<< endl;
    }
    cout<< "Current balance: "<< balance<< endl;
}

int main(){
    
    std::thread T2 (withdrawMoney, 50);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::thread T1 (addMoney, 50);
    T1.join();
    T2.join();
    
    return 0;
}