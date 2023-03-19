/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 10:23:17 by nristorc          #+#    #+#             */
/*   Updated: 2023/03/19 03:42:44 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void ft_put_pixels(t_stack *stack)
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
			mlx_pixel_put(stack->mlx, stack->win, stack->data_x[i][j], stack->data_y[i][j], 0xFF0000);
			j++;
		}
		i++;
	}
}

void ft_initialize_window(t_stack *stack)
{
	stack->stack_width = 1500;
	stack->stack_height = 1500;
	stack->s_x = 750;
	stack->s_y = 750;
	stack->angle_z = 30;
	stack->angle_x = 30;
	stack->angle_y = 0;
	stack->rotate_x = 1;
	stack->rotate_y = 1;
	stack->offset_x = 10;
	stack->offset_y = 5;
	stack->factor_x = 10;
	stack->factor_z = 1;
	stack->color = 0xFF0000;
	stack->color_background = 0xFF00FF;
	stack->mlx = mlx_init();
	stack->win = mlx_new_window(stack->mlx, stack->stack_width, stack->stack_height, "My Window");
	stack->img_ptr =mlx_new_image(stack->mlx, stack->stack_width, stack->stack_height);
    stack->data_ptr = mlx_get_data_addr(stack->img_ptr, &stack->bpp, &stack->size_line, &stack->endian);
	host_get_clock_service(mach_host_self(), REALTIME_CLOCK, &stack->clock_service);
	clock_get_time(stack->clock_service, &stack->start_time);
	stack->last_update_time = 0.0;
}
// int ft_get_color(int red, int green, int blue, int alpha)
// {
// 	int color;

// 	color = (alpha <<24) | (red << 16) | (green << 8) | blue;
// 	return (color);
// }
void ft_define_pixel(t_stack *stack, int x, int y, int color)
{
	int bpp;
    int index;

	bpp = 32 / 8;
	index = (x * stack->size_line) + (y * bpp);
	*(int *)(stack->data_ptr + index) = color;
}

long	millis(struct timeval time)
{
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	engine(t_stack *stack)
{
	double	time;
	//struct timeval			current_time;
	//static struct timeval	time_stamp;

	//gettimeofday(&current_time, NULL);
	time = ft_gettime(stack);
	if (time - stack->last_update_time > 0.016)
	{
		ft_memset((stack->data_ptr) , 0, 9000000);
		ft_draw(stack);
		mlx_put_image_to_window(stack->mlx, stack->win, stack->img_ptr, 0, 0);
		display_control(stack);
		stack->angle_z -= 0.5;
		stack->angle_x -= 0.5;
		stack->angle_y -= 0.5;
		stack->last_update_time = time;
	}

	return (0);
}

int	main(int argc, char **argv)
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		ft_putendl_fd("Malloc Error!", 2);
	if (argc != 2)
	{
		ft_putendl_fd("Error! Stupid, stupid, stupid! Provide two valid arguments like './fdf test.fdf' for example", 2);
		exit(0);
	}
	ft_input(argv[1]);
	ft_get_arguments(stack, argv);
	ft_initialize_window(stack);
	// ft_get_coordinates(stack);
	// ft_draw(stack);
	// mlx_put_image_to_window(stack->mlx, stack->win, stack->img_ptr, 0, 0);
	// display_control(stack);
	mlx_key_hook(stack->win, ft_keyboard_input, stack);
	mlx_loop_hook(stack->mlx, engine, stack);

	mlx_loop(stack->mlx);
	return (0);
}
// minilibx files https://github.com/gcamerli/minilibx/tree/master/src
//
