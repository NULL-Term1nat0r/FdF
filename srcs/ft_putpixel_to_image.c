/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpixel_to_image.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:51:16 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/08 19:14:47 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int *ft_putpixel_to_image(t_stack *stack, int x, int y, int color)
{
	char *index;

	index = stack->data_ptr + (y * stack->size_line + x * stack->bpp / 8);
	*(int *)index = color;
	return ((int *) index);
}
