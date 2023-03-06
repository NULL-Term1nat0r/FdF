/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:30:15 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/06 02:09:14 by estruckm         ###   ########.fr       */
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
		window->color = COLOR_BLUE;
	return 0;
}
