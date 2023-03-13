/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:19:34 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/13 00:54:18 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void ft_draw_line_horizontal(t_stack *stack)
{
	double deltaX;
	double deltaY;
	double pixelX;
	double pixelY;
	int pixels;
	int i;
	int j;

	i = 0;
	while (i < stack->rows)
	{
		j = 0;
		while (j < stack->coloums - 1)
		{
			pixelX = stack->tmp_x[i][j];
			pixelY = stack->tmp_y[i][j];

			deltaX = stack->tmp_x[i][j + 1] - stack->tmp_x[i][j];
			// deltaX = endX - beginX;
			deltaY = stack->tmp_y[i][j + 1] - stack->tmp_y[i][j];
			// deltaY = endY - beginY;
			pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
			deltaX /= pixels; // 1
 			deltaY /= pixels; // 0
			while (pixels)
			{
				// ft_putpixel_to_image(stack, pixelX, pixelY);
				// mlx_pixel_put(stack->mlx, stack->win, pixelX, pixelY, 0xFF0000);
				if (pixelX < stack->stack_width && pixelY < stack->stack_height)
					ft_putpixel_to_image(stack, pixelX, pixelY, stack->color);
				pixelX += deltaX;
				pixelY += deltaY;
				--pixels;
			}
			j++;
		}
		i++;
	}
}

void ft_draw_line_vertical(t_stack *stack)
{
	double deltaX;
	double deltaY;
	double pixelX;
	double pixelY;
	int pixels;
	int i;
	int j;

	i = 0;
	while (i < stack->coloums)
	{
		j = 0;
		while (j < stack->rows - 1)
		{
			pixelX = stack->tmp_x[j][i];
			pixelY = stack->tmp_y[j][i];

			deltaX = stack->tmp_x[j + 1][i] - stack->tmp_x[j][i];
			// deltaX = endX - beginX;
			deltaY = stack->tmp_y[j + 1][i] - stack->tmp_y[j][i];
			// deltaY = endY - beginY;
			pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
			deltaX /= pixels; // 1
 			deltaY /= pixels; // 0
			while (pixels)
			{
				// mlx_pixel_put(stack->mlx, stack->win, pixelX, pixelY, 0xFF0000);
				//ft_putpixel_to_image(stack, pixelX, pixelY);
				if (pixelX < stack->stack_width && pixelY < stack->stack_height)
					ft_putpixel_to_image(stack, pixelX, pixelY, stack->color);
				pixelX += deltaX;
				pixelY += deltaY;
				--pixels;
			}
			j++;
		}
		i++;
	}
}

void ft_draw(t_stack *stack)
{
	ft_get_coordinates(stack);
	ft_draw_line_horizontal(stack);
	ft_draw_line_vertical(stack);
}
