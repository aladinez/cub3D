/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:18:44 by aez-zaou          #+#    #+#             */
/*   Updated: 2020/11/09 18:17:27 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	my_bzero(void *s, size_t n)
{
	size_t			j;
	unsigned char	*str;

	str = (unsigned char*)s;
	j = 0;
	while (j < n)
	{
		str[j] = 0;
		j++;
	}
}

void	*my_calloc(size_t count, size_t size)
{
	void	*tab;
	size_t	i;

	i = 0;
	if (size == 0)
	{
		if ((tab = malloc(1)) == NULL)
			return (NULL);
		my_bzero(tab, 1);
		return (tab);
	}
	tab = malloc(count * size);
	if (tab == NULL)
		return (NULL);
	my_bzero(tab, count * size);
	return (tab);
}

char	*my_substr(char *s, unsigned int start, size_t len, int a)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > my_strlen(s))
		return (my_calloc(1, 1));
	if (my_strlen(s + start) < len)
		len = my_strlen(s + start);
	if ((str = (char*)malloc((len + 1) * sizeof(char))) == NULL)
		return (my_calloc(1, 1));
	len += start;
	while (start < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	if (a)
		free(s);
	return (str);
}

int		helper(char **line, char **save)
{
	*line = my_substr(*save, 0, my_strlen(*save), 1);
	*save = NULL;
	return (0);
}

char	*my_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = my_strlen(s1) + my_strlen(s2) + 1;
	if ((str = (char*)malloc(i * sizeof(char))) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
	{
		str[j] = s1[j];
		j++;
	}
	while (s2[i])
	{
		str[j] = s2[i];
		j++;
		i++;
	}
	str[j] = '\0';
	free(s1);
	return (str);
}
