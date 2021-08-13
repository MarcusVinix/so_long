/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:40:43 by mavinici          #+#    #+#             */
/*   Updated: 2021/08/13 17:57:36 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_img	init_image(void *mlx)
{
	t_img	img;

	init_wall(&img, mlx);
	init_exit(&img, mlx);
	init_item(&img, mlx);
	init_player(&img, mlx);
	init_enemy(&img, mlx);
	return (img);
}

void	print_player(t_game *game, t_pos pos)
{
	if (game->side == DOWN)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.player.down.img, pos.x, pos.y);
	else if (game->side == TOP)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.player.top.img, pos.x, pos.y);
	else if (game->side == RIGHT)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.player.right.img, pos.x, pos.y);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.player.left.img, pos.x, pos.y);
}

static void	print_sprites_cex(t_game *game, int line, int col)
{
	int	x;
	int	y;

	x = col * TILES;
	y = line * TILES;
	if (game->map.map[line][col] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.exit.img, x, y);
	}
	if (game->map.map[line][col] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.item.img, x, y);
	}
	if (game->map.map[line][col] == 'V')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.enemy.img, x, y);
	}
}

static void	print_sprites_wpe(t_game *game, int line, int col)
{
	int		x;
	int		y;
	t_pos	pos;

	pos.x = col * TILES;
	pos.y = line * TILES;
	x = col * TILES;
	y = line * TILES;
	if (game->map.map[line][col] == '1')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.wall.img, x, y);
	}
	if (game->map.map[line][col] == '0')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.emp.img, x, y);
	}
	if (game->map.map[line][col] == 'P')
	{
		print_player(game, pos);
	}
}

void	print_map(t_game *game)
{
	int		line;
	int		col;
	char	*str;

	line = 0;
	while (line < game->map.line)
	{
		col = 0;
		while (col < game->map.colum)
		{
			print_sprites_cex(game, line, col);
			print_sprites_wpe(game, line, col);
			col++;
		}
		line++;
		str = ft_itoa(game->steps);
		mlx_string_put(game->mlx, game->win, 25, 25, 0xFFFF00,
			"CURRENT STEP:");
		mlx_string_put(game->mlx, game->win, 120, 25, 0xFFFF00, str);
		free(str);
		if (game->end_game)
			mlx_string_put(game->mlx, game->win, 150, 25, 0xFFFF00,
				"YOU WIN PRESS R TO PLAY AGAIN!!");
	}
}
