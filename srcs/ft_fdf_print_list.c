/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_print_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 03:01:05 by estruckm          #+#    #+#             */
/*   Updated: 2023/02/28 18:53:25 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_fdf_print_list(t_point_lst *stack, int rows, int coloums)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(i < rows)
	{
		j = 0;
		while(j < coloums)
		{
			printf("%d ", stack->data[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
