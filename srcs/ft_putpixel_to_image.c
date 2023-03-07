/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpixel_to_image.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:51:16 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/07 04:44:48 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int *ft_putpixel_to_image(t_initialise_window *window, int x, int y)
{
	char *index;

	index = window->data_ptr + (y * window->size_line + x * window->bpp / 8);
	*(int *)index = window->color;
	printf("testcolor: %d\n", window->color);
	return ((int *) index);
}


// int	*ft_put(t_fdf *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->ll + x * (data->bp / 8));
// 	*(int *)dst = color;
// 	return ((int *) dst);
// }


// void ft_putpixel_to_image(t_initialise_window *window, int x, int y)
// {
// 	int bpp;
//     char *index;

// 	bpp = 32 / 8;
// 	index = (y * window->size_line) + (x * bpp);
// 	*(int *)(window->data_ptr + index) = COLOR_RED;
// }
