/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 10:23:17 by nristorc          #+#    #+#             */
/*   Updated: 2023/03/01 03:34:23 by estruckm         ###   ########.fr       */
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

	x = window->s_x;
	y = window->s_y;

	i = 0;
	ft_initialise_array(t_point, argv);
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
			t_point->data_y[i][j] = y - (ft_fdf_atoi(s_array[j]) * 5);
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

// // int draw_line(void *mlx, void *win, int row, int coloum);
// // {
// // 	double deltaX;
// // 	double deltaY;
// // 	int pixels;


// // 	deltaX = endX - beginX; // 10
// // 	deltaY = endY - beginY; // 0
// // 	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY)); //  pixels = sqrt((10 * 10) + (0 * 0)) = sqrt(100) = 10

// // 	deltaX /= pixels; // 1
// // 	deltaY /= pixels; // 0

// // 	double pixelX = beginX;
// // 	double pixelY = beginY;
// // 	while (pixels)
// // 	{
// // 		mlx_pixel_put(mlx, win, pixelX, pixelY, color);
// // 		pixelX += deltaX;
// // 		pixelY += deltaY;
// // 		--pixels;
// // 	}
// }

void ft_put_pixels(void *mlx, void *win, t_point_lst *stack)
{
	int i;
	int j;
	int z;


	i = 0;
	j = 0;

	while (i < stack->rows)
	{
		j = 0;
		while (j < stack->coloums)
		{
			z = 0;
			while (z <= 10)
			{
				mlx_pixel_put(mlx, win, stack->data_x[i][j] - z, stack->data_y[i][j] + z, 0xFF0000);
				z++;
			}
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
}

int			main(int argc, char **argv)
{
	void *mlx_ptr;
    void *win_ptr;
	int i;
	int j;
	int x;
	int y;
	// char *s;
	// char **s_array;
	j = 0;
	i = 0;
	x = 500;
	y = 50;
	t_point_lst stack;
	t_initialise_window window;

    // Initialize mlx
    mlx_ptr = mlx_init();
	if (argc > 2)
		printf("Error");
    // Create a window
	ft_initialize_window(&window);
    win_ptr = mlx_new_window(mlx_ptr, window.window_width, window.window_height, "My Window");
	// int draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color);

	// draw_line(mlx_ptr, win_ptr, 10, 10, 20, 10, 0xFFFFFF); // This should create a white horizontal line about 10 pixels long.
	// draw_line(line_array, mlx_ptr, win_ptr);
	ft_get_arguments(&stack, argv, &window);
	ft_put_pixels(mlx_ptr, win_ptr, &stack);
	// ft_fdf_print_list(&stack, ft_get_rows(argv), ft_get_coloums(argv));
	// while (i < 9)
	// {
	// 	fprintf(stderr, "%d ", stack.data[2][i]);
	// 	i++;
	// }
	// i = 0;
	// printf("\n");

	// while (i < stack.rows)
	// {
	// 	j = 0;
	// 	while (j < stack.coloums)
	// 	{
	// 		printf("current coordninates: %d | %d\n", x, y + stack.data[i][j]);
	// 		mlx_pixel_put(mlx_ptr, win_ptr, x, y - (stack.data[i][j] * 5), 0xFF0000);
	// 		x -= 10;
	// 		y += 10;
	// 		j ++;
	// 	}
	// 	i++;
	// 	x += (stack.coloums + 1) * 10;
	// 	y -= (stack.coloums - 1) * 10;
	// }

	// mlx_pixel_put(mlx_ptr, win_ptr, 500, 500 + stack.data[3][4], 0xFF0000);
	// mlx_pixel_put(mlx_ptr, win_ptr, 490, 490 + stack.data[3][4], 0xFF0000);

	// ft_put_pixels(mlx_ptr, win_ptr, &stack, &window);
	// mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFF0000);
	// printf("%d\n", ft_get_rows(argv));
	// printf("%d\n", ft_get_rows(argv));ç
	// printf("%d\n", ft_get_coloums(argv));

    // Draw a pixel at (250, 250) with color 0xFF0000 (red)
    //mlx_pixel_put(mlx_ptr, win_ptr, 100, 400, 0xFF0000);
	// mlx_pixel_put(mlx_ptr, win_ptr, 260, 250, 0xFF0000);
	// mlx_pixel_put(mlx_ptr, win_ptr, 250, 260, 0xFF0000);
	// mlx_pixel_put(mlx_ptr, win_ptr, 260, 260, 0xFF0000);



    // Display the window and wait for user input
    mlx_loop(mlx_ptr);
	return (0);
}
// minilibx files https://github.com/gcamerli/minilibx/tree/master/src
//
