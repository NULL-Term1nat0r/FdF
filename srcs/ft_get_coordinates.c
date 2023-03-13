/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_coordinates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 02:26:42 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/13 00:13:38 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void ft_move_center(t_stack *stack)
{
	int c_x_object;
	int c_y_object;
	int i;
	int j;

	i = 0;
	j = 0;

	c_x_object = (stack->tmp_x[0][stack->coloums - 1] - stack->tmp_x[0][0]) /2;
	c_y_object = (stack->tmp_y[stack->rows - 1 ][0] - stack->tmp_y[0][0]) /2;
	stack->c_x = stack->s_x - c_x_object;
	stack->c_y = stack->s_x - c_x_object;

	while (i < stack->coloums)
	{
		j = 0;
		while (j < stack->rows)
		{
			stack->tmp_x[i][j] = stack->tmp_x[i][j] + stack->c_x;
			stack->tmp_y[i][j] = stack->tmp_y[i][j] + stack->c_y;
			j++;
		}
		i++;
	}
}

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

void ft_middle_coordinate(t_stack *stack)
{
	stack->c_x = (stack->data_x[0][stack->coloums - 1] * stack->factor_x + stack->data_x[stack->rows - 1][0] * stack->factor_x)/2;
	stack->c_y = (stack->data_y[0][stack->coloums - 1] * stack->factor_x + stack->data_y[stack->rows - 1][0] * stack->factor_x)/2;
	stack->wc_x = stack->s_x - (stack->data_x[0][stack->coloums - 1] * stack->factor_x + stack->data_x[stack->rows - 1][0] * stack->factor_x)/2;
	stack->wc_y = stack->s_x - (stack->data_x[0][stack->coloums - 1] * stack->factor_x + stack->data_x[stack->rows - 1][0] * stack->factor_x)/2;
}
void ft_get_coordinates(t_stack *stack)
{
	int i;
	int j;
	int tmp_x;

	// stack->c_x = stack->s_x - (stack->data_x[0][stack->coloums - 1] * stack->factor_x)/2;
	// stack->c_y = stack->s_y - (stack->data_y[stack->rows - 1][stack->coloums - 1] * stack->factor_x)/2;

	i = 0;
	ft_middle_coordinate(stack);
	while (i < stack->rows)
	{
		j = 0;

		while (j < stack->coloums)
		{
			stack->tmp_x[i][j] = stack->data_x[i][j] * stack->factor_x;
			stack->tmp_y[i][j] = stack->data_y[i][j] * stack->factor_x;

			stack->tmp_x[i][j] = stack->tmp_x[i][j];
			stack->tmp_y[i][j] = stack->tmp_y[i][j];

			tmp_x = stack->tmp_x[i][j];

			// stack->tmp_x[i][j] = ft_cos(stack->angle) * (stack->tmp_x[i][j] - stack->c_x) - ft_sin(stack->angle) * (stack->tmp_y[i][j] - stack->c_y) + stack->tmp_x[i][j];
			// stack->tmp_y[i][j] = ft_sin(stack->angle) * (tmp_x - stack->c_x) + ft_cos(stack->angle) * (stack->tmp_y[i][j] - stack->c_y) + stack->tmp_x[i][j];

			stack->tmp_x[i][j] = (stack->tmp_x[i][j] - stack->c_x) * ft_cos(stack->angle) - (stack->tmp_y[i][j] - stack->c_y - stack->data_z[i][j] * stack->factor_z) * ft_sin(stack->angle) + stack->c_x  + stack->wc_x;
			stack->tmp_y[i][j]= (tmp_x - stack->c_x) * ft_sin(stack->angle) + ((stack->tmp_y[i][j] - stack->c_y - (stack->data_z[i][j] * stack->factor_z)) * ft_cos(stack->angle)) + stack->c_y  + stack->wc_x;

			j++;
		}
		i++;
	}
	printf("test c_x: %d\n", stack->c_x);
	printf("test c_y: %d\n", stack->c_y);
}

// void ft_get_coordinates(t_stack *stack)
// {
// 	int i;
// 	int j;
// 	int x_2;
// 	float y_2;
// 	printf("rows before get coordinates: %d\n", stack->rows);
// 	x_2 = stack->s_x;
// 	y_2 = stack->s_y;
// 	printf("%p\n", stack->data_z);
// 	printf("%p\n", stack);
// 	i = 0;
// 	while (i < stack->rows)
// 	{
// 		// printf("test%d\n", i);
// 		j = 0;
// 		// x_2 -= i * 10;
// 		// y_2 -= i * 5.77 * stack->coloums;
// 		while (j < stack->coloums)
// 		{
// 			//fprintf(stderr, "i: %d j: %d\n", i, j);
// 			stack->tmp_x[i][j] = (stack->data_x[i][j] * stack->factor_x) + x_2;
// 			stack->tmp_y[i][j] = 0.6 * stack->factor_x * j - (stack->data_z[i][j] * stack->factor_z) + y_2;
// 			// x -= 9.9;
// 			// y -= 10;
// 			// printf("%d ", ft_fdf_atoi(s_array[j]));
// 			j++;
// 		}
// 		// x -= ((stack->coloums + 1) * 10);
// 		// y -= ((stack->coloums - 1) * 10);
// 		i++;
// 		x_2 -= 10;
// 		y_2 += 6;
// 	}
// }
