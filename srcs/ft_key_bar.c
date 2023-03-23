/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_bar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 02:17:03 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/23 13:11:13 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	display_control_1(t_stack *stack)
{
	mlx_string_put(stack->mlx, stack->win, 5, 25, COLOR_WHITE,
		"Color_change: C + color value");
	mlx_string_put(stack->mlx, stack->win, 5, 45, COLOR_WHITE,
		"Color value R: 1 = Increase R 2 = Decrease");
	mlx_string_put(stack->mlx, stack->win, 5, 65, COLOR_WHITE,
		"Color value G: 3 = Increase R 4 = Decrease");
	mlx_string_put(stack->mlx, stack->win, 5, 85, COLOR_WHITE,
		"Color value B: 5 = Increase R 6 = Decrease");
	mlx_string_put(stack->mlx, stack->win, 5, 105, COLOR_WHITE,
		"________________________________________");
	mlx_string_put(stack->mlx, stack->win, 5, 125, COLOR_WHITE,
		"Angle_chance: ");
	mlx_string_put(stack->mlx, stack->win, 5, 145, COLOR_WHITE,
		"Angle_x: W = increase | S = decrease");
	mlx_string_put(stack->mlx, stack->win, 5, 165, COLOR_WHITE,
		"Angle_y: A = increase | D = decrease");
	mlx_string_put(stack->mlx, stack->win, 5, 185, COLOR_WHITE,
		"Angle_z: F = increase | G = decrease");
	mlx_string_put(stack->mlx, stack->win, 5, 205, COLOR_WHITE,
		"________________________________________");
	mlx_string_put(stack->mlx, stack->win, 5, 225, COLOR_WHITE,
		"Z_coordinate_change");
	mlx_string_put(stack->mlx, stack->win, 5, 245, COLOR_WHITE,
		"H = increase | J = decrease");
}

void	display_control_2(t_stack *stack)
{
	mlx_string_put(stack->mlx, stack->win, 5, 265, COLOR_WHITE,
		"________________________________________");
	mlx_string_put(stack->mlx, stack->win, 5, 285, COLOR_WHITE,
		"Move object: ");
	mlx_string_put(stack->mlx, stack->win, 5, 305, COLOR_WHITE,
		"Move up/down/left/right = arrow keys");
	mlx_string_put(stack->mlx, stack->win, 5, 325, COLOR_WHITE,
		"________________________________________");
	mlx_string_put(stack->mlx, stack->win, 5, 345, COLOR_WHITE,
		"Zoom_change: ");
	mlx_string_put(stack->mlx, stack->win, 5, 365, COLOR_WHITE,
		"Z = increase | U = decrease");
	mlx_string_put(stack->mlx, stack->win, 5, 385, COLOR_WHITE,
		"________________________________________");
	mlx_string_put(stack->mlx, stack->win, 5, 405, COLOR_WHITE,
		"Spinning_loop: ");
	mlx_string_put(stack->mlx, stack->win, 5, 425, COLOR_WHITE,
		"Space = deactivate| B = activate");
	mlx_string_put(stack->mlx, stack->win, 5, 445, COLOR_WHITE,
		"________________________________________");
	mlx_string_put(stack->mlx, stack->win, 5, 465, COLOR_WHITE,
		"Activate isometric mode: 7 = activate/deactivate");
	mlx_string_put(stack->mlx, stack->win, 5, 485, COLOR_WHITE,
		"________________________________________");
}

void	display_control_3(t_stack *stack, char *s)
{
	mlx_string_put(stack->mlx, stack->win, 5, 505, COLOR_WHITE,
		"Current values: ");
	mlx_string_put(stack->mlx, stack->win, 5, 525, COLOR_WHITE,
		(ft_create_int_string((stack->color_r), "Color_value_r: ", s)));
	mlx_string_put(stack->mlx, stack->win, 5, 545, COLOR_WHITE,
		(ft_create_int_string((stack->color_g), "Color_value_g: ", s)));
	mlx_string_put(stack->mlx, stack->win, 5, 565, COLOR_WHITE,
		(ft_create_int_string((stack->color_b), "Color_value_b: ", s)));
	mlx_string_put(stack->mlx, stack->win, 5, 585, COLOR_WHITE,
		(ft_create_int_string((stack->color_a), "Color_value_a: ", s)));
	mlx_string_put(stack->mlx, stack->win, 5, 605, COLOR_WHITE,
		(ft_create_int_string((stack->angle_x), "Angle_x: ", s)));
	mlx_string_put(stack->mlx, stack->win, 5, 625, COLOR_WHITE,
		(ft_create_int_string((stack->angle_y), "Angle_y: ", s)));
	mlx_string_put(stack->mlx, stack->win, 5, 645, COLOR_WHITE,
		(ft_create_int_string((stack->angle_z), "Angle_z: ", s)));
	mlx_string_put(stack->mlx, stack->win, 5, 665, COLOR_WHITE,
		(ft_create_int_string((stack->move_x), "Move-factor_x: ", s)));
	mlx_string_put(stack->mlx, stack->win, 5, 685, COLOR_WHITE,
		(ft_create_int_string((stack->move_y), "Move-factor_y: ", s)));
	mlx_string_put(stack->mlx, stack->win, 5, 705, COLOR_WHITE,
		(ft_create_int_string((stack->factor_x), "Zoom_factor_x: ", s)));
	mlx_string_put(stack->mlx, stack->win, 5, 725, COLOR_WHITE,
		(ft_create_int_string((stack->factor_z), "Factor_z: ", s)));
}

void	display_control(t_stack *stack)
{
	char	s[26];

	display_control_1(stack);
	display_control_2(stack);
	display_control_3(stack, s);
}
