/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpixel_to_image.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:51:16 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/23 12:57:16 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_putpixel_to_image(t_stack *stack, int x, int y, int color)
{
	char	*index;

	if (x >= 0 && y >= 0 && x < stack->stack_width && y < stack->stack_height)
	{
		index = stack->data_ptr + (y * stack->size_line + x * stack->bpp / 8);
		*(int *)index = color;
	}
}
