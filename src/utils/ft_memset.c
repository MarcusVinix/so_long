/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 19:24:14 by mavinici          #+#    #+#             */
/*   Updated: 2021/05/14 19:24:14 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s_s;
	size_t			i;

	i = 0;
	s_s = (unsigned char *)s;
	while (i < n)
	{
		s_s[i] = c;
		i++;
	}
	return (s);
}
