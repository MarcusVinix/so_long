/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 00:15:49 by mavinici          #+#    #+#             */
/*   Updated: 2021/08/12 00:31:14 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int main(int argc, char **argv)
{
	t_game game;
	
	game.end_game = 0;
	game.steps = 0;
	if (init_game(&game, argc, argv) < 0)
		return (0);
	//mlx_hook(game.win, 2, 1L<<0, test, (void *)&game);
	mlx_hook(game.win, 2, 1L<<0, action, (void *)&game);
	mlx_loop(game.mlx);
	return (0);
}
