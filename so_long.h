#ifndef SO_LONG_H

# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <limits.h>
# include "src/get_next_line/get_next_line.h"


# define BUFFER_SIZE 1

typedef struct	s_map_check
{
	int	player;
	int	exit;
	int	collect;
} 				t_map_check;

typedef struct	s_map
{
	int		valid;
	int		end_col;
	int		colum;
	int		line;
	t_map_check check;
	char	**map;
} 				t_map;

typedef struct	s_position
{
	int	x;
	int	y;
} 				t_pos;



//utils
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);

//map
char	**read_map(char *path, t_map *o_map);
void	verify(int valid, t_map *map);
int		check_wall(char c);
int		check_c(char c, t_map *map);
int 	valid_cpe(t_map *map);
int		check(char c, t_map *map, int col, int line);
int		valid_map(int argc, char *map_file);
void	free_map(char **map_str, t_map *map);

//erros
int		errors(char *message);
void	*null_erro(char *message);
void	warning(char *message);

#endif