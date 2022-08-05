- In order to trace system calls, we have the strace() command which allows us to trace the system call made by a program. 
- This is useful for debugging or simply to find out what a program is doing. 
- Using strace on terminal, producing a trace of the system calls the program makes --> strace command arguments..
- By default, strace will write its output on to the stderror file, but you can change it to any file you want using the -o flag
- Even for a simple program, the output produced by strace is going to be huge. For these reasons, it is sometimes useful to selectively filter the output of strace and get the output that you just want. f
- Examples:
    1. strace date 2>&1 --> without filter
    2. strace date 2>&1 | grep open --> with filter, only include those lines in the output with "open" in them
    3. strace -e trace=open,close date --> to trace all "open" and "close" system calls
