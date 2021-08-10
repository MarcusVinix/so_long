/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 11:11:11 by mavinici          #+#    #+#             */
/*   Updated: 2021/05/28 22:12:46 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	count_c(char const *s, char c)
{
	int	i;
	int	count;
	int	w;

	w = 0;
	i = 0;
	count = 0;
	while (s[i])
	{	
		if (s[i] == c)
			w = 0;
		else if (s[i] != c && w == 0)
		{
			w = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static char	*word(char const *s, char c)
{
	char	*word;
	int		len;
	int		i;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc(len + 1);
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		f;
	int		w;

	array = (char **)malloc((count_c(s, c) + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	i = -1;
	f = -1;
	w = 0;
	while (s[++i])
	{
		if (s[i] == c)
			w = 0;
		else if (s[i] != c && w == 0)
		{
			w = 1;
			array[++f] = word(s + i, c);
			if (array[f] == NULL)
				return (NULL);
		}
	}
	array[count_c(s, c)] = 0;
	return (array);
}
