/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_coordinates_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:05:04 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/23 10:06:02 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_move_center(t_stack *stack, int i, int j, int mode)
{
	if (mode == 1)
	{
		stack->tmp_y[i][j] = stack->tmp_y[i][j] + stack->wc_y;
		stack->tmp_x[i][j] = stack->tmp_x[i][j] + stack->wc_x;
	}
	else
	{
		stack->tmp_y[i][j] = stack->tmp_y[i][j] - stack->wc_y;
		stack->tmp_x[i][j] = stack->tmp_x[i][j] - stack->wc_x;
	}
}

void	ft_middle_coordinate(t_stack *stack)
{
	stack->c_x = (stack->data_x[0][stack->coloums - 1] * stack->factor_x
			+ stack->data_x[stack->rows - 1][0] * stack->factor_x) / 2;
	stack->c_y = (stack->data_y[0][stack->coloums - 1] * stack->factor_x
			+ stack->data_y[stack->rows - 1][0] * stack->factor_x) / 2 ;
	stack->wc_x = stack->stack_width / 2 - stack->c_x;
	stack->wc_y = stack->stack_height / 2 - stack->c_y;
}

void	ft_rotate_x(t_stack *stack, int i, int j)
{
	int	tmp_y;

	tmp_y = stack->tmp_y[i][j];
	stack->tmp_y[i][j] = (ft_cos(stack->angle_x) * (stack->tmp_y[i][j]
				- stack->c_y) - ft_sin(stack->angle_x)
			* stack->tmp_z[i][j]) + stack->c_y;
	stack->tmp_z[i][j] = (ft_sin(stack->angle_x) * (tmp_y - stack->c_y)
			+ ft_cos(stack->angle_x) * (stack->tmp_z[i][j]));
}

void	ft_rotate_y(t_stack *stack, int i, int j)
{
	int	tmp_x;

	tmp_x = stack->tmp_x[i][j];
	stack->tmp_x[i][j] = (ft_cos(stack->angle_y) * (stack->tmp_x[i][j]
				- stack->c_x) + ft_sin(stack->angle_y)
			* stack->tmp_z[i][j]) + stack->c_x;
	stack->tmp_z[i][j] = (ft_sin(stack->angle_y) * (-1 * (tmp_x - stack->c_x)
				+ ft_cos(stack->angle_y) * stack->tmp_z[i][j]));
}

void	ft_rotate_z(t_stack *stack, int i, int j)
{
	int	tmp_x;

	tmp_x = stack->tmp_x[i][j];
	stack->tmp_x[i][j] = (stack->tmp_x[i][j] - stack->c_x)
		* ft_cos(stack->angle_z) + (stack->tmp_y[i][j] - stack->c_y)
		*(-1) * ft_sin(stack->angle_z) + stack->c_x;
	stack->tmp_y[i][j] = (tmp_x - stack->c_x) * ft_sin(stack->angle_z)
		+ ((stack->tmp_y[i][j] - stack->c_y)
			* ft_cos(stack->angle_z)) + stack->c_y;
}
