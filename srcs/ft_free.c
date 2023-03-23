/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:32:36 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/23 16:07:22 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_free_2d_int_array(t_stack *stack, int **array)
{
	int	i;

	i = 0;
	while (i < stack->rows)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_free_2d_char_array(int num, char **array)
{
	int	i;

	i = 0;
	while (i < num)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_free_stack(t_stack *stack)
{
	ft_free_2d_int_array(stack, stack->data_x);
	ft_free_2d_int_array(stack, stack->data_y);
	ft_free_2d_int_array(stack, stack->data_z);
	ft_free_2d_int_array(stack, stack->tmp_x);
	ft_free_2d_int_array(stack, stack->tmp_y);
	ft_free_2d_int_array(stack, stack->tmp_z);
	ft_free_2d_int_array(stack, stack->data_color);
}
