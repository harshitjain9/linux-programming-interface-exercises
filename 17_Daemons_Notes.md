- A daemon is a long-lived process which has no controlling terminal and runs in the background. 
- Daemons perform specific tasks, such as providing a network login facility or serving webpages. 
- A daemon is usually created either by a process forking a child process and then immediately exiting, thus causing init to adopt the child process, or by the init process directly launching the daemon.
- To become a daemon, a program performs a standard sequence of steps, such as a call to fork() and setsid(). 
- Steps required to become a daemon:
    1. fork
    2. setsid - Create a new session. The calling process becomes the leader of the new session and the process group leader of the new process group. The process is detached from its controlling terminal. 
    3. catch signals - Ignore or handle signals. 
    4. fork again - Let the parent process terminate to ensure that you get rid of the session leading process. 
    5. chdir- Change the working directory of the daemon
    6. umask- You have to change the file mode mask according to the needs of the daemon. 
    7. close- Close all the open file descriptors that may be inherited by the parent process
