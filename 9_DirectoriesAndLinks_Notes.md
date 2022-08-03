- An inode does not contain a file's name
- Instead, files are assigned names via entries in directories, which are tables listing file names and inode number correspondences
-  A file may have multiple links, all of which enjoy equal status
-  Links are created using link() and unlink() 
- You can create, remove, open using the in-built functions within C programs like mkdir(), rmdir(), opendir() 


