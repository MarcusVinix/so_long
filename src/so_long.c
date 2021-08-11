/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 00:15:49 by mavinici          #+#    #+#             */
/*   Updated: 2021/08/11 13:17:18 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_win(int keycode, t_game *game)
{
	int i = 0;
	free_map(game->map.map, &game->map);
	exit(0);
}

t_img	new_sprite(void *mlx)
{
	t_img img;

	img.wall.img = mlx_xpm_file_to_image(mlx, PATH_W, &img.wall.size.x, &img.wall.size.y);
	img.wall.pixel = mlx_get_data_addr(img.wall.img, &img.wall.bpp, &img.wall.line_size, &img.wall.endian);

	img.emp.img = mlx_xpm_file_to_image(mlx, PATH_E, &img.emp.size.x, &img.emp.size.y);
	img.emp.pixel = mlx_get_data_addr(img.emp.img, &img.emp.bpp, &img.emp.line_size, &img.emp.endian);

	img.exit.img = mlx_xpm_file_to_image(mlx, PATH_EX, &img.exit.size.x, &img.exit.size.y);
	img.exit.pixel = mlx_get_data_addr(img.exit.img, &img.exit.bpp, &img.exit.line_size, &img.exit.endian);

	img.player.img = mlx_xpm_file_to_image(mlx, PATH_P, &img.player.size.x, &img.player.size.y);
	img.player.pixel = mlx_get_data_addr(img.player.img, &img.player.bpp, &img.player.line_size, &img.player.endian);

	img.item.img = mlx_xpm_file_to_image(mlx, PATH_I, &img.item.size.x, &img.item.size.y);
	img.item.pixel = mlx_get_data_addr(img.item.img, &img.item.bpp, &img.item.line_size, &img.item.endian);

	return (img);
}

void print_sprites(t_game *game)
{
	int	line;
	int	col;

	line = 0;
	while (line < game->map.line)
	{
		col = 0;
		while (col < game->map.colum)
		{
			if (game->map.map[line][col] == '1')
			{
				game->img.wall.pos.x = col * TILES;
				game->img.wall.pos.y = line * TILES;

				mlx_put_image_to_window(game->mlx, game->win, 
				game->img.wall.img, game->img.wall.pos.x, game->img.wall.pos.y);
			}
			if (game->map.map[line][col] == '0')
			{
				game->img.emp.pos.x = col * TILES;
				game->img.emp.pos.y = line * TILES;

				mlx_put_image_to_window(game->mlx, game->win, 
				game->img.emp.img, game->img.emp.pos.x, game->img.emp.pos.y);
			}
			if (game->map.map[line][col] == 'P')
			{
				game->img.player.pos.x = col * TILES;
				game->img.player.pos.y = line * TILES;

				mlx_put_image_to_window(game->mlx, game->win, 
				game->img.player.img, game->img.player.pos.x, game->img.player.pos.y);
			}
			if (game->map.map[line][col] == 'E')
			{
				game->img.exit.pos.x = col * TILES;
				game->img.exit.pos.y = line * TILES;

				mlx_put_image_to_window(game->mlx, game->win, 
				game->img.exit.img, game->img.exit.pos.x, game->img.exit.pos.y);
			}
			if (game->map.map[line][col] == 'C')
			{
				game->img.item.pos.x = col * TILES;
				game->img.item.pos.y = line * TILES;

				mlx_put_image_to_window(game->mlx, game->win, 
				game->img.item.img, game->img.item.pos.x, game->img.item.pos.y);
			}
			col++;
		}
		line++;
	}
}

int main(int argc, char **argv)
{
	t_game game;
	
	if (init_game(&game, argc, argv) < 0)
		return (0);
	game.img = new_sprite(game.mlx);

	game.img.wall.pos.x = 0;
	game.img.wall.pos.y = 0;
	mlx_put_image_to_window(game.mlx, game.win, 
	game.img.wall.img, game.img.wall.pos.x, game.img.wall.pos.y);

	print_sprites(&game);

	//int fd = open("map_files/map.ber", O_RDONLY);
	//printf("FD MAIN: %i\n", fd);
	//int line = lines("map_files/map.ber", &map);
	//game.map->map = read_map("map_files/map.ber", game.map);
//	if (map.map == NULL)
//		return (-1);
	printf("Entrei\n");
//	t_map map;
//	map.colum = 0;
//	map.line = 0;
//	map.valid = 1;
//	map.end_col = 0;
//	map.check.collect = 0;
//	map.check.exit = 0;
//	map.check.player = 0;
//	game.map = map;
//
//	game.map.map = read_map(argv[1], &game.map);
	//if (game.map.map)
	//{
	//	printf("LINHAS: %i COLUM: %i\n", game.map.line, game.map.colum);
	//	int i = 0;
	//
	//	printf("Entrei\n");
	//	while (i < game.map.line)
	//		printf("%s\n", game.map.map[i++]);
	//	i = 0;
	//	while (i <= game.map.line)
	//		free(game.map.map[i++]);
	//	free(game.map.map);
	//}

	mlx_hook(game.win, 2, 1L<<0, close_win, (void *)&game);
	mlx_loop(game.mlx);
	
//	close(fd);
	return (0);
}
