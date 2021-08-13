/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 23:38:37 by mavinici          #+#    #+#             */
/*   Updated: 2021/08/13 09:25:32 by mavinici         ###   ########.fr       */
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
	if (check_extension(map_file, ".ber") <= 0)
		return (errors("Wrong extension of the map"));
	return (1);
}

void	free_map(char **map_str, t_map *map)
{
	int	i;

	i = 0;
	while (i <= map->line)
		free(map_str[i++]);
	free(map_str);
	i = 0;
	while (i <= map->line)
		free(map->backup_map[i++]);
	free(map->backup_map);
}

int	backup_map(t_map *map, char **map_str)
{
	int		i;
	int		line;

	line = map->line;
	map->backup_map = malloc(sizeof(char *) * line + 1);
	if (!map->backup_map)
		return (0);
	i = 0;
	while (i < line)
	{
		map->backup_map[i] = ft_strdup(map_str[i]);
		i++;
	}
	map->backup_map[i] = NULL;
	map->item_bup = map->check.collect;
	return (1);
}

int	recovery(t_map *map)
{
	int		i;
	int		line;

	i = 0;
	while (i <= map->line)
		free(map->map[i++]);
	free(map->map);
	line = map->line;
	map->map = malloc(sizeof(char *) * line + 1);
	if (!map->map)
		return (0);
	i = 0;
	while (i < line)
	{
		map->map[i] = ft_strdup(map->backup_map[i]);
		i++;
	}
	map->map[i] = NULL;
	map->check.collect = map->item_bup;
	return (1);
}
