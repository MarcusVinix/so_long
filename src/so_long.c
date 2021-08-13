/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 00:15:49 by mavinici          #+#    #+#             */
/*   Updated: 2021/08/13 10:29:56 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	start_struct(t_game *game)
{
	game->side = 0;
	game->reset = 0;
	game->end_game = 0;
	game->steps = 0;
	game->init_game = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	start_struct(&game);
	if (init_game(&game, argc, argv) < 0)
		return (0);
	mlx_hook(game.win, 17, 0, close_win, (void *)&game);
	mlx_hook(game.win, 2, 1L << 0, action, (void *)&game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_loop(game.mlx);
	return (0);
}
