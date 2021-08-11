/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 00:15:49 by mavinici          #+#    #+#             */
/*   Updated: 2021/08/11 16:00:06 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_win(int keycode, t_game *game)
{
	int i = 0;
	free_map(game->map.map, &game->map);
	exit(0);
}

int main(int argc, char **argv)
{
	t_game game;
	
	if (init_game(&game, argc, argv) < 0)
		return (0);
	mlx_hook(game.win, 2, 1L<<0, close_win, (void *)&game);
	mlx_loop(game.mlx);
	return (0);
}
