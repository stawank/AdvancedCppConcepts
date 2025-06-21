# AdvancedCppConcepts

## A little bit about GPUs
-   GPUs (Graphics Processing Units) are specialized hardware designed to accelerate the processing of images and computations that can be performed in parallel. 
-   Originally developed for rendering graphics, modern GPUs are widely used for general-purpose computing tasks (GPGPU), such as scientific simulations, machine learning, and data processing.

### Performance Comparison:

-   Parallelism:
GPUs have thousands of smaller, efficient cores designed for handling multiple tasks simultaneously, making them ideal for parallel workloads. CPUs have fewer, more powerful cores optimized for sequential processing.

-   Throughput:
For highly parallel tasks (like matrix operations, image processing, or deep learning), GPUs can be much faster than CPUs—sometimes by orders of magnitude.

-   Latency:
CPUs are better for tasks that require low latency and complex logic, as they have higher clock speeds and more sophisticated control logic.


### Definitions
-   DRAM: Large, slower, main memory.
-   Cache: Small, very fast, temporary.
-   A core is an individual processing unit within a CPU or GPU that can execute instructions independently.

#### CUDA Specific Definitions
-   CPU(host): minimize time of one task. Metric: Latency in seconds
-   GPU (device): Maximize throughput. Metric: throughput in tasks per second (ex: pixels per ms)
-   Kernel (GPU function): A kernel in CUDA programming is a function written to run on the GPU. When you launch a kernel, it is executed in parallel by many threads on the GPU, allowing you to process large amounts of data efficiently.
-   GEMM: GEneral Matrix Multiplication
-   SGEMM: Single precision(fp32) GEneral Matrix Multiplication
-   cpu/host/functions vs GPU/Device/kernels

### Typical CUDA Program
1.  CPU allocates CPU memory
2.  CPU copies data to GPU
3.  CPU launches kernel on GPU (Processing is done here)
4.  CPU copies back the results from GPU back to CPU to do something useful with it

