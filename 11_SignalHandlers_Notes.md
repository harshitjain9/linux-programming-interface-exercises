- A signal is a notification that some event has occured and is then sent to a process by the kernel, another process, or by itself.
- There is a range of standard signal types, each of which has a unique number and purpose
- Signal delivery is usually asynchronous, meaning the point at which the signal interrupts execution of the process is unpredictable.
- For some cases, for example hardware generated signals, the signals are delivered synchronously, meaning the delivery occurs predictably and reproducibly.
- By default, a signal is ignored, terminates a process with or without a core dump, stops a running process or restarts a stopped process

