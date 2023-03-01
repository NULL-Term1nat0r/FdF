/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 10:23:17 by nristorc          #+#    #+#             */
/*   Updated: 2023/03/01 20:53:44 by estruckm         ###   ########.fr       */
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

void ft_initialise_array(t_point_lst *t_point, char **argv)
{
	int i;
	int j;

	j = 0;
	i = 0;
	t_point->rows = ft_get_rows(argv);
	t_point->coloums = ft_get_coloums(argv);
	t_point->data_x = (int **)malloc(t_point->rows * sizeof(int *));
	t_point->data_y = (int **)malloc(t_point->rows * sizeof(int *));
	while (i < t_point->rows)
	{
		t_point->data_x[i] = (int *)malloc(t_point->coloums * sizeof(int));
		t_point->data_y[i] = (int *)malloc(t_point->coloums * sizeof(int));
		i++;
	}
}
void ft_get_arguments(t_point_lst *t_point, char **argv, t_initialise_window *window)
{
	int fd;
	int i;
	int j;
	char *s;
	char **s_array;
	int x;
	int y;
	ft_initialise_array(t_point, argv);
	x = window->s_x;
	y = window->s_y;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (i < t_point->rows)
	{
		s = ft_get_next_line(fd);
		s_array = ft_split(s, ' ');
		j = 0;
		while (j < t_point->coloums)
		{
			//fprintf(stderr, "i: %d j: %d\n", i, j);
			t_point->data_x[i][j] = x;
			t_point->data_y[i][j] = y - (ft_fdf_atoi(s_array[j]) * 10);
			x -= 10;
			y += 10;
			// printf("%d ", ft_fdf_atoi(s_array[j]));
			j++;
		}
		x += (t_point->coloums + 1) * 10;
		y -= (t_point->coloums - 1) * 10;
		i++;
	}
	close(fd);
}

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
//  	deltaX = endX - beginX; // 10
//  	deltaY = endY - beginY; // 0
//  	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY)); //  pixels = sqrt((10 * 10) + (0 * 0)) = sqrt(100) = 10
//  	deltaX /= pixels; // 1
//  	deltaY /= pixels; // 0
//  	double pixelX = beginX;
//  	double pixelY = beginY;
//  	while (pixels)
//  	{
//  		mlx_pixel_put(mlx, win, pixelX, pixelY, 0xFF0000);
//  		pixelX += deltaX;
//  		pixelY += deltaY;
//  		--pixels;
//  	}
// }

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
			// z = 0;
			// while (z <= 10)
			// {
			// 	mlx_pixel_put(window->mlx, window->win, stack->data_x[i][j] - z, stack->data_y[i][j] + z, 0xFF0000);
			// 	z++;
			// }
			j++;
		}
		i++;
	}
}

void ft_initialize_window(t_initialise_window *stack)
{

	stack->s_x = 500;
	stack->s_y = 50;
	stack->window_width = 1000;
	stack->window_height = 1000;
	stack->mlx = mlx_init();
	stack->win = mlx_new_window(stack->mlx, stack->window_width, stack->window_height, "My Window");
}

int			main(int argc, char **argv)
{
	t_point_lst stack;
	t_initialise_window window;

    // Initialize mlx
	if (argc > 2)
		printf("Error");
    // Create a window
	ft_initialize_window(&window);
	printf("s_x : %d\n", window.s_x);
	printf("s_y : %d\n", window.s_y);
	ft_get_arguments(&stack, argv, &window);
	// ft_put_pixels(&stack, &window);
	ft_draw_line_horizontal(&stack, &window);
	ft_draw_line_vertical(&stack, &window);
	fprintf(stderr, "test\n");

    mlx_loop(window.mlx);
	fprintf(stderr, "test\n");
	return (0);
}
// minilibx files https://github.com/gcamerli/minilibx/tree/master/src
//
