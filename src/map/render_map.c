/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:40:43 by mavinici          #+#    #+#             */
/*   Updated: 2021/08/11 16:09:38 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_img	init_image(void *mlx)
{
	t_img img;

	init_wall(&img, mlx);
	init_empty(&img, mlx);
	init_exit(&img, mlx);
	init_item(&img, mlx);
	init_player(&img, mlx);
	return (img);
}

static void	print_sprites_cex(t_game *game,int line, int col)
{
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
}

static void	print_sprites_wpe(t_game *game,int line, int col)
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
}

void print_map(t_game *game)
{
	int	line;
	int	col;

	line = 0;
	while (line < game->map.line)
	{
		col = 0;
		while (col < game->map.colum)
		{
			if (game->map.map[line][col] == 'C')
				print_sprites_cex(game, line, col);
			if (game->map.map[line][col] == 'E')
				print_sprites_cex(game, line, col);
			print_sprites_wpe(game, line, col);
			col++;
		}
		line++;
	}
}
