/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_coordinates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 02:26:42 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/06 01:59:40 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void ft_get_coordinates(t_point_lst *t_point, t_initialise_window *window)
{
	int i;
	int j;
	int x;
	int y;

	x = window->s_x;
	y = window->s_y;
	i = 0;
	j = 0;
	while (i < t_point->rows)
	{
		j = 0;
		x -= 5;
		y += 5;
		while (j < t_point->coloums)
		{
			//fprintf(stderr, "i: %d j: %d\n", i, j);
			t_point->data_x[i][j] = t_point->data_x[i][j] * 10 + x;
			t_point->data_y[i][j] = (t_point->data_y[i][j] * (10)) - (t_point->data_z[i][j] * 1) + y;
			// x -= 9.9;
			// y -= 10;
			// printf("%d ", ft_fdf_atoi(s_array[j]));
			j++;
		}
		// x -= ((t_point->coloums + 1) * 10);
		// y -= ((t_point->coloums - 1) * 10);
		i++;
	}
}
