/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 10:23:17 by nristorc          #+#    #+#             */
/*   Updated: 2023/03/04 02:40:13 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// void draw_line(int *line_array, void *mlx_ptr, void *win_ptr)
// {
// 	int i;

// 	i = line_array[2] - line_array[0];
// 	while (i-- >= 0)
// 		mlx_pixel_put(mlx_ptr, win_ptr, line_array[0] + i, line_array[0], 0xFF0000);
// }
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
	char *s;
	char **s_array;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if ((s = ft_get_next_line(fd)) != NULL)
	{
		s_array = ft_split(s, ' ');
		while(s_array[i] != NULL)
			i++;
		close(fd);
		return (i);
	}
	close(fd);
	return (0);
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

char **ft_get_array_argv(int fd)
{
	char *s;
	char **s_array;

	s = ft_get_next_line(fd);
	s_array = ft_split(s, ' ');
	return (s_array);
}
void ft_get_coordinates(t_point_lst *t_point, char **argv)
{
	int fd;
	int i;
	int j;
	char **s_array;

	i = 0;
	ft_initialise_array(t_point, argv);
	fd = open(argv[1], O_RDONLY);
	while (i < t_point->rows)
	{
		s_array = ft_get_array_argv(fd);
		j = 0;
		while (j < t_point->coloums)
		{
			//fprintf(stderr, "i: %d j: %d\n", i, j);
			t_point->data_x[i][j] = j;
			t_point->data_y[i][j] = i;
			t_point->data_z[i][j] = ft_fdf_atoi(s_array[j]);
			j++;
		}
		i++;
	}
	close(fd);
}

void ft_get_arguments(t_point_lst *t_point, char **argv, t_initialise_window *window)
{
	int i;
	int j;
	int x;
	int y;

	x = window->s_x;
	y = window->s_y;
	i = 0;
	j = 0;

	ft_get_coordinates(t_point, argv);
	while (i < t_point->rows)
	{
		j = 0;
		x += 4;
		y += 5;
		while (j < t_point->coloums)
		{
			//fprintf(stderr, "i: %d j: %d\n", i, j);
			t_point->data_x[i][j] = t_point->data_x[i][j] * 7 + x;
			t_point->data_y[i][j] = (t_point->data_y[i][j] * (2)) - (t_point->data_z[i][j] * 20) + y;
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

// void ft_get_arguments(t_point_lst *t_point, char **argv, t_initialise_window *window)
// {
// 	int fd;
// 	int i;
// 	int j;
// 	char **s_array;
// 	float x;
// 	int y;
// 	fprintf(stderr, "test\n");
// 	ft_initialise_array(t_point, argv);
// 	fprintf(stderr, "test\n");
// 	x = window->s_x;
// 	y = window->s_y;

// 	i = 0;
// 	fd = open(argv[1], O_RDONLY);
// 	while (i < t_point->rows)
// 	{
// 		s_array = ft_get_array_argv(fd);
// 		j = 0;
// 		while (j < t_point->coloums)
// 		{
// 			//fprintf(stderr, "i: %d j: %d\n", i, j);
// 			t_point->data_x[i][j] = x;
// 			fprintf(stderr, "test\n");
// 			t_point->data_y[i][j] = y - (ft_fdf_atoi(s_array[j]) * 10);
// 			printf("%s ", s_array[j]);
// 			x += 9.9;
// 			y += 10;
// 			// printf("%d ", ft_fdf_atoi(s_array[j]));
// 			j++;
// 		}
// 		printf("\n");
// 		x -= ((t_point->coloums + 1) * 10);
// 		y -= ((t_point->coloums - 1) * 10);
// 		i++;
// 	}
// 	close(fd);
// }

void ft_draw_line_horizontal(t_point_lst *t_point, t_initialise_window *stack)
{
	double deltaX;
	double deltaY;
	double pixelX;
	double pixelY;
	int pixels;
	int i;
	int j;

	i = 0;
	while (i < t_point->rows)
	{
		j = 0;
		while (j < t_point->coloums - 1)
		{
			pixelX = t_point->data_x[i][j];
			pixelY = t_point->data_y[i][j];

			deltaX = t_point->data_x[i][j + 1] - t_point->data_x[i][j];
			// deltaX = endX - beginX;
			deltaY = t_point->data_y[i][j + 1] - t_point->data_y[i][j];
			// deltaY = endY - beginY;
			pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
			deltaX /= pixels; // 1
 			deltaY /= pixels; // 0
			while (pixels)
			{
				mlx_pixel_put(stack->mlx, stack->win, pixelX, pixelY, 0xFF0000);
				pixelX += deltaX;
				pixelY += deltaY;
				--pixels;
			}
			j++;
		}
		i++;
	}
}

void ft_draw_line_vertical(t_point_lst *t_point, t_initialise_window *stack)
{
	double deltaX;
	double deltaY;
	double pixelX;
	double pixelY;
	int pixels;
	int i;
	int j;

	i = 0;
	while (i < t_point->coloums)
	{
		j = 0;
		while (j < t_point->rows - 1)
		{
			pixelX = t_point->data_x[j][i];
			pixelY = t_point->data_y[j][i];

			deltaX = t_point->data_x[j + 1][i] - t_point->data_x[j][i];
			// deltaX = endX - beginX;
			deltaY = t_point->data_y[j + 1][i] - t_point->data_y[j][i];
			// deltaY = endY - beginY;
			pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
			deltaX /= pixels; // 1
 			deltaY /= pixels; // 0
			while (pixels)
			{
				mlx_pixel_put(stack->mlx, stack->win, pixelX, pixelY, 0xFF0000);
				pixelX += deltaX;
				pixelY += deltaY;
				--pixels;
			}
			j++;
		}
		i++;
	}
}


void ft_put_pixels(t_point_lst *stack, t_initialise_window *window)
{
	int i;
	int j;
	// int z;


	i = 0;
	j = 0;
	while (i < stack->rows)
	{
		j = 0;
		while (j < stack->coloums)
		{
			mlx_pixel_put(window->mlx, window->win, stack->data_x[i][j], stack->data_y[i][j], 0xFF0000);
			j++;
		}
		i++;
	}
}

void ft_initialize_window(t_initialise_window *stack)
{
	stack->window_width = 2500;
	stack->window_height = 1500;
	stack->s_x = 200;
	stack->s_y = 200;
	stack->mlx = mlx_init();
	stack->win = mlx_new_window(stack->mlx, stack->window_width, stack->window_height, "My Window");
	stack->img_ptr =mlx_new_image(stack->mlx, stack->window_width, stack->window_height);
    stack->data_ptr = mlx_get_data_addr(stack->img_ptr, &stack->bpp, &stack->size_line, &stack->endian);
}
int ft_get_color(int red, int green, int blue, int alpha)
{
	int color;

	color = (alpha <<24) | (red << 16) | (green << 8) | blue;
	return (color);
}
void ft_define_pixel(t_initialise_window *window, int x, int y, int color)
{
	int bpp;
    int index;

	bpp = 32 / 8;
	index = (x * window->size_line) + (y * bpp);
	*(int *)(window->data_ptr + index) = color;
}
int	main(int argc, char **argv)
{
	t_point_lst stack;
	t_initialise_window window;

	ft_initialize_window(&window);
	if (argc > 2)
		printf("Error");
	// ft_get_arguments(&stack, argv);
	ft_get_coordinates(&stack, argv);
	ft_fdf_print_list(&stack);
	printf("\n");
	ft_get_arguments(&stack, argv, &window);
	ft_fdf_print_list(&stack);
	// ft_get_arguments(&stack, argv, &window);
	// ft_put_pixels(&stack, &window);
	ft_fdf_print_list(&stack);
	ft_draw_line_vertical(&stack, &window);
	ft_draw_line_horizontal(&stack, &window);
	fprintf(stderr, "test\n");
	// mlx_put_image_to_window(window.mlx, window.win, window.img_ptr, 0, 0);
    mlx_loop(window.mlx);
	return (0);
}
// minilibx files https://github.com/gcamerli/minilibx/tree/master/src
//
