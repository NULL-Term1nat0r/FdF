/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:15:41 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/08 19:18:02 by estruckm         ###   ########.fr       */
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
	// printf("%s \n", s);
	s_array = ft_split(s, ' ');
	// while (z < 10)
	// 		printf("%s ", s_array[z++]);
	// 	printf("\n");
	return (s_array);
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
	printf("test initialise");
	fd = open(argv[1], O_RDONLY);
	while (i < stack->rows)
	{
		s_array = ft_get_array_argv(fd);
		z = 0;
		j = 0;
		while (j < stack->coloums)
		{
			//fprintf(stderr, "i: %d j: %d\n", i, j);
			stack->data_x[i][j] = j;
			stack->data_y[i][j] = i;
			stack->data_z[i][j] = ft_fdf_atoi(s_array[j]);
			j++;
		}
		i++;
	}
	close(fd);
}
