/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 02:43:02 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/21 18:18:44 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int ft_rgbToColor(int r, int g, int b)
{
	int color = ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF);
	return (color);
}

int	ft_hex_to_color(t_stack *stack, const char *str)
{
	int	color;
	int	digit;
	void *test;

	test = stack;


 	color = 0;
	while (*str != ',' && *str != '\0')
		str++;
	if (*str == ',')
	{
		str += 3;
		while (*str)
		{
			if (*str >= '0' && *str <= '9')
				digit = *str - '0';
			else if (*str >= 'a' && *str <= 'f')
				digit = *str - 'a' + 10;
			else if (*str >= 'A' && *str <= 'F')
				digit = *str - 'A' + 10;
			color = (color << 4) | digit;
			str++;
		}
	}
	if (color == 0)
	{
		color = stack->color_b;
		return (ft_rgbToColor(255, 0, 0));
	}
 	return (color);
}

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
