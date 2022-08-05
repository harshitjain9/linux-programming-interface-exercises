- Shared memory allows two or more processes to share the same pages of memory
- No kernel intervention is required to exchange data via shared memory
- Once a process has copied data to a shared memory segment, the data is immediately visible to other processes. 
- Shared memory provides fast interprocess communication (IPC). Normally we would need some type of synchronization technique, for eg. using semaphores, in order to manage access to the shared memory.
- The recommended approach when attaching a shared memory segment is to allow the kernel to choose the address at which the segment is attached in the process's virtual address space. 
- This means the segment may reside in different virtual addresses in different processes. 
- For this reason, all reference to addresses within the segment should be maintained as relative offsets rather than absolute addresses. 
- shmctl(int shmid, int cmd, struct shmid_ds *buf) system call performs a range of control operations on the shared memory segment identified by the shmid. cmd specifiees the control op to be performed, but required by the IPC_STAT and IPC_SET, and to be specified to NULL. IPC_STAT places the copy of shmid_ds in the shared memory segment pointed to by buf. IPC_SET updates the selected fields of the shmid_ds associated with the shared memory segment using values from the buffer pointed to by buf. 