/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 18:11:11 by mavinici          #+#    #+#             */
/*   Updated: 2021/06/05 18:11:11 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total;
	size_t	i;
	char	*newstr;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	total = ft_strlen(s1) + ft_strlen(s2);
	newstr = (char *)malloc(sizeof(char) * (total + 1));
	if (!newstr)
		return (NULL);
	while (*s1)
		newstr[i++] = *s1++;
	while (*s2)
		newstr[i++] = *s2++;
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strdup(const char *s)
{
	char	*new_str;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	new_str = malloc(len + 1);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[len] = '\0';
	return (new_str);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*s_s;
	unsigned char	s_c;

	s_s = (unsigned char *)s;
	s_c = (unsigned char)c;
	if (*s_s == s_c)
		return ((char *)s);
	while (*s_s++)
	{
		if (*s_s == s_c)
			return ((char *)s_s);
	}
	return (NULL);
}

char	*ft_line(char *s, size_t len)
{
	char			*line;
	size_t			i;

	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
