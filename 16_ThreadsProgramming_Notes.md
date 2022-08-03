- A thread is a single sequence stream within a process.
- Because threads have some of the properties of processes, they are sometimes called lightweight processes. 
- Threads are not independent of one another, unlike processes. 
- Threads share with other threads their code and data.
- However, a thread has its own program counter, the register set and the stack space. 
- Threads are a popular way to improve applications through parallelism. For example, in a browser, multiple tabs can be different threads; in MS Word, there can be one thread to format the text, another to process the input etc. 
- Threads operate faster than processes due to following reasons
    1. Thread creation is much faster
    2. Context switching between different threads is much faster 
    3. Threads can be terminated very easily
    4. Communication between threads is faster as compared to that of processes
- Join statement is a blocking statement and waits until the created thread terminates. It is similar to wait() function used for child processes. 