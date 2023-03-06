/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:19:34 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/06 02:13:14 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void ft_draw_line_horizontal(t_point_lst *t_point, t_initialise_window *stack)
{
	double deltaX;
	double deltaY;
	double pixelX;
	double pixelY;
	int pixels;
	int i;
	int j;

	i = 0;
	while (i < t_point->rows)
	{
		j = 0;
		while (j < t_point->coloums - 1)
		{
			pixelX = t_point->data_x[i][j];
			pixelY = t_point->data_y[i][j];

			deltaX = t_point->data_x[i][j + 1] - t_point->data_x[i][j];
			// deltaX = endX - beginX;
			deltaY = t_point->data_y[i][j + 1] - t_point->data_y[i][j];
			// deltaY = endY - beginY;
			pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
			deltaX /= pixels; // 1
 			deltaY /= pixels; // 0
			while (pixels)
			{
				// ft_putpixel_to_image(stack, pixelX, pixelY);
				// mlx_pixel_put(stack->mlx, stack->win, pixelX, pixelY, 0xFF0000);
				if (pixelX < stack->window_width && pixelY < stack->window_height)
					ft_putpixel_to_image(stack, pixelX, pixelY);
				pixelX += deltaX;
				pixelY += deltaY;
				--pixels;
			}
			j++;
		}
		i++;
	}
}

void ft_draw_line_vertical(t_point_lst *t_point, t_initialise_window *stack)
{
	double deltaX;
	double deltaY;
	double pixelX;
	double pixelY;
	int pixels;
	int i;
	int j;

	i = 0;
	while (i < t_point->coloums)
	{
		j = 0;
		while (j < t_point->rows - 1)
		{
			pixelX = t_point->data_x[j][i];
			pixelY = t_point->data_y[j][i];

			deltaX = t_point->data_x[j + 1][i] - t_point->data_x[j][i];
			// deltaX = endX - beginX;
			deltaY = t_point->data_y[j + 1][i] - t_point->data_y[j][i];
			// deltaY = endY - beginY;
			pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
			deltaX /= pixels; // 1
 			deltaY /= pixels; // 0
			while (pixels)
			{
				// mlx_pixel_put(stack->mlx, stack->win, pixelX, pixelY, 0xFF0000);
				//ft_putpixel_to_image(stack, pixelX, pixelY);
				if (pixelX < stack->window_width && pixelY < stack->window_height)
					ft_putpixel_to_image(stack, pixelX, pixelY);
				pixelX += deltaX;
				pixelY += deltaY;
				--pixels;
			}
			j++;
		}
		i++;
	}
}

void ft_draw(t_point_lst *t_point, t_initialise_window *stack)
{
	ft_draw_line_horizontal(t_point, stack);
	ft_draw_line_vertical(t_point, stack);
}
