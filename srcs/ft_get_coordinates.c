/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_coordinates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 02:26:42 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/23 10:07:48 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_move_object(t_stack *stack, int i, int j)
{
	stack->tmp_x[i][j] = stack->tmp_x[i][j] + stack->move_x;
	stack->tmp_y[i][j] = stack->tmp_y[i][j] + stack->move_y;
}

void	ft_isometric(t_stack *stack, int i, int j, double angle)
{
	int	tmp_x;

	tmp_x = stack->tmp_x[i][j];
	stack->tmp_x[i][j] = (stack->tmp_x[i][j] - stack->c_x)
		* ft_cos(angle) - (stack->tmp_y[i][j] - stack->c_y)
		* ft_sin(angle) + stack->c_x;
	stack->tmp_y[i][j] = (tmp_x - stack->c_y) * ft_sin(angle)
		+ ((stack->tmp_y[i][j] - stack->c_y) * ft_cos(angle)) + stack->c_y;
		stack->tmp_y[i][j] = stack->tmp_y[i][j] - stack->tmp_z[i][j];
}

void	ft_get_coordinates_core(t_stack *stack, int i, int j)
{
	while (j < stack->coloums)
	{
		stack->tmp_x[i][j] = (stack->data_x[i][j] * stack->factor_x);
		stack->tmp_y[i][j] = stack->data_y[i][j] * stack->factor_x;
		stack->tmp_z[i][j] = stack->data_z[i][j]
			* stack->factor_z * stack->factor_x;
		if ((stack->isometric_mode % 2) != 0)
			ft_isometric(stack, i, j, stack->angle_z);
		else
		{
			ft_rotate_x(stack, i, j);
			ft_rotate_y(stack, i, j);
			ft_rotate_z(stack, i, j);
		}
		ft_move_center(stack, i, j, 1);
		ft_move_object(stack, i, j);
		j++;
	}
}

void	ft_get_coordinates(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	ft_middle_coordinate(stack);
	while (i < stack->rows)
	{
		j = 0;
		ft_get_coordinates_core(stack, i, j);
		i++;
	}
}
