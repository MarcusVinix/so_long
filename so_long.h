#ifndef SO_LONG_H

# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <limits.h>


# define BUFFER_SIZE 1

typedef struct	s_map
{
	int		colum;
	int		line;
	char	**map;
} 				t_map;

void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);

int		lines(char *map);
char	**read_map(char *path, t_map *o_map);

#endif