/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 21:28:40 by mavinici          #+#    #+#             */
/*   Updated: 2021/05/14 21:28:40 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../../so_long.h"
#include <string.h>
size_t	ft_strlen(const char *s)
{
	size_t				len;

	len = 0;
	while ((unsigned char)s[len])
		len++;
	return (len);
}
