/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 10:23:17 by nristorc          #+#    #+#             */
/*   Updated: 2023/03/06 02:11:09 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
	stack->window_width = 1500;
	stack->window_height = 1500;
	stack->s_x = 750;
	stack->s_y = 750;
	stack->color = 0xFF0000;
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
	t_point_lst *stack;
	t_initialise_window *window;

	stack = malloc(sizeof(t_point_lst));
	if (!stack)
		printf("Malloc error.");
	window = malloc(sizeof(t_initialise_window));
	if (!window)
		printf("Malloc error.");

	ft_initialize_window(window);
	printf("width: %d", window->window_width);
	printf("height: %d", window->window_height);
	if (argc > 2)
		printf("Error");
	ft_get_arguments(stack, argv);
	ft_fdf_print_list(stack);

	ft_get_coordinates(stack, window);
	ft_fdf_print_list(stack);

	printf("width: %d", window->window_width);
	printf("height: %d", window->window_height);

	ft_draw(stack, window);
	// ft_putpixel_to_image(window, 200, 400);
	// ft_putpixel_to_image(window, 400, 200);

	mlx_put_image_to_window(window->mlx, window->win, window->img_ptr, 0, 0);
	mlx_hook(window->win, 2, 3, ft_keyboard_input, &window);
	mlx_expose_hook(window->win, ft_expose, window);
	mlx_loop(window->mlx);
	return (0);
}
// minilibx files https://github.com/gcamerli/minilibx/tree/master/src
//
