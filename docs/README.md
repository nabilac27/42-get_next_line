### **get_next_line**

This repository contains my implementation of the **get_next_line** function,
which reads and returns a single line from a file descriptor, including the newline character (if present). 

The function is designed to be memory-efficient and can handle any valid file descriptor, 
such as files and standard input.

#### **Key Concepts**

- **Dynamic Memory Management**: The function dynamically allocates memory as needed and ensures proper management of memory throughout the process, using only the allowed functions: `read`, `malloc`, and `free`.
- **Efficient Chunk Reading**: The function reads input in chunks of a specified size, determined by `BUFFER_SIZE`. It handles multiple file descriptors and edge cases such as reaching the end of a file or reading an empty file.
- **Multiple File Descriptors**: The implementation efficiently manages multiple file descriptors, ensuring that the state for each file descriptor is maintained separately.

#### **Function Overview**

| **Function** | **Description** |
|--------------|-----------------|
| `get_next_line(int fd)` | Reads and returns a single line from the file descriptor `fd`. If a newline is present, it includes it; otherwise, it returns the data up to the end of the file or the buffer size limit. |
| `read_into_buffer(char *buffer, int fd)` | Reads data from the file descriptor `fd` into the buffer `buffer` until the buffer is full, a newline is encountered, or the end of the file is reached. |
| `next_line(char buffer[])` | Processes the buffer to extract the next line. This function isolates the portion of the buffer containing the new line or the content before a newline character. |
| `clear_buffer(char buffer[])` | Clears the buffer for the next read cycle, resetting it to ensure no leftover data from the previous read. |

#### **Helper Functions**

| **Function** | **Description** |
|--------------|-----------------|
| `ft_strjoin(char *s1, char *s2)` | Joins two strings `s1` and `s2` into a new dynamically allocated string, concatenating the contents of both. |
| `ft_strchr(const char *ptr_string, int ptr_find)` | Searches for the first occurrence of the character `ptr_find` in the string `ptr_string` and returns a pointer to that location. |
| `ft_strlen(const char *str)` | Returns the length of the string `str`, excluding the null-terminator. |
| `ft_strlcpy(char *dst, const char *src, int dstsize)` | Copies the string `src` to `dst`, ensuring that the result is null-terminated and no more than `dstsize - 1` characters are copied. |
| `ft_strjoin_free(char *s1, char *s2)` | Joins `s1` and `s2` into a new string, then frees the memory allocated to `s1`, returning the new concatenated string. |

---

#### **Bonus: Multiple File Descriptors**

The bonus aspect of this project is to handle **multiple file descriptors**. In the original version of `get_next_line`, the function works with a single file descriptor. However, for this implementation, the function has been extended to support multiple file descriptors simultaneously.
