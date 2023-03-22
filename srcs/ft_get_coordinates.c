/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_coordinates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 02:26:42 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/22 04:34:04 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double ft_cos(int angle)
{
	double rad_angle;
	double c;

	rad_angle = angle * 3.14 / 180;
	c = cos(rad_angle);
	return (c);
}

double ft_sin(int angle)
{
	double rad_angle;
	double c;

	rad_angle = angle * 3.14 / 180;
	c = sin(rad_angle);
	return (c);
}

void ft_move_object(t_stack *stack, int i, int j)
{
	stack->tmp_x[i][j] = stack->tmp_x[i][j] + stack->move_x;
	stack->tmp_y[i][j] = stack->tmp_y[i][j] + stack->move_y;
}

void ft_move_center(t_stack *stack, int i, int j, int mode)
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

void ft_middle_coordinate(t_stack *stack)
{
	stack->c_x = (stack->data_x[0][stack->coloums - 1] * stack->factor_x + stack->data_x[stack->rows - 1][0] * stack->factor_x)/2;
	stack->c_y = (stack->data_y[0][stack->coloums - 1] * stack->factor_x + stack->data_y[stack->rows - 1][0] * stack->factor_x)/2;
	stack->wc_x = stack->s_x - (stack->data_x[0][stack->coloums - 1] * stack->factor_x + stack->data_x[stack->rows - 1][0] * stack->factor_x)/2;
	stack->wc_y = stack->s_y - (stack->data_y[0][stack->coloums - 1] * stack->factor_x + stack->data_y[stack->rows - 1][0] * stack->factor_x)/2;
}

void ft_rotate_x(t_stack *stack, int i, int j)
{
	int tmp_y;

	tmp_y = stack->tmp_y[i][j];
	stack->tmp_y[i][j] = (ft_cos(stack->angle_x) * (stack->tmp_y[i][j] - stack->c_y) - ft_sin(stack->angle_x) * stack->tmp_z[i][j]) + stack->c_y;
	stack->tmp_z[i][j] = (ft_sin(stack->angle_x) * (tmp_y - stack->c_y) + ft_cos(stack->angle_x) * (stack->tmp_z[i][j]));
}
void ft_rotate_y(t_stack *stack, int i, int j)
{
	int tmp_x;

	tmp_x = stack->tmp_x[i][j];
	stack->tmp_x[i][j] = (ft_cos(stack->angle_y) * (stack->tmp_x[i][j] - stack->c_x) + ft_sin(stack->angle_y) * stack->tmp_z[i][j]) + stack->c_x;
	stack->tmp_z[i][j] = (ft_sin(stack->angle_y) * (-1 * (tmp_x - stack->c_x) + ft_cos(stack->angle_y) * stack->tmp_z[i][j]));
}
void ft_rotate_z(t_stack *stack, int i, int j)
{
	int tmp_x;

	tmp_x = stack->tmp_x[i][j];
	stack->tmp_x[i][j] = (stack->tmp_x[i][j] - stack->c_x) * ft_cos(stack->angle_z) + (stack->tmp_y[i][j] - stack->c_y) *(-1) * ft_sin(stack->angle_z) + stack->c_x;
	stack->tmp_y[i][j]= (tmp_x - stack->c_x) * ft_sin(stack->angle_z) + ((stack->tmp_y[i][j] - stack->c_y) * ft_cos(stack->angle_z)) + stack->c_y;
}

void ft_isometric(t_stack *stack, int i, int j, double angle)
{
	int tmp_x;

	tmp_x = stack->tmp_x[i][j];
	stack->tmp_x[i][j] = (stack->tmp_x[i][j] - stack->c_x) * ft_cos(angle) - (stack->tmp_y[i][j] - stack->c_y) * ft_sin(angle) + stack->c_x;
	stack->tmp_y[i][j]= (tmp_x - stack->c_y) * ft_sin(angle) + ((stack->tmp_y[i][j] - stack->c_y) * ft_cos(angle)) + stack->c_y;
	stack->tmp_y[i][j] = stack->tmp_y[i][j] - stack->tmp_z[i][j];
}
void ft_get_coordinates(t_stack *stack)
{
	int i;
	int j;

	i = 0;
	ft_middle_coordinate(stack);
	while (i < stack->rows)
	{
		j = 0;
		while (j < stack->coloums)
		{
			stack->tmp_x[i][j] = (stack->data_x[i][j] * stack->factor_x);
			stack->tmp_y[i][j] = stack->data_y[i][j] * stack->factor_x;
			stack->tmp_z[i][j] = stack->data_z[i][j] * stack->factor_z * stack->factor_x;
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
		i++;
	}
}


// void ft_get_coordinates(t_stack *stack)
// {
// 	int i;
// 	int j;
// 	int tmp_x;

// 	i = 0;
// 	ft_middle_coordinate(stack);
// 	while (i < stack->rows)
// 	{
// 		j = 0;
// 		while (j < stack->coloums)
// 		{
// 			stack->tmp_x[i][j] = stack->data_x[i][j] * stack->factor_x;
// 			stack->tmp_y[i][j] = stack->data_y[i][j] * stack->factor_x;
// 			stack->tmp_z[i][j] = stack->data_z[i][j] * stack->factor_z;
// 			stack->tmp_x[i][j] = stack->tmp_x[i][j];
// 			stack->tmp_y[i][j] = stack->tmp_y[i][j];
// 			tmp_x = stack->tmp_x[i][j];
// 			stack->tmp_x[i][j] = (stack->tmp_x[i][j] - stack->c_x) * ft_cos(stack->angle) - (stack->tmp_y[i][j] - stack->c_y) * ft_sin(stack->angle) + stack->c_x  + stack->wc_x;
// 			stack->tmp_y[i][j]= (tmp_x - stack->c_x) * ft_sin(stack->angle) + ((stack->tmp_y[i][j] - stack->c_y) * ft_cos(stack->angle)) + stack->c_y  + stack->wc_x;
// 			stack->tmp_y[i][j] = stack->tmp_y[i][j] - stack->tmp_z[i][j];
// 			j++;
// 		}
// 		i++;
// 	}
// }
