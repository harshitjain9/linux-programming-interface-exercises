- fork() system call creates a child process which is an exact duplicate of the parent process
- After the fork() call, we can't be sure of the order in which the parent and child processes will be next scheduled by the OS.
- A process can terminate either abnormally or normally
- Abnormal termination of a process occurs on the delivery of certain signals, some of which also cause the process to produce a core dump file
- Normal termination occurs by calling exit() or _exit()- there is a minor diff b/w exit() and _exit()
- The exit() function performs some cleaning before the termination of the process, such as connection termination, buffer flushing etc while the _exit() does normal termination without doing any cleanup tasks
