/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:31:05 by aez-zaou          #+#    #+#             */
/*   Updated: 2020/11/09 18:18:11 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	int				res;

	i = 0;
	if ((!s1 && n == 0) || (!s2 && n == 0) || n == 0)
		return (0);
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			res = (unsigned char)s1[i] - (unsigned char)s2[i];
			return (res);
		}
		else
			i++;
	}
	if (i == n)
	{
		res = (unsigned char)s1[i - 1] - (unsigned char)s2[i - 1];
		return (res);
	}
	res = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (res);
}
