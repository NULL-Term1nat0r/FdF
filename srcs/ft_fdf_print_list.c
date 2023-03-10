/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_print_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 03:01:05 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/08 19:18:15 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_fdf_print_list(t_stack *stack)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(i < stack->rows)
	{
		j = 0;
		while(j < stack->coloums)
		{
			printf("(%d|%d) ", stack->tmp_x[i][j], stack->tmp_y[i][j]);
			j++;
		}
		printf("\n\n");
		i++;
	}
}
