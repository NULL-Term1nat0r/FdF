/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_coordinates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 02:26:42 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/07 02:11:00 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void ft_get_coordinates(t_point_lst *t_point, t_initialise_window *window)
{
	int i;
	int j;
	int x;
	int x_2;
	float y_2;
	float y;

	x = 0;
	y = 0;
	i = 0;
	j = 0;
	x_2 = window->s_x;
	y_2 = window->s_y;
	while (i < t_point->rows)
	{
		j = 0;
		// x_2 -= i * 10;
		// y_2 -= i * 5.77 * t_point->coloums;
		x_2 -= 10;
		y_2 += 6;
		while (j < t_point->coloums)
		{
			//fprintf(stderr, "i: %d j: %d\n", i, j);
			t_point->data_x[i][j] = (t_point->data_x[i][j] * 10) + x_2;
			t_point->data_y[i][j] = 6 * j - (t_point->data_z[i][j] * 7) + y_2;
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
