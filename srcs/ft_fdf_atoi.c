/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 02:43:02 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/22 20:46:21 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_rgb_to_color(int a, int r, int g, int b)
{
	int	color;

	color = (a << 24) | (r << 16) | (g << 8) | b;
	return (color);
}

static void	hex_to_color(char str, int *color)
{
	int	digit;

	digit = 0;
	if (str >= '0' && str <= '9')
		digit = str - '0';
	else if (str >= 'a' && str <= 'f')
		digit = str - 'a' + 10;
	else if (str >= 'A' && str <= 'F')
		digit = str - 'A' + 10;
	*color = (*color << 4) | digit;
}

int	ft_hex_to_color(t_stack *stack, const char *str)
{
	int		color;
	void	*test;

	test = stack;
	color = 0;
	while (*str != ',' && *str != '\0')
		str++;
	if (*str == ',')
	{
		str += 3;
		while (*str)
		{
			hex_to_color(*str, &color);
			str++;
		}
	}
	if (color == 0)
	{
		color = ft_rgb_to_color(stack->color_a, stack->color_r,
				stack->color_g, stack->color_b);
		return (color);
	}
	return (color);
}

int	ft_fdf_atoi(char *argv)
{
	int		sign;
	long	ret;

	ret = 0;
	sign = 1;
	while (*argv == 32 || (*argv >= 9 && *argv <= 13))
		argv++;
	if (*argv == 45)
		sign = -1;
	if (*argv == 45 || *argv == 43)
		argv++;
	while (*argv >= 48 && *argv <= 57)
	{
		ret = (ret * 10) + (*argv++ - 48);
	}
	return ((int)ret * sign);
}
