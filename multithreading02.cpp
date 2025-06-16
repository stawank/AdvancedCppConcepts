#include<iostream>
#include<chrono>
#include<algorithm>
#include<thread>
using namespace std::chrono;
using namespace std;

/*
Join
-   Once thread is started, we wait fpr this to finish by calling join() on thread object.
-   Double join will result into program termination.
-   If needed we should check thread is joinable using joinable() function. 



Detach
-   This should detach newly created thread from the parent thread. 
-   Always check before detaching a thread that it is joinable otherwise we may end up double detaching and
    double detach() will result into program termination. 
-   If we have detached thread and main function i s returning then the detached thread execution is suspended. 
*/

/*
If we create a thred, we MUST use Join() or Detach()
Otherwise, Parent thread will crash.!! 

*/


void run(int count){
    while(count--> 0){
    cout<< count;
    cout<< " CppNerd"<< endl;
    
    }
    std::this_thread::sleep_for(chrono::seconds(3));
    cout<< "Thread finished"<< endl;
}
int main(){
    std::thread t1 (run, 4);
    // As soon as above line is executed, athread will be created and it will start running function run, control will go to function run.
    // After that control will come back to main
    // main is parent thread of t1
    cout<< "main()"<< endl; // Main and t1 might be running parallely
    t1.join(); // main is waiting here to t1 to finish execution

    cout<< "main() after"<< endl;
    //t1.detach();  // detach the t1 from main thread -> Main says "I dont care whether t1 has finished or not, I will continue my execution"
    std::this_thread::sleep_for(chrono::seconds(5));





    return 0;
}