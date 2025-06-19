#include <iostream> 
#include <thread>   
#include <mutex>  
#include<future>
#include<chrono>

using namespace std;
using namespace std::chrono;


/*
std::promise 
1.  Ussed to set values or exceptions

std::future
1.  Used to get values from promise
2.  Ask promise if the value is available
3.  Wait for the promise

*/


typedef long int ull; 

void findOdd(std::promise<ull>&& OddSumPromise, ull Start, ull End){
    ull OddSum = 0;
    for(int i = Start; i <= End; ++i){
        if((i&1)==1){
            OddSum+= i;
        }
    }

    OddSumPromise.set_value(OddSum);


}


int main(){
    ull start = 0;
    ull end = 1900000000;
    std::promise<ull> OddSum;
    std::future<ull> OddFuture= OddSum.get_future();
    std::thread T1(findOdd,std::move(OddSum),start, end);
    cout<< "Waiting for result"<< endl;

    cout<< "OddSum: "<< OddFuture.get()<< endl;  // Main will wait here untill the promise sends the value to future

    cout<< "completed"<< endl;
    T1.join();

    return 0;
}