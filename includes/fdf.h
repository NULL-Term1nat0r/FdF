/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 11:16:04 by nristorc          #+#    #+#             */
/*   Updated: 2023/03/04 00:48:57 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../Get_next_line/get_next_line_bonus.h"
# include "../push_swap/push_swap.h"
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "../minilibx_macos/mlx.h"

typedef struct s_point_lst
{
	int **data_x;
	int **data_y;
	int **data_z;
	int **data_color;
	int rows;
	int coloums;
} t_point_lst;

typedef struct s_initialise_window
{
	int s_x;
	int s_y;
	int bpp;
	int size_line;
	int endian;
	int window_width;
	int window_height;
	void *win;
	void *mlx;
	void *img_ptr;
    char *data_ptr;
} t_initialise_window;

int	ft_fdf_atoi(char *argv);
void ft_fdf_print_list(t_point_lst *t_point);
#endif
