/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 00:34:55 by mavinici          #+#    #+#             */
/*   Updated: 2021/08/11 09:05:02 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void start_map(t_map *map)
{
	map->colum = 0;
	map->line = 0;
	map->valid = 1;
	map->end_col = 0;
	map->check.collect = 0;
	map->check.exit = 0;
	map->check.player = 0;

}

char	**init_map(t_game *game, int argc, char **argv)
{
	char **map;
	
	map = read_map(argv[1], &game->map);
	if (!map)
		return (null_erro("error in the creation of the map"));
	return (map);
}

int	init_game(t_game *game, int argc, char **argv)
{
	t_map map;

	start_map(&map);
	game->map = map;
	game->map.map = init_map(game, argc, argv);
	if (game->map.map == NULL)
		return (-1);
	return (1);
}