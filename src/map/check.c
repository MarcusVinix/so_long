/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:46:42 by mavinici          #+#    #+#             */
/*   Updated: 2021/08/10 23:38:50 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/* verify if the map is arounded of walls */
void	verify(int valid, t_map *map)
{
	if (map->valid == 1)
		map->valid = valid;
	//printf("validddd is %i\n", map->valid);
}

int	check_wall(char c)
{
	if (c == '1')
		return (1);
	else
		return (0);
}

int	check_c(char c, t_map *map)
{
	if (c == 'P')
		map->check.player += 1;
	if (c == 'E')
		map->check.exit += 1;
	if (c == 'C')
		map->check.collect += 1;
	if (c == 'P' || c == '1' || c == 'C' || c == 'E' || c == '0')
		return (1);
	else
		return (0);

}

int valid_cpe(t_map *map)
{
	if (map->check.collect < 1)
		return (0);
	if (map->check.exit < 1)
		return (0);
	if (map->check.player > 1 || map->check.player < 1)
		return (0);
	return (1);
}

int	check(char c, t_map *map, int col, int line)
{
	int	valid_c;

	valid_c = check_c(c, map);
	if (valid_c == 0 && c != '\n')
		return (0);
	if ((line == 1 || col == 0) && c != '\n')
		return (check_wall(c));
	if ((map->end_col == col) && c != '\n')
		return (check_wall(c));
	return (1);
}