/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 23:38:37 by mavinici          #+#    #+#             */
/*   Updated: 2021/08/11 08:47:05 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/* this funtion will verify the argc and the map extension */
int	valid_map(int argc, char *map_file)
{
	if (argc == 1)
		return (errors("don't have argv"));
	if (argc > 2)
		warning("Just the first argv will be used");
	//todo 
	//some function to verify the extension of the map
	return (0);
}

void	free_map(char **map_str, t_map *map)
{
	int	i;
	printf("ENTREI FREE");
	i = 0;
	while (i <= map->line)
			free(map_str[i++]);
	free(map_str);
}
