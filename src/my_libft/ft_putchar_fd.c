/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 18:38:39 by aez-zaou          #+#    #+#             */
/*   Updated: 2020/11/09 18:18:02 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	ft_putchar_fd(char c, int fd)
{
	if ((c < 0 || c > 127) || !fd)
		return ;
	write(fd, &c, 1);
}
