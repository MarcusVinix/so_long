/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 23:56:21 by mavinici          #+#    #+#             */
/*   Updated: 2021/08/10 11:01:52 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	counts(int fd, int count_lines, int count_col)
{
	int		size;
	char	buffer;
	int tmp;

	tmp = 0;	
	while (true)
	{
		size = read(fd, &buffer, BUFFER_SIZE);
		printf("size: %i\n", size);
		if (size < 0)
			return (-1);			
		if (buffer == '\n')
			count_lines++;
		else if (buffer != '\n' && size > 0)
			count_col++;
		if (tmp == 0 && buffer == '\n')
			tmp = count_col;
		printf("TMP: %i COLUM: %i\n", tmp, count_col);
		if (tmp != count_col && (buffer == '\n' || size == 0))
			return (-1);
		else if (buffer == '\n')
			count_col = 0;
		if (size == 0)
			break ;
	}
	return (count_lines);
}

int	lines(char *map)
{
	int		fd;
	int		count_lines;
	int		count_col;
	
	fd = open(map, O_RDONLY);
	printf("FD: %i\n", fd);
	if (fd < 0)
		return (-1);
	count_lines = 1;
	count_col = 0;
	printf("FD: %i  %i\n", fd, count_lines);
	count_lines = counts(fd, count_lines, count_col);
	if (count_lines < 0)
		return (-1);
	close(fd);
	return (count_lines);
}
