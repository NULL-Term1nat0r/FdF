/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 10:23:17 by nristorc          #+#    #+#             */
/*   Updated: 2023/03/22 04:13:53 by estruckm         ###   ########.fr       */
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
	stack->stack_width = 1900;
	stack->stack_height = 1500;
	stack->s_x = 750;
	stack->s_y = 750;
	stack->angle_z = 30;
	stack->angle_x = 30;
	stack->angle_y = 0;
	stack->factor_x = 10;
	stack->factor_z = 1;
	stack->move_x = 0;
	stack->move_y = 0;
	stack->color_rgb = 0;
	stack->isometric_mode = 0;
	stack->draw_loop = 0;
	stack->color_background = 0x778899;
	stack->mlx = mlx_init();
	stack->win = mlx_new_window(stack->mlx, stack->stack_width, stack->stack_height, "My Window");
	stack->img_ptr =mlx_new_image(stack->mlx, stack->stack_width, stack->stack_height);
    stack->data_ptr = mlx_get_data_addr(stack->img_ptr, &stack->bpp, &stack->size_line, &stack->endian);
	host_get_clock_service(mach_host_self(), REALTIME_CLOCK, &stack->clock_service);
	clock_get_time(stack->clock_service, &stack->start_time);
	stack->last_update_time = 0.0;
}

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
	if (stack->draw_loop == 0)
	{
		time = ft_gettime(stack);
		if (time - stack->last_update_time > 0.16)
		{
			ft_memset((stack->data_ptr) , 0, 9000000);
			ft_draw(stack);
			mlx_put_image_to_window(stack->mlx, stack->win, stack->img_ptr, 0, 0);
			display_control(stack);
			stack->angle_z += 0.1;
			stack->last_update_time = time;
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack *stack;
	int i;

	i = 12;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		ft_putendl_fd("Malloc Error!", 2);
	if (argc != 2)
	{
		ft_putendl_fd("Error! Stupid, stupid, stupid! Provide two valid arguments like './fdf test.fdf' for example", 2);
		exit(0);
	}
	ft_input(argv[1]);
	stack->color_a = 0;
	stack->color_r = 255;
	stack->color_g = 0;
	stack->color_b = 0;
	stack->color_change = 0;
	ft_get_arguments(stack, argv);
	ft_initialize_window(stack);
	ft_get_coordinates(stack);
	mlx_key_hook(stack->win, ft_keyboard_input, stack);
	mlx_loop_hook(stack->mlx, engine, stack);
	mlx_loop(stack->mlx);
	ft_free_stack(stack);
	free(stack);
	return (0);
}
// minilibx files https://github.com/gcamerli/minilibx/tree/master/src
//
// ft_draw(stack);
	// mlx_put_image_to_window(stack->mlx, stack->win, stack->img_ptr, 0, 0);
	// display_control(stack);
