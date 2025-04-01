# **get_next_line**

This repository contains my implementation of the **get_next_line** function, which reads and returns a single line from a file descriptor, including the newline character (if present).

## **Key Concepts**

- **Dynamic Memory Management**: The function uses only `read`, `malloc`, and `free` to manage memory efficiently.
  
- **Efficient Chunk Reading**: It reads data in chunks, defined by `BUFFER_SIZE`, and handles cases like the end of a file or an empty file.

- **Multiple File Descriptors**: Supports multiple file descriptors and keeps track of the state of each one separately.

## **Bonus: Multiple File Descriptors**
This implementation handles multiple files at once, maintaining the state of each file descriptor independently.

---

## **Functions Overview**

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
