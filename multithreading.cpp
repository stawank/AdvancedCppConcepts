#include<iostream>
#include<chrono>
#include<algorithm>
#include<thread>
using namespace std::chrono;
using namespace std;


typedef unsigned long long ull;

ull evenSum = 0;  
ull oddSum = 0;

    

void findEvenSum(ull start, ull end){
    
    for(ull i = start; i<= end; i++){
        if((i&1)==0){
            evenSum += i;
        }

    }
    
}

void findOddSum(ull start, ull end){
    
    for(ull i = start; i<= end; i++){
        if((i&1)==1){
            oddSum += i;
        }
        
    }
    
}

int main(){
    
    ull start = 0;
    ull end = 1900000000;
    auto startTime = high_resolution_clock::now();

    std::thread thread1(findEvenSum, start, end);
    std::thread thread2(findOddSum, start, end);


    thread1.join();
    thread2.join();
    // findEvenSum(start, end);
    // findOddSum(start, end);

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds> (stopTime - startTime); 

    cout<< "Even sum: " << evenSum<< endl;
    cout<< "Odd sum: "<< oddSum<< endl;

    cout<< "Sec: "<< duration.count()/1000000 << endl;




    return 0;
}
