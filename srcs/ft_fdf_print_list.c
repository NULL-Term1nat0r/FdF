/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_print_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 03:01:05 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/04 01:30:18 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_fdf_print_list(t_point_lst *stack)
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
			printf("(%d|%d|%d) ", stack->data_x[i][j], stack->data_y[i][j], stack->data_z[i][j]);
			j++;
		}
		printf("\n\n");
		i++;
	}
}
