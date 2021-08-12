/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 00:15:49 by mavinici          #+#    #+#             */
/*   Updated: 2021/08/11 18:54:28 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_win(int keycode, t_game *game)
{
	free_map(game->map.map, &game->map);
	exit(0);
}

int	test(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		free_map(game->map.map, &game->map);
		exit(0);
	}
	printf("keycode is : %i\n", keycode);
	game->map.map[3][11] = '0';
	game->map.map[2][4] = 'P';
	print_map(game);
	return (1);
}

int main(int argc, char **argv)
{
	t_game game;
	
	if (init_game(&game, argc, argv) < 0)
		return (0);
	//mlx_hook(game.win, 2, 1L<<0, test, (void *)&game);
	mlx_hook(game.win, 2, 1L<<0, action, (void *)&game);
	mlx_loop(game.mlx);
	return (0);
}
