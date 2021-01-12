/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:49:45 by aez-zaou          #+#    #+#             */
/*   Updated: 2020/11/09 18:18:07 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

static int	skip(const char *ss, char c, int i)
{
	while (ss[i] == c)
		i++;
	return (i);
}

static void	fill2(const char *s1, char **str1, char c, int a)
{
	int i;
	int j;
	int dim2;

	i = 0;
	j = 0;
	while (a--)
	{
		dim2 = 0;
		j = skip(s1, c, j);
		while (s1[j])
		{
			if (s1[j] != c)
			{
				str1[i][dim2] = s1[j];
				j++;
				dim2++;
			}
			else
			{
				i++;
				break ;
			}
		}
	}
}

static char	**ft_free(char **str)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
	str = NULL;
	return (str);
}

static char	**allo_fill(char **str, const char *s, char c, int dim1)
{
	int i;
	int dim2;
	int j;

	i = 0;
	j = -1;
	while (++j < dim1)
	{
		dim2 = 1;
		i = skip(s, c, i);
		while (s[i] && s[i] != c)
		{
			dim2++;
			i++;
		}
		if ((str[j] = (char*)malloc(dim2 * sizeof(char))) == NULL)
			return (ft_free(str));
		str[j][dim2 - 1] = '\0';
	}
	str[j] = NULL;
	fill2(s, str, c, j);
	return (str);
}

char		**ft_split(char const *s, char c)
{
	char	**str;
	int		dim1;
	int		i;

	dim1 = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (s[i] && s[i] != c)
		{
			dim1++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	if ((str = (char**)malloc((dim1 + 1) * sizeof(char*))) == NULL)
		return (NULL);
	str = allo_fill(str, s, c, dim1);
	return (str);
}
