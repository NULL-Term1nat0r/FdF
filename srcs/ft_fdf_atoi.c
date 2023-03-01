/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 02:43:02 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/01 01:39:01 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_fdf_atoi(char *argv)
{
	int				sign;
	long	ret;

	ret = 0;
	sign = 1;
	while (*argv == 32 || (*argv >= 9 && *argv <= 13))
		argv++;
	if (*argv == 45)
		sign = -1;
	if (*argv == 45 || *argv == 43)
		argv++;
	while (*argv >= 48 && *argv <= 57 )
	{
		ret = (ret * 10) + (*argv++ - 48);
	}
	return ((int)ret * sign);
}
