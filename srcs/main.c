/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 10:23:17 by nristorc          #+#    #+#             */
/*   Updated: 2023/03/09 03:11:07 by estruckm         ###   ########.fr       */
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
	stack->angle = 45;
	stack->rotate_x = 1;
	stack->rotate_y = 1;
	stack->offset_x = 10;
	stack->offset_y = 5;
	stack->factor_x = 10;
	stack->factor_z = 3;
	stack->color = 0xFF0000;
	stack->color_background = 0xFF00FF;
	stack->mlx = mlx_init();
	stack->win = mlx_new_window(stack->mlx, stack->stack_width, stack->stack_height, "My Window");
	stack->img_ptr =mlx_new_image(stack->mlx, stack->stack_width, stack->stack_height);
    stack->data_ptr = mlx_get_data_addr(stack->img_ptr, &stack->bpp, &stack->size_line, &stack->endian);
}
int ft_get_color(int red, int green, int blue, int alpha)
{
	int color;

	color = (alpha <<24) | (red << 16) | (green << 8) | blue;
	return (color);
}
void ft_define_pixel(t_stack *stack, int x, int y, int color)
{
	int bpp;
    int index;

	bpp = 32 / 8;
	index = (x * stack->size_line) + (y * bpp);
	*(int *)(stack->data_ptr + index) = color;
}
int	main(int argc, char **argv)
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		printf("Malloc error.");

	ft_initialize_window(stack);
	// display_control(stack);
	if (argc > 2)
		printf("Error");

	ft_get_arguments(stack, argv);


	ft_draw(stack, 0);
	ft_fdf_print_list(stack);
	mlx_put_image_to_window(stack->mlx, stack->win, stack->img_ptr, 0, 0);
	mlx_key_hook(stack->win, ft_keyboard_input, stack);
	mlx_loop(stack->mlx);
	return (0);
}
// minilibx files https://github.com/gcamerli/minilibx/tree/master/src
//
