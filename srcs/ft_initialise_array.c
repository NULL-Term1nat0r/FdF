/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialise_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:37:19 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/23 14:44:00 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*hax_get_next_line(int fd);

int	ft_get_rows(char **argv)
{
	int		i;
	int		fd;
	char	*s;

	i = 0;

	fd = open(argv[1], O_RDONLY);
	s = ft_get_next_line(fd);
	while (s)
	{
		free(s);
		s = ft_get_next_line(fd);
		i++;
	}
	free(s);
	if (i == 1)
	{
		ft_putendl_fd("Error! Provide a proper 2D Map!", 2);
		close(fd);
		exit(1);
	}
	close(fd);
	return (i);
}

int	ft_get_coloums(char **argv)
{
	int		i;
	int		fd;
	char	*s;
	char	**s_array;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	s = ft_get_next_line(fd);
	s_array = ft_split(s, ' ');
	free(s);
	while (s_array[i] != NULL)
		i++;
	ft_free_2d_char_array(i, s_array);
	close(fd);
	return (i);
}

int	**ft_malloc_2d_array(t_stack *stack, int ***array_adress)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	*array_adress = (int **)malloc(stack->rows * sizeof(int *));
	if (*array_adress == NULL)
		ft_putendl_fd("Error: could not allocate memory for row pointers\n", 2);
	while (i < stack->rows)
	{
		(*array_adress)[i] = (int *) malloc(stack->coloums * sizeof(int));
		if ((*array_adress)[i] == NULL)
		{
			ft_putendl_fd("Error: could not allocate memory for row %d\n", 2);
			while (j < i)
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

void	ft_initialise_array(t_stack *stack, char **argv)
{
	stack->rows = ft_get_rows(argv);
	stack->coloums = ft_get_coloums(argv);
	if (stack->coloums == 0 || stack->rows == 0)
	{
		ft_putendl_fd("Error! Provide a non empty 2D Map!", 2);
		exit(1);
	}
	if (stack->coloums == 1)
	{
		ft_putendl_fd("Error! You are gay! Not a proper 2d Map", 2);
		exit(1);
	}
	ft_malloc_2d_array(stack, &stack->data_x);
	ft_malloc_2d_array(stack, &stack->data_y);
	ft_malloc_2d_array(stack, &stack->data_z);
	ft_malloc_2d_array(stack, &stack->tmp_x);
	ft_malloc_2d_array(stack, &stack->tmp_y);
	ft_malloc_2d_array(stack, &stack->tmp_z);
	ft_malloc_2d_array(stack, &stack->data_color);
}
