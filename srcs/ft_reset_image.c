/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 02:44:26 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/23 13:04:48 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_reset_image(t_stack*stack)
{
	int		i;
	int		j;
	char	*index;

	i = 0;
	while (i < stack->stack_width)
	{
		j = 0;
		while (j < stack->stack_height)
		{
			index = stack->data_ptr + (j * stack->size_line
					+ i * stack->bpp / 8);
			if (*(int *)index)
				*(int *)index = 0;
			j++;
		}
		i++;
	}
}
