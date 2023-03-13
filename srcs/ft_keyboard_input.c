/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:30:15 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/13 01:58:23 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void ft_change_image(t_stack *stack, int color)
{
	stack->color = color;
	ft_reset_image(stack);
	ft_draw(stack);
	mlx_put_image_to_window(stack->mlx, stack->win, stack->img_ptr, 0, 0);
}

int ft_keyboard_input(int keycode, t_stack *stack)
{
	if (keycode == KEYBOARD_ESC)
	{
		mlx_clear_window(stack->mlx, stack->win);
		exit(0);
	}
	if (keycode == KEYBOARD_B)
		ft_change_image(stack, COLOR_BLUE);
	if (keycode == KEYBOARD_C)
		ft_change_image(stack, COLOR_CYAN);
	// if (keycode == KEYBOARD_P)
	// 	ft_change_image(stack, COLOR_PURPLE);
	if (keycode == KEYBOARD_G)
		ft_change_image(stack, COLOR_GREEN);
	if (keycode == KEYBOARD_PLUS)
	{
		stack->factor_z = stack->factor_z + 1;
		ft_reset_image(stack);
		ft_draw(stack);
		mlx_put_image_to_window(stack->mlx, stack->win, stack->img_ptr, 0, 0);
	}
		if (keycode == KEYBOARD_H)
	{
		stack->factor_z = stack->factor_z + 1;
		ft_reset_image(stack);
		ft_draw(stack);
		mlx_put_image_to_window(stack->mlx, stack->win, stack->img_ptr, 0, 0);
	}
		if (keycode == KEYBOARD_R)
	{
		stack->factor_x = stack->factor_x + 1;
		ft_reset_image(stack);
		ft_draw(stack);
		mlx_put_image_to_window(stack->mlx, stack->win, stack->img_ptr, 0, 0);
	}
	// 	if (keycode == KEYBOARD_R)
	// {
	// 	stack->factor_x = stack->factor_x + 1;
	// 	ft_reset_image(stack);
	// 	ft_draw(stack);
	// 	mlx_put_image_to_window(stack->mlx, stack->win, stack->img_ptr, 0, 0);
	// }
		if (keycode == KEYBOARD_P)
	{
		// stack->angle = stack->angle + 1;
		ft_reset_image(stack);
		stack->angle += 2;
		ft_draw(stack);
		mlx_put_image_to_window(stack->mlx, stack->win, stack->img_ptr, 0, 0);
	}
	return 0;
}
