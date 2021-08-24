/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 10:43:47 by mavinici          #+#    #+#             */
/*   Updated: 2021/08/24 11:08:22 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/* Check which side the player will and store in side variable */
void	check_side(t_game *game, int key)
{
	if (key == DOWN)
		game->side = DOWN;
	else if (key == TOP)
		game->side = TOP;
	else if (key == RIGHT)
		game->side = RIGHT;
	else if (key == LEFT)
		game->side = LEFT;
}

/* This function call auxiliary functions to check if its possible move */
/* If its possible to move, so where the player was */
/* will be fill with empty space */
/* and the player will to received position, also steps will be incremented. */
void	move_player(t_game *game, int line, int col, int key)
{
	int	y;
	int	x;
	int	valid;

	y = game->map.player.y;
	x = game->map.player.x;
	valid = verify_move(game, line, col, key);
	check_side(game, key);
	if (game->end_game)
		kill_player(game);
	if (valid > 0)
	{
		if (game->map.map[line][col] == 'C')
			game->map.check.collect--;
		game->map.map[y][x] = '0';
		game->map.map[line][col] = 'P';
		game->map.player.y = line;
		game->map.player.x = col;
		game->steps++;
	}
}

/* Check if its possible to move the player */
/* If its a wall the return will be -1 */
/* If its the exit and the collectable its different of 0  will return -1 */
/* If  its exit and the collectable its equal 0 */
/* so the variable end_game will receive 1(true) */
/* and will return -1, if its a enemy will return -1 */
/* and the game will be restarted */
/* Will be returned -1 if the key its diferrent of AWSD */
int	verify_move(t_game *game, int line, int col, int key)
{
	if (game->map.map[line][col] == '1')
		return (-1);
	if (game->map.map[line][col] == 'E' && game->map.check.collect == 0)
		game->end_game = 1;
	if (game->map.map[line][col] == 'E')
		return (-1);
	if (game->end_game)
		return (-1);
	if (game->map.map[line][col] == 'V')
	{
		game->side = DOWN;
		reset(game);
		return (-1);
	}
	if (key != TOP && key != DOWN && key != LEFT && key != RIGHT)
		return (-1);
	else
		return (1);
}
