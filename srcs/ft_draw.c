/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:19:34 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/23 12:45:46 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_change_color(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->rows)
	{
		j = 0;
		while (j < stack->coloums)
		{
			stack->data_color[i][j] = ft_rgb_to_color(stack->color_a,
					stack->color_r, stack->color_g, stack->color_b);
			j++;
		}
		i++;
	}
}

void	ft_draw_background(t_stack *stack)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	color = ft_rgb_to_color(0, 40, 40, 40);
	while (i < 1500)
	{
		j = 0;
		while (j < 1900)
		{
			ft_putpixel_to_image(stack, j, i, color);
			j++;
		}
		i++;
	}
}

void	ft_draw(t_stack *stack)
{
	ft_get_coordinates(stack);
	ft_reset_image(stack);
	ft_draw_background(stack);
	if (stack->color_change != 0)
		ft_change_color(stack);
	ft_draw_line_horizontal_main(stack);
	ft_draw_line_vertical_main(stack);
}
