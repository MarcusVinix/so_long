# Get Next Line

> This is the function get_next_line, which will return a line from a file descriptor passed, this is my second project as a cadet at School 42 São Paulo.

## Description

> The aim of this project is to make you code a function that returns a line ending with a newline, read from a file descriptor.  

> Calling the function get_next_line in a loop will then allow you to read the text available on a file descriptor one line at a time until the EOF.

>The return of this function is:
> * 1 if found a line with \n on the end;
> * 0 if found the last line of the file;
> * -1 if a error is found

### How use the function 

```c
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int	main(void)
{
	int		fd;
	int		gnl;
	char	*line;

	fd = open("file", O_RDONLY);
	gnl = get_next_line(fd, &line);
	while(gnl)
	{
		printf("%s\n", line);
		free(line);
		gnl = get_next_line(fd, &line);
	}
	free(line);
	close(fd);
	return (0);
}
```
> The function gnl make the allocation of memory for the variable line.  
> So its necessary call free after use the variable for avoid problems with leak.  
> This function has an undefined behavior if, between two calls, the same file descriptor switches to a different file before the EOF has been reached on the first fd.

> If you need read multiple files without reached the EOF, use the function bonus.  
> Its necessary just change the include of header used by `get_next_line_bonus.h`

```c
#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int	main(void)
{
	int		fd;
	int		fd2;
	int		fd3;
	char	*line;

	fd = open("file", O_RDONLY);
	fd2 = open("file3", O_RDONLY);
	fd3 = open("file3", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd2, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd3, &line);
	printf("%s\n", line);
	free(line);
	close(fd);
	close(fd2);
	close(fd2);
	return (0);
}
```

### How Compile

> Compilation will be done this way :  
> `gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32
get_next_line.c get_next_line_utils.c`  
> You can choose any length of BUFFER_SIZE.  
> If you want use the bonus part to be able to use multiple files descriptor, you just need add `_bonus` at the end of the name, `get_next_line_bonus.c`.