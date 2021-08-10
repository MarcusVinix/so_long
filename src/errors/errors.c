/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:04:18 by mavinici          #+#    #+#             */
/*   Updated: 2021/08/10 16:37:57 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/*  message error for functions with return int */
int	errors(char *message)
{
	printf("\n%s\n", message);
	return (0);
}

/* message error for functions that return null for error */
void	*null_erro(char *message)
{
	printf("\n%s\n", message);
	return (0);
}

/* print a warning for the user */
void	warning(char *message)
{
	printf("\n%s\n", message);
}
