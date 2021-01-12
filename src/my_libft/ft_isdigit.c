/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:34:09 by aez-zaou          #+#    #+#             */
/*   Updated: 2020/11/09 19:14:32 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57) || c == ' ')
		return (1);
	else
		return (0);
}
