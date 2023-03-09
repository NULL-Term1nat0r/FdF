/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 02:44:26 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/08 19:14:34 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void ft_reset_image(t_stack*stack)
{
	{
	int i;
	int j;

	i = 0;

	while (i < stack->stack_height)
	{
		j = 0;
		while (j < stack->stack_height)
		{
			char *index = stack->data_ptr + (j * stack->size_line + i * stack->bpp / 8);
			if (*(int *)index)
				*(int *)index = 0;
			j++;
		}
		i++;
	}
}
}
