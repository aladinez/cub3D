/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:15:23 by aez-zaou          #+#    #+#             */
/*   Updated: 2020/11/09 18:17:47 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	ft_bzero(void *s, size_t n)
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
