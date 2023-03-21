/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 00:12:47 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/21 18:16:47 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int ft_hex_to_int(char *hex)
{
	int digit_value;
	int base = 1; // 16^0
	int decimal = 0;
	int i = 1;
	while (i >= 0)
	{
		if (hex[i] >= '0' && hex[i] <= '9')
			digit_value = hex[i] - '0'; // convert digit from char to int
		if (hex[i] >= 'A' && hex[i] <= 'F')
			digit_value = hex[i] - 'A' + 10; // convert digit from char to int
		decimal += digit_value * base;
		base *= 16;
		i--;
	}
	return decimal;
}

int ft_get_color(char *argv)
{
	int red;
	int green;
	int blue;
	int alpha;

	while (*argv == 32 || (*argv >= 9 && *argv <= 13))
		argv++;
	// if (*argv == 44 && *(argv + 1) == 48 && *(argv + 2) == 120)
	argv += 1;
	if (*argv == 44)
	{
		argv += 3;
		alpha = 255;
		printf("string: %s", argv);
		red = ft_hex_to_int(argv);
		printf("red: %d\n", red);
		argv += 2;
		printf("string: %s", argv);
		green = ft_hex_to_int(argv);
		printf("green: %d\n", green);
		argv += 2;
		printf("string: %s", argv);
		blue = ft_hex_to_int(argv);
		printf("blue: %d\n", blue);
		return ((alpha <<24) | (red << 16) | (green << 8) | blue);
	}
	else
		return (0xFF0000);
}
// unsigned long createRGBA(int r, int g, int b, int a)
// {
//     return ((r & 0xff) << 24) + ((g & 0xff) << 16) + ((b & 0xff) << 8)
//            + (a & 0xff);
// }



// int ft_get_color(int red, int green, int blue, int alpha)
// {
// 	int color;

// 	color = (alpha <<24) | (red << 16) | (green << 8) | blue;
// 	return (color);
// }
