## **get_next_line**

This repository contains my implementation of the **get_next_line** function,
which reads and returns a single line from a file descriptor, including the newline character (if present). 

The function is designed to be memory-efficient and can handle any valid file descriptor, 
such as files and standard input.

### **Key Concepts**

- **Dynamic Memory Management**: The function dynamically allocates memory as needed and ensures proper management of memory throughout the process, using only the allowed functions: `read`, `malloc`, and `free`.
- **Efficient Chunk Reading**: The function reads input in chunks of a specified size, determined by `BUFFER_SIZE`. It handles multiple file descriptors and edge cases such as reaching the end of a file or reading an empty file.
- **Multiple File Descriptors**: The implementation efficiently manages multiple file descriptors, ensuring that the state for each file descriptor is maintained separately.

### **Bonus: Multiple File Descriptors**

This implementation supports multiple file descriptors. It manages the state for each file descriptor independently, allowing the function to handle multiple files at the same time.

---

### **Functions Overview**

| **Function**                          | **Description** |
|---------------------------------------|-----------------|
| `get_next_line(int fd)`               | Reads and returns a single line from the file descriptor `fd`. |
| `read_into_buffer(char *buffer, int fd)` | Reads data from the file descriptor into the buffer. |
| `next_line(char buffer[])`            | Extracts the next line from the buffer. |
| `clear_buffer(char buffer[])`         | Clears the buffer after reading a line. |
| `ft_strjoin(char *s1, char *s2)`      | Concatenates two strings `s1` and `s2` into a new string. |
| `ft_strchr(const char *ptr_string, int ptr_find)` | Finds the first occurrence of `ptr_find` in `ptr_string`. |
| `ft_strlen(const char *str)`          | Returns the length of `str`. |
| `ft_strlcpy(char *dst, const char *src, int dstsize)` | Copies `src` into `dst` ensuring it doesn't exceed `dstsize`. |
| `ft_strjoin_free(char *s1, char *s2)` | Joins `s1` and `s2` and frees `s1`. |
