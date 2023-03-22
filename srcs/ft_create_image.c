/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:05:33 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/21 22:54:53 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// void ft_create_image(t_stack *stack)
// {
// 	int i;
// 	int j;
// 	int z;

// 	z = 0;
// 	i = 0;
// 	printf("gesamt: %d\n", z);
// 	while (i < stack->stack_height)
// 	{
// 		j = 0;
// 		while (j < stack->stack_height)
// 		{
// 			char *index = stack->data_ptr + (j * stack->size_line + i * stack->bpp / 8);
// 			if (*(int *)index)
// 				ft_putpixel_to_image(stack, i, j, stack->color);
// 			if (!*(int *)index)
// 				ft_putpixel_to_image(stack, i, j, stack->color_background);
// 			j++;
// 			z++;
// 		}
// 		i++;
// 	}
// 	printf("gesamt: %d\n", z);
// }
