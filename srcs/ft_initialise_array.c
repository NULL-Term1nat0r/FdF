/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialise_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:37:19 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/05 19:23:31 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int ft_get_rows(char **argv)
{
	int i;
	int fd;
	char *s;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	while ((s = ft_get_next_line(fd)) != NULL)
	{
		i++;
	}
	close(fd);
	return (i);
}

int ft_get_coloums(char **argv)
{
	int i;
	int fd;
	int z;
	char *s;
	char **s_array;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if ((s = ft_get_next_line(fd)) != NULL)
	{
		s_array = ft_split(s, ' ');
		while(s_array[i] != NULL)
			i++;
	}
	z = i;
	while ((s = ft_get_next_line(fd)) != NULL)
	{
		z++;
	}
	close(fd);
	return (i);
}

int	**ft_malloc_2d_array(t_point_lst *stack, int ***array_adress)
{
	int i;
	int j;

	i = 0;
	j = 0;
	*array_adress = (int **)malloc(stack->rows * sizeof(int *));
	if (*array_adress == NULL)
		printf("Error: could not allocate memory for row pointers\n");
	while (i < stack->rows)
	{
		(*array_adress)[i] = (int*) malloc(stack->coloums * sizeof(int));
		if ((*array_adress)[i] == NULL)
		{
			printf("Error: could not allocate memory for row %d\n", i);
			while ( j < i)
			{
				free((*array_adress)[j++]);
			}
			free(*array_adress);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return ((*array_adress));
}

void ft_initialise_array(t_point_lst *t_point, char **argv)
{
	t_point->rows = ft_get_rows(argv);
	t_point->coloums = ft_get_coloums(argv);
	ft_malloc_2d_array(t_point, &t_point->data_x);
	ft_malloc_2d_array(t_point, &t_point->data_y);
	ft_malloc_2d_array(t_point, &t_point->data_z);
	ft_malloc_2d_array(t_point, &t_point->data_color);
}
