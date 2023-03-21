/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:30:15 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/21 18:49:40 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void ft_change_int_image(t_stack *stack, int *variable, int value)
{
	*variable  += value;
	ft_reset_image(stack);
	ft_draw(stack);
	mlx_put_image_to_window(stack->mlx, stack->win, stack->img_ptr, 0, 0);
	display_control(stack);
}

void ft_change_double_image(t_stack *stack, double *variable, double value)
{
	*variable  += value;
	ft_reset_image(stack);
	ft_draw(stack);
	mlx_put_image_to_window(stack->mlx, stack->win, stack->img_ptr, 0, 0);
	display_control(stack);
}

int ft_keyboard_input(int keycode, t_stack *stack)
{
	if (keycode == KEYBOARD_ESC)
	{
		mlx_clear_window(stack->mlx, stack->win);
		exit(0);
	}
		if (keycode == KEYBOARD_RightArrow)
			ft_change_int_image(stack, &(stack->move_x), 20);
		if (keycode == KEYBOARD_LeftArrow)
			ft_change_int_image(stack, &(stack->move_x), -20);
		if (keycode == KEYBOARD_UpArrow)
			ft_change_int_image(stack, &(stack->move_y), -20);
		if (keycode == KEYBOARD_DownArrow)
			ft_change_int_image(stack, &(stack->move_y), 20);
		if (keycode == KEYBOARD_W)
			ft_change_double_image(stack, &(stack->angle_x), 2);
		if (keycode == KEYBOARD_S)
			ft_change_double_image(stack, &(stack->angle_x), -2);
		if (keycode == KEYBOARD_A)
			ft_change_double_image(stack, &(stack->angle_y), 2);
		if (keycode == KEYBOARD_D)
			ft_change_double_image(stack, &(stack->angle_y), -2);
		if (keycode == KEYBOARD_F)
			ft_change_double_image(stack, &(stack->angle_z), 2);
		if (keycode == KEYBOARD_G)
			ft_change_double_image(stack, &(stack->angle_z), -2);

		if (keycode == KEYBOARD_Y)
			ft_change_int_image(stack, &(stack->factor_x), 1);
		if (keycode == KEYBOARD_U)
			ft_change_int_image(stack, &(stack->factor_x), -1);

		if (keycode == KEYBOARD_H)
			ft_change_double_image(stack, &(stack->factor_z), 0.2);
		if (keycode == KEYBOARD_J)
			ft_change_double_image(stack, &(stack->factor_z), -0.2);

		if (keycode == KEYBOARD_Space)
			stack->draw_loop = 1;
		if (keycode == KEYBOARD_B)
			stack->draw_loop = 0;
	return 0;
}
