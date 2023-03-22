/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_bar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 02:17:03 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/22 02:07:25 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char *ft_create_double_string(double *variable, char *description)
{
	char *value;
	char *output_string;

	value = ft_itoa(*variable);
	output_string = ft_strjoin(description, value);
	return (output_string);
}

char *ft_create_int_string(int *variable, char *description)
{
	char *value;
	char *output_string;

	value = ft_itoa(*variable);
	output_string = ft_strjoin(description, value);
	return (output_string);
}
void		display_control(t_stack *stack)
{
	char *str;
	str = ft_itoa(stack->angle_x);
	// mlx_string_put(stack->mlx, stack->win, 5, 25, COLOR_WHITE, ft_create_string(&(stack->angle_x), "Angle_x: "));
	mlx_string_put(stack->mlx, stack->win, 5, 5, COLOR_WHITE, "Color Change: C + Color value");
	mlx_string_put(stack->mlx, stack->win, 5, 25, COLOR_WHITE,"Color value R: 1 = Increase R 2 = Decrease");
	mlx_string_put(stack->mlx, stack->win, 5, 45, COLOR_WHITE,"Color value G: 3 = Increase R 4 = Decrease");
	mlx_string_put(stack->mlx, stack->win, 5, 65, COLOR_WHITE,"Color value B: 5 = Increase R 6 = Decrease");
	mlx_string_put(stack->mlx, stack->win, 5, 85, COLOR_WHITE,"Color value A: 7 = Increase R 8 = Decrease");
	mlx_string_put(stack->mlx, stack->win, 5, 105, COLOR_WHITE,"________________________________________");
	mlx_string_put(stack->mlx, stack->win, 5, 125, COLOR_WHITE,"Angle Chance: ");
	mlx_string_put(stack->mlx, stack->win, 5, 145, COLOR_WHITE,"Angle_x: W = Increase | S = Decrease");
	mlx_string_put(stack->mlx, stack->win, 5, 165, COLOR_WHITE,"Angle_y: A = Increase | D = Decrease");
	mlx_string_put(stack->mlx, stack->win, 5, 185, COLOR_WHITE,"Angle_z: F = Increase | G = Decrease");
	mlx_string_put(stack->mlx, stack->win, 5, 205, COLOR_WHITE,"________________________________________");
	mlx_string_put(stack->mlx, stack->win, 5, 225, COLOR_WHITE,"Zoom: ");
	mlx_string_put(stack->mlx, stack->win, 5, 245, COLOR_WHITE,"Zoom: Z = Increase | U = Decrease");
	mlx_string_put(stack->mlx, stack->win, 5, 265, COLOR_WHITE,"________________________________________");
	mlx_string_put(stack->mlx, stack->win, 5, 285, COLOR_WHITE,"Spinning Loop: ");
	mlx_string_put(stack->mlx, stack->win, 5, 305, COLOR_WHITE,"Zoom: Space = Deactivate| B = Activate");
	mlx_string_put(stack->mlx, stack->win, 5, 325, COLOR_WHITE,"________________________________________");
	mlx_string_put(stack->mlx, stack->win, 5, 345, COLOR_WHITE,"Current Values: ");
	mlx_string_put(stack->mlx, stack->win, 5, 365, COLOR_WHITE, ft_create_int_string(&(stack->color_r), "Color_value_r: "));
	mlx_string_put(stack->mlx, stack->win, 5, 385, COLOR_WHITE, ft_create_int_string(&(stack->color_g), "Color_value_g: "));
	mlx_string_put(stack->mlx, stack->win, 5, 405, COLOR_WHITE, ft_create_int_string(&(stack->color_b), "Color_value_b: "));
	mlx_string_put(stack->mlx, stack->win, 5, 425, COLOR_WHITE, ft_create_int_string(&(stack->color_a), "Color_value_a: "));
	mlx_string_put(stack->mlx, stack->win, 5, 445, COLOR_WHITE, ft_create_double_string(&(stack->angle_x), "Angle_x: "));
	mlx_string_put(stack->mlx, stack->win, 5, 465, COLOR_WHITE, ft_create_double_string(&(stack->angle_y), "Angle_y: "));
	mlx_string_put(stack->mlx, stack->win, 5, 485, COLOR_WHITE, ft_create_double_string(&(stack->angle_z), "Angle_z: "));
	mlx_string_put(stack->mlx, stack->win, 5, 505, COLOR_WHITE, ft_create_int_string(&(stack->factor_x), "Zoom_factor_x: "));
	mlx_string_put(stack->mlx, stack->win, 5, 525, COLOR_WHITE, ft_create_double_string(&(stack->factor_z), "Factor_z: "));
}
