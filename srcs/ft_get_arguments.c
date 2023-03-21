/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:15:41 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/21 18:49:00 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char **ft_get_array_argv(int fd)
{
	char *s;
	char **s_array;
	int z;

	z = 0;

	s = ft_get_next_line(fd);
	s_array = ft_split(s, ' ');
	free(s);
	return (s_array);
	// ft_free_2d_char_array()
}

void ft_get_arguments(t_stack *stack, char **argv)
{
	int fd;
	int i;
	int j;
	int z;
	char **s_array;

	i = 0;
	z = 0;

	ft_initialise_array(stack, argv);
	fd = open(argv[1], O_RDONLY);
	while (i < stack->rows)
	{
		s_array = ft_get_array_argv(fd);

		z = 0;
		j = 0;
		while (j < stack->coloums)
		{
			stack->data_x[i][j] = j;
			stack->data_y[i][j] = i;
			// printf("string: %s", s_array[j]);
			stack->data_z[i][j] = ft_fdf_atoi(s_array[j]);

			stack->data_color[i][j] = ft_hex_to_color(stack, s_array[j]);
			j++;
		}
		i++;
	}
	// ft_free_2d_char_array(stack->rows, s_array);
	// free(s_array);
	close(fd);
}
