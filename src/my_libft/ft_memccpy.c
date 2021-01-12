/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:40:20 by aez-zaou          #+#    #+#             */
/*   Updated: 2020/11/09 18:17:58 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst2;
	unsigned char	*src2;
	unsigned int	i;
	unsigned char	c1;

	dst2 = (unsigned char*)dst;
	src2 = (unsigned char*)src;
	i = 0;
	c1 = (unsigned char)c;
	while (i < n)
	{
		dst2[i] = src2[i];
		if (src2[i] == c1)
			return ((unsigned char*)dst + i + 1);
		i++;
	}
	return (NULL);
}
