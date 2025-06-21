#include<stdio.h>
#include<cuda.h>


__global__ void dkernel(){
    /*
    GPU Kernel 
    Executed on GPU

    __global__ tells nvcc compiler that this is GPU function(kernel)
    */
    printf("Hello World");

}


int main(){


    dkernel<<<1,1>>>();
    /*
    why <<<>>> ? 
    for kernel launch

    why 1,1 ?
    tells GPU that launch this function on 1*1 i.e. single thread.

    CPU and GPU both are ***executing asynchronously.*** <- Key takeaway
    No one is waiting for each other.

    */
    dkernel<<<1,1>>>();
    dkernel<<<1,1>>>();
    dkernel<<<1,1>>>();
    dkernel<<<1,1>>>();

    cudaDeviceSynchronise();
    /*
    This tells the CPU to wait, till kernel is executed on GPU.
    Just like we join threads.

    After this execution of main will take place.

    */
    printf("on CPU\n")

    
    return 0;
}

/*

Wont run and execute on CPU based systems.
compile:  nvcc hello.cu -> cuda compiler
run: a.out
*/