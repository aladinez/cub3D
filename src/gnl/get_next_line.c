/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:14:51 by aez-zaou          #+#    #+#             */
/*   Updated: 2020/11/09 18:17:22 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int		check(char *buf)
{
	int i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		f_u_moul(char **save, char **line, int fd, char **buf)
{
	int ret;

	if (fd < 0 || !line || ((*save == NULL) && !(*save = my_calloc(1, 1))))
		return (-1);
	if ((ret = check(*save)) >= 0)
	{
		(*line) = my_substr(*save, 0, ret, 0);
		*save = my_substr(*save, ret + 1, my_strlen(*save) - ret, 1);
		return (1);
	}
	if (!(*buf = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	return (0);
}

size_t	my_strlen(const char *tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int		get_next_line(int fd, char **line)
{
	static char *save;
	char		*buf;
	int			i;

	if ((i = f_u_moul(&save, line, fd, &buf)))
		return (i);
	while ((i = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		buf[i] = 0;
		save = my_strjoin(save, buf);
		if ((i = check(save)) >= 0)
		{
			(*line) = my_substr(save, 0, i, 0);
			(save) = my_substr((save), i + 1, my_strlen((save)) - i, 1);
			free(buf);
			return (1);
		}
		if (*buf == '\0')
		{
			free(buf);
			return (helper(line, &save));
		}
	}
	free(buf);
	return (i);
}
