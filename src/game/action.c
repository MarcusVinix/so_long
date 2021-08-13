/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:55:09 by mavinici          #+#    #+#             */
/*   Updated: 2021/08/12 20:38:05 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/*
UP 65362
DOWN 65364
LEFT 65361
RIGHT 65363
x = coluna
y = linha 
*/

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

int	verify_move(t_game *game, int line, int col, int key)
{
//	printf("what is the house %c\n", game->map.map[line][col]);
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
		reset(game);
		return (-1);
	}	
	if (key != TOP && key != DOWN && key != LEFT && key != RIGHT )
		return (-1);
	else
		return (1);
}

void	kill_player(t_game *game)
{
	int	y;
	int x;

	y = game->map.player.y;
	x = game->map.player.x;
	game->map.map[y][x] = '0';
	print_map(game);
}

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

void	move_player(t_game *game, int line, int col, int key)
{
	int y;
	int x;
	int valid;

	//printf("testeee line  %i colum %i\n", line, col);
	y = game->map.player.y;
	x = game->map.player.x;
	valid = verify_move(game, line, col, key);
	if (game->end_game)
		kill_player(game);
	//printf("\ny : %i x : %i   line %i col %i move : %i how many colectables %i\n", y, x, line, col, verify_move(game, line, col), game->map.check.collect);
	check_side(game, key);
	if (valid > 0)
	{
		if (game->map.map[line][col] == 'C')
			game->map.check.collect--;
		game->map.map[y][x] = '0';
		game->map.map[line][col] = 'P';
		game->map.player.y = line;
		game->map.player.x = col;
		game->steps++;
		printf("CURRENT STEP: %i\n", game->steps);
	}
}

int	action(int keycode, t_game *game)
{
	int line;
	int col;

	line = game->map.player.y;
	col = game->map.player.x;
	if (keycode == 65307)
		close_win(game);
	if (keycode == 114)
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
	{
	//	mlx_clear_window(game->mlx, game->win);
		move_player(game, line, col, keycode);
		//print_map(game);

	}

	return (1);
}

int	update(t_game *game)
{
	if (game->reset < 30)
		game->reset += 0.1;
	else if (game->end_game < 1)
	{
		//printf("LIMPEI");
		mlx_clear_window(game->mlx, game->win);
		game->reset = 0;
	}
	//printf("CLEAR\n");
	if (game->end_game < 1)
	{
		//printf("reset is %.2f\n", game->reset);
		print_map(game);
	}
	return (0);
}
