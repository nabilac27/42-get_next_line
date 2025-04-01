#include "get_next_line.h"

int	main(void)
{
	//   int open(const char *path, int oflag, ...);

	int fd = open("./abc.txt", O_RDONLY);
	printf("number fd = %d\n\n", fd);

	//    int fd2 = open("./abc.txt", O_RDONLY);
	//    printf("number fd2 = %d\n", fd2);

	char *line;
	int i = 0;
	while(1)
	{

	    line =  get_next_line(fd);  //hello\n //im\n //nabila\n //\n //NULL

	    if (line == NULL)
	        break ;
	    i++;

	    printf("line(%d) =[%s]\n", i ,line);
	    // if (i == 5)
	    //     break ;
	}

	// line = get_next_line(fd);
	// printf("line = [%s]", line);

	close(fd);
	// close(fd2);

	return (0);
}