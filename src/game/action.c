/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:55:09 by mavinici          #+#    #+#             */
/*   Updated: 2021/08/13 17:45:22 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	reset(t_game *game)
{
	recovery(&game->map);
	game->map.player.x = game->map.player_bup.x;
	game->map.player.y = game->map.player_bup.y;
	game->end_game = 0;
	game->steps = 0;
	game->side = DOWN;
}

int	close_win(t_game *game)
{
	free_map(game->map.map, &game->map);
	exit(0);
}

void	kill_player(t_game *game)
{
	int	y;
	int	x;

	y = game->map.player.y;
	x = game->map.player.x;
	game->map.map[y][x] = '0';
	game->side = DOWN;
	print_map(game);
}

int	action(int keycode, t_game *game)
{
	int	line;
	int	col;

	line = game->map.player.y;
	col = game->map.player.x;
	if (keycode == ESC)
		close_win(game);
	if (keycode == RESET)
		reset(game);
	if (keycode == TOP)
		line--;
	if (keycode == DOWN)
		line++;
	if (keycode == LEFT)
		col--;
	if (keycode == RIGHT)
		col++;
	if (!game->end_game)
		move_player(game, line, col, keycode);
	return (1);
}

int	update(t_game *game)
{
	if (game->reset < 30)
		game->reset += 0.1;
	else if (game->end_game < 1)
	{
		mlx_clear_window(game->mlx, game->win);
		game->reset = 0;
	}
	print_map(game);
	return (0);
}
