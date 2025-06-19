#include <iostream> 
#include <thread>   
#include <mutex>  
#include<future>
#include<chrono>

using namespace std;
using namespace std::chrono;
typedef long int ull;
/*
std::async

Notes
-   It runs a function asynchronously (potentially in a new thread) and returns a std::future that will hold the result
-   There are three launch policies for creating task:
    1.  std::launch::async (threading)
    2.  std::launch::deffered ( no separate thread is created)
    3.  std::launch::async | std::launch::defered (let computer decide)

How it works:
1.  It automatically creates a thread (or picks from thread pool) and a promise object for us. 
2.  Then passes, the std::promise object to the thread function and returns the associated std::future object. 
3.  When our passed argument function exists then. its value will be set inb this promise object, so eventually
    return value will be available in std::future object

Side Notes
-   We can send functor and lambda as callback function to std::async , it will work the same.  
*/


ull findOdd( ull Start, ull End){
    ull OddSum = 0;
    for(int i = Start; i <= End; ++i){
        if((i&1)==1){
            OddSum+= i;
        }
    }

    return OddSum;


}
int main(){
    ull start = 0;
    ull end = 1900000000;
    cout<< "Thread created if policy is std::launch::async"<< endl;
    std::future<ull> OddFuture= std::async(std::launch::async, findOdd, start, end);
    
    cout<< "Waiting for result"<< endl;

    cout<< "OddSum: "<< OddFuture.get()<< endl;  // Main will wait here untill the promise sends the value to future

    cout<< "completed"<< endl;


    return 0;
}