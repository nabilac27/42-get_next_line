This repository contains my implementation of the get_next_line function, 

which reads and returns a single line from a file descriptor, including the newline character (if present). 


It dynamically handles memory and works efficiently with any valid file descriptor, including files and standard input.


The function reads input in chunks of size BUFFER_SIZE and ensures proper handling of multiple file descriptors and edge cases, 
such as empty files or reaching the end of a file.


Only the allowed functions (read, malloc, free) are used, and the implementation focuses on efficient memory management and clean, reusable code.
