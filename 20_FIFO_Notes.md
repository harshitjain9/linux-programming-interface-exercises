- FIFO (first-in-first-out) operate in exactly the same way as pipes except that they are created using mkfifo() function.
- FIFO can be opened by any process with appropriate permissions. 
- By default, opening a FIFO for reading blocks another process opens the FIFO for writing and vice-versa. 