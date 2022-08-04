- An object library is an aggregation of compiled object modules that can be employed by programs which are linked against the library.
- LINUX provides two types of libraries:
    1. static- used in earlier UNIX implementations
    2. shared- dominant type in use today
- Advantage of shared library- when a program is linked against an object library, copies of the object modules are not included in the resulting executable. 
- When the file is executed, the dynamic linker loads the required shared libraries. 
- During runtime, all programs using the same shared library share the single copy of the library in the memory.
- Since shared libraries are not copied into executable files and a single memory resident copy of the shared library is employed by all the programs at runtime, shared libraries use the amount of disk space and memory required by the system. 
- If any changes have to be made to the static library, it has to be recompiled and relinked. 
- Three important commands:
    1. ar -rc libstatic.a => -r inserts the file members into the archive libstatic.a. -c creates the archive. 
    2. gcc -g -o prog prog.o libstatic.a => allows us to use the static library
    3. gcc -g -fPIC -Wall -Werror -Wextra -pedantic *.c -shared -o libshared.so => allows us to create a shared library. -g includes debugging information in the compiled program. -fPIC standing for position independent code, generates the position independent code, allowing the shared library to be located at any virtual address at runtime. -shared creates the shared library. shared libraries have the prefix "lib" and the suffix "so".