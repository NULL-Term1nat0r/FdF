/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:15:41 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/23 16:59:43 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// char	**ft_get_array_argv(int fd)
// {
// 	char	*s;
// 	char	**s_array;

// 	s = ft_get_next_line(fd);

// 	s_array = ft_split(s, ' ');
// 	free(s);
// 	return (s_array);
// }

void	ft_get_arguments(t_stack *stack, char **argv)
{
	int		fd;
	int		i;
	int		j;
	char	**s_array;
	char	*s;
	// stack->y = 0;

	i = 0;
	ft_initialise_array(stack, argv);
	fd = open(argv[1], O_RDONLY);
	printf("coloums: %d\n", stack->coloums);
	while (i < stack->rows)
	{
		// s_array = ft_get_array_argv(fd);
		s = ft_get_next_line(fd);
		s_array = ft_split(s, ' ');
		free(s);
		j = 0;
		while (j < stack->coloums)
		{
			stack->data_x[i][j] = j;
			stack->data_y[i][j] = i;
			stack->data_z[i][j] = ft_fdf_atoi(s_array[j]);
			stack->data_color[i][j] = ft_hex_to_color(stack, s_array[j]);
			j++;
		}
		// if (stack->rows != 500)
		// 	printf("rows: %d\n", stack->rows);
		ft_free_2d_char_array(stack->coloums, s_array);
		i++;
	}
	// ft_free_2d_char_array(stack->coloums, s_array);
	// printf("y: %d\n", stack->y);
	close(fd);
}
