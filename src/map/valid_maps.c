/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 23:38:37 by mavinici          #+#    #+#             */
/*   Updated: 2021/08/12 19:45:51 by mavinici         ###   ########.fr       */
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
	if (check_extension(map_file, ".ber") <= 0)
		return (errors("Wrong extension of the map"));
	return (1);
}

void	free_map(char **map_str, t_map *map)
{
	int	i;
	//printf("ENTREI FREE");
	i = 0;
	while (i <= map->line)
			free(map_str[i++]);
	free(map_str);
	i = 0;
	while (i <= map->line)
			free(map->backup_map[i++]);
	free(map->backup_map);
}

void	*backup_map(t_map *map, char **map_str)
{
	int		i;
	int		line;

	line = map->line;
	map->backup_map = malloc(sizeof(char *) * line + 1);
	if (!map->backup_map)
		return (NULL);
	i = 0;
	while (i < line)
	{
		map->backup_map[i] = ft_strdup(map_str[i]);
		i++;
	}
	map->backup_map[i] = NULL;
	map->item_bup = map->check.collect;
}

void	*recovery(t_map *map)
{
	int		i;
	int		line;

	//printf("ENTREI FREE");
	i = 0;
	while (i <= map->line)
			free(map->map[i++]);
	free(map->map);
	line = map->line;
	map->map  = malloc(sizeof(char *) * line + 1);
	if (!map->map)
		return (NULL);
	i = 0;
	while (i < line)
	{
		map->map[i] = ft_strdup(map->backup_map[i]);
		i++;
	}
	map->map[i] = NULL;
	map->check.collect = map->item_bup;
}
