/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 10:23:17 by nristorc          #+#    #+#             */
/*   Updated: 2023/02/25 03:35:58 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void draw_line(int *line_array, void *mlx_ptr, void *win_ptr)
{
	int i;

	i = line_array[2] - line_array[0];
	while (i-- >= 0)
		mlx_pixel_put(mlx_ptr, win_ptr, line_array[0] + i, line_array[0], 0xFF0000);
}

void test()
{

}
int			main(int argc, char **argv)
{
	// void *mlx_ptr;
    // void *win_ptr;
	int line_array[4];
	int fd;
	char *s;

	line_array[0] = 250;
	line_array[1] = 250;
	line_array[2] = 260;
	line_array[3] = 250;
	fd = open(argv[1], O_RDONLY);
    // Initialize mlx
    // mlx_ptr = mlx_init();
	if (argc > 2)
		printf("Error");
    // Create a window
    // win_ptr = mlx_new_window(mlx_ptr, 500, 500, "My Window");

	// draw_line(line_array, mlx_ptr, win_ptr);
	ft_strlen(s);
	s = ft_get_next_line(fd);
	printf("%s\n", s);

    // Draw a pixel at (250, 250) with color 0xFF0000 (red)
    // mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFF0000);
	// mlx_pixel_put(mlx_ptr, win_ptr, 260, 250, 0xFF0000);
	// mlx_pixel_put(mlx_ptr, win_ptr, 250, 260, 0xFF0000);
	// mlx_pixel_put(mlx_ptr, win_ptr, 260, 260, 0xFF0000);



    // Display the window and wait for user input
    // mlx_loop(mlx_ptr);
	return (0);
}
// minilibx files https://github.com/gcamerli/minilibx/tree/master/src
//
