/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_coordinates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 02:26:42 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/09 03:45:29 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int ft_get_x(t_stack *stack, int i, int j, char type)
{
	int lenght;
	if (type == 'x')
		lenght = stack->tmp_x[i][j] - stack->s_x;
	if (type == 'y')
		lenght = stack->tmp_y[i][j] - stack->s_y;
	return (lenght);
}

int ft_cos(t_stack *stack)
{
	int angle;
	int c;

	angle = stack->angle * 3.14 / 180;
	c = cos(angle);
	return (c);
}

int ft_sin(t_stack *stack)
{
	int angle;
	int s;

	angle = stack->angle * 3.14 / 180;
	s = sin(angle);
	return (s);
}


void ft_get_coordinates(t_stack *stack)
{
	int i;
	int j;
	// int x_2;
	// int y_2;
	int x_q;
	int y_q;
	// x_2 = stack->s_x;
	// y_2 = stack->s_y;

	i = 0;
	// x_2 = stack->s_x - stack->coloums * stack->factor_x / 2;
	// y_2 = stack->s_y - stack->coloums * stack->factor_x / 2;
	while (i < stack->rows)
	{
		j = 0;

		while (j < stack->coloums)
		{
			stack->tmp_x[i][j] = stack->data_x[i][j] * stack->factor_x + (stack->s_x - (stack->coloums * stack->factor_x / 2));
			stack->tmp_y[i][j] = stack->data_y[i][j] * stack->factor_x - stack->data_z[i][j] + (stack->s_y - (stack->coloums * stack->factor_x / 2));
			printf("(%d|%d) ", stack->tmp_x[i][j], stack->tmp_y[i][j]);
			x_q = (stack->tmp_x[i][j] - stack->s_x) * ft_cos(stack) - (stack->tmp_y[i][j] - stack->s_y) * ft_sin(stack);
			y_q = (stack->tmp_x[i][j] - stack->s_y) * ft_sin(stack) + (stack->tmp_y[i][j] - stack->s_y) * ft_cos(stack);
			// printf("(%d|%d) ", x_q, y_q);
			stack->tmp_x[i][j] = stack->tmp_x[i][j]  - x_q;
			stack->tmp_y[i][j] = stack->tmp_y[i][j]  - y_q;
			j++;
		}
		printf("\n");
		i++;
	}
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
