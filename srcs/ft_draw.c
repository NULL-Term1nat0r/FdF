/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:19:34 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/20 14:16:37 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void ft_draw_line_horizontal(t_stack *stack, int i, int j, int color)
{
	double delta_x;
	double delta_y;
	double pixel_x;
	double pixel_y;
	int pixels;

	pixel_x = stack->tmp_x[i][j];
	pixel_y = stack->tmp_y[i][j];
	delta_x = stack->tmp_x[i][j + 1] - stack->tmp_x[i][j];
	delta_y = stack->tmp_y[i][j + 1] - stack->tmp_y[i][j];
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels; // 1
 	delta_y /= pixels; // 0
	while (pixels)
	{
		ft_putpixel_to_image(stack, pixel_x, pixel_y, color);
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
}

void ft_draw_line_vertical(t_stack *stack, int i, int j, int color)
{
	double delta_x;
	double delta_y;
	double pixel_x;
	double pixel_y;
	int pixels;

	pixel_x = stack->tmp_x[j][i];
	pixel_y = stack->tmp_y[j][i];
	delta_x = stack->tmp_x[j + 1][i] - stack->tmp_x[j][i];
	delta_y = stack->tmp_y[j + 1][i] - stack->tmp_y[j][i];
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels; // 1
	delta_y /= pixels; // 0
	while (pixels)
	{
		ft_putpixel_to_image(stack, pixel_x, pixel_y, color);
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
}

void ft_draw_line_horizontal_main(t_stack *stack)
{
	int i;
	int j;

	i = 0;
	while (i < stack->rows)
	{
		j = 0;
		while (j < stack->coloums - 1)
		{
			ft_draw_line_horizontal(stack,i ,j, stack->data_color[i][j + 1]);
			j++;
		}
		i++;
	}
}

void ft_draw_line_vertical_main(t_stack *stack)
{
	int i;
	int j;

	i = 0;
	while (i < stack->coloums)
	{
		j = 0;
		while (j < stack->rows - 1)
		{
			ft_draw_line_vertical(stack,i ,j, stack->data_color[j + 1][i]);
			j++;
		}
		i++;
	}
}

void ft_draw(t_stack *stack)
{
	ft_get_coordinates(stack);
	ft_draw_line_horizontal_main(stack);
	ft_draw_line_vertical_main(stack);
}
