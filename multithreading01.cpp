#include<iostream>
#include<chrono>
#include<algorithm>
#include<thread>
using namespace std::chrono;
using namespace std;


/*
NOTE:
-   If we create multiple threads at the same time, it doesnt guarantee which one will start first.


Different ways of creating Threads.
There are 5 different types of creation.


1. Function Pointer

*/

void f (int x){

    while(x-- >0){
        cout<< x << endl;
    }
}


/*
2. Lambda Functions
Functions without name.
Lamdas should be declared where they are used -> in main
*/

// auto myLambda = [](int age){
//     cout<< "My age is:  "<< age << " years"<< endl;
// }


/*
3.  Functor (Function Object)


*/

class Base{
    public:
    void operator ()(int x){
        while(x-- >0){
            cout<< x <<endl;
        }
    }



};

/*
4. Non Static Member Function


*/

class MyClass{
    public: // Public because it is called not by any member functions
    void run(int x){
        while(x-- > 0){

            cout<< x << endl;
        }
    }



};


/*
5. Static Member function

*/
class MyClass2 {
    public:

    static void function(int x){
        while(x-- > 0){
            cout<< x<< endl;
        }
    }


};

int main(){
    // Function Pointers
    std::thread t1(f, 10);
    std::thread t2(f,11);

    t1.join();
    t2.join();

    // Lambda Functions
    auto myLambda = [](int age){
    cout<< "My age is:  "<< age << " years"<< endl;
    };
    std::thread t3(myLambda, 20);
    t3.join();

    // Functor
    std::thread t4(Base(), 5);

    t4.join();

    // Non Static Member Function
    MyClass c;
    std::thread t5 (&MyClass::run, &c, 3);
    t5.join();

    // Static Member function
    // No need to create object of class

    std::thread t6(&MyClass2::function, 6);
    t6.join();


    return 0;
}