#ifndef SO_LONG_H

# define SO_LONG_H

# define TILES 64
# define PATH_W "./sprite_file/wood.xpm"
# define PATH_E "./sprite_file/colorstone.xpm"
# define PATH_EX "./sprite_file/barrel.xpm"
# define PATH_P "./sprite_file/knight2.xpm"
# define PATH_I "./sprite_file/cake.xpm"

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <limits.h>
# include "src/get_next_line/get_next_line.h"


# define BUFFER_SIZE 1

typedef struct	s_position
{
	int	x;
	int	y;
} 				t_pos;

typedef struct	s_map_check
{
	int	player;
	int	exit;
	int	collect;
} 				t_map_check;

typedef struct	s_map
{
	t_pos	player;
	int		valid;
	int		end_col;
	int		colum;
	int		line;
	t_map_check check;
	char	**map;
} 				t_map;


typedef struct	s_data
{
	void	*img;
	char	*pixel;
	t_pos	pos;
	t_pos	size;
	int		bpp;
	int		line_size;
	int		endian;
}				t_data;

typedef struct	s_img
{
	t_data	wall;
	t_data	emp;
	t_data	exit;
	t_data	player;
	t_data	item;
}				t_img;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_img	img;
	int		end_game;
	int		steps;
}				t_game;

//utils
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);

//map
char	**read_map(char *path, t_map *o_map);
void	verify(int valid, t_map *map);
int		check_wall(char c);
int		check_c(char c, t_map *map, int col, int line);
int 	valid_cpe(t_map *map);
int		check(char c, t_map *map, int col, int line);
int		valid_map(int argc, char *map_file);
void	free_map(char **map_str, t_map *map);

//print map
t_img	init_image(void *mlx);
void 	print_map(t_game *game);

//init sprites
void	init_wall(t_img *img, void *mlx);
void	init_empty(t_img *img, void *mlx);
void	init_exit(t_img *img, void *mlx);
void	init_item(t_img *img, void *mlx);
void	init_player(t_img *img, void *mlx);

//erros
int		errors(char *message);
void	*null_erro(char *message);
void	warning(char *message);

//game
int		init_game(t_game *game, int argc, char **argv);
int		action(int key, t_game *game);

#endif