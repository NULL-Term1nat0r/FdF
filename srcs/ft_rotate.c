/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:21:08 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/16 01:16:22 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void ft_cx(t_stack *stack)
{
	int cx;

	cx = abs(stack->tmp_x[stack->rows - 1][0] - stack->tmp_x[0][stack->coloums - 1]);
	stack->c_x = cx;
}

void  ft_cy(t_stack *stack)
{
	int cy;

	cy = abs(stack->tmp_y[0][0] - stack->tmp_y[stack->rows - 1][stack->coloums - 1]);
	stack->c_y = cy;
}

void ft_rotate(t_stack *stack)
{
	int i;
	int j;
	double c;
	double s;
	double angle;
	// int delta_x;
	// int rotate_factor;

	i = 0;
	angle = stack->angle * 3.14 / 180;
	s = sin(angle);
	c = cos(angle);

	while (i < stack->rows)
	{
		j = 0;
		while (j < stack->coloums)
		{
			stack->tmp_x[i][j] = (stack->tmp_x[i][j] - stack->c_x) * c - (stack->tmp_y[i][j] - stack->c_y) * s + stack->c_x;
			stack->tmp_y[i][j] = (stack->tmp_x[i][j] - stack->c_x) * s + (stack->tmp_y[i][j] - stack->c_y) * c + stack->c_y;
			j++;
		}
		i++;
	}
}
// int main()
// {
//     double x, y, width, height;


//     double cx = x + width / 2;
//     double cy = y + height / 2;

//     // Rotate the rectangle by 30 degrees counterclockwise
//     double angle = 30 * PI / 180;
//     double s = sin(angle);
//     double c = cos(angle);

//     double new_x = (x - cx) * c - (y - cy) * s + cx;
//     double new_y = (x - cx) * s + (y - cy) * c + cy;

//     return 0;
// }
