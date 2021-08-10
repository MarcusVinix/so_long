/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 00:15:49 by mavinici          #+#    #+#             */
/*   Updated: 2021/08/10 11:03:09 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int main(int argc, char **argv)
{
	t_map *map;
	int fd = open("../map_files/map.ber", O_RDONLY);
	printf("FD MAIN: %i\n", fd);
	int line = lines("../map_files/map.ber");
	

	printf("LINHAS: %i\n", line);
	close(fd);
	return (0);
}