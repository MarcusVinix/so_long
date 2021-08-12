/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:55:09 by mavinici          #+#    #+#             */
/*   Updated: 2021/08/11 21:35:57 by mavinici         ###   ########.fr       */
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

int	verify_move(t_game *game, int line, int col)
{

	printf("what is the house %c\n", game->map.map[line][col]);
	if (game->map.map[line][col] == 'C')
		game->map.check.collect--;
	if (game->map.map[line][col] == '1')
		return (-1);
	else if (game->map.map[line][col] == 'E')
		return (-1);
	else
		return (1);
}

void	move_player(t_game *game, int line, int col)
{
	int y;
	int x;

	printf("testeee line  %i colum %i\n", line, col);
	y = game->map.player.y;
	x = game->map.player.x;
	printf("\ny : %i x : %i   line %i col %i move : %i how many colectables %i\n", y, x, line, col, verify_move(game, line, col), game->map.check.collect);
	if (verify_move(game, line, col) > 0)
	{
		game->map.map[y][x] = '0';
		game->map.map[line][col] = 'P';
		game->map.player.y = line;
		game->map.player.x = col;
	}
	if (game->map.map[line][col] == 'C')
		game->map.check.collect++;
}

int	action(int keycode, t_game *game)
{
	int line;
	int col;

	mlx_clear_window(game->mlx, game->win);
	line = game->map.player.y;
	col = game->map.player.x;
	if (keycode == 65307)
	{
		free_map(game->map.map, &game->map);
		exit(0);
	}
	if (keycode == 65362)
		line--;
	if (keycode == 65364)
		line++;
	if (keycode == 65361)
		col--;
	if (keycode == 65363)
		col++;
	move_player(game, line, col);
	print_map(game);
	printf("ACTION KEY IS %i\n", keycode);
	return (1);
}

void	swap_map(t_game *game)
{

}