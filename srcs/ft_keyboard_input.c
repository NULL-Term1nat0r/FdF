/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:30:15 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/07 05:25:06 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int ft_keyboard_input(int keycode, t_initialise_window *window)
{
	if (keycode == KEYBOARD_ESC)
	{
		mlx_clear_window(window->mlx, window->win);
		exit(0);
	}
	if (keycode == KEYBOARD_B)
	{
		window->color = COLOR_BLUE;
		// mlx_destroy_image(window->mlx, window->img_ptr);
		// window->img_ptr =mlx_new_image(window->mlx, window->window_width, window->window_height);
		ft_draw(window->t_point, window);
		// ft_putpixel_to_image(window, 500, 500);
		// ft_putpixel_to_image(window, 500, 502);
		mlx_put_image_to_window(window->mlx, window->win, window->img_ptr, 0, 0);
		printf("test end\n");
	}
	return 0;
}
