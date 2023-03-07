/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 11:16:04 by nristorc          #+#    #+#             */
/*   Updated: 2023/03/07 02:19:05 by estruckm         ###   ########.fr       */
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

# define COLOR_WHITE 0xFFFFFF
# define COLOR_RED  0xFF0000
# define COLOR_BLUE 0x0000FF
# define COLOR_GREEN 0x00FF00
# define COLOR_YELLOW 0xFFFF00
# define COLOR_PINK 0xFF00FF
# define COLOR_CYAN 0x00FFFF
# define COLOR_ORANGE 0xFF90FF
# define COLOR_PURPLE 0xA437FF

# define KEYBOARD_ESC 53
# define KEYBOARD_W 13
# define KEYBOARD_B 11
# define KEYBOARD_R 15
# define KEYBOARD_G 5
# define KEYBOARD_H 4
# define KEYBOARD_Y 16
# define KEYBOARD_C 8
# define KEYBOARD_P 35
# define KEYBOARD_ARROW_LEFT 123
# define KEYBOARD_ARROW_RIGHT 124
# define KEYBOARD_ARROW_UP 125
# define KEYBOARD_ARROW_DOWN 126
# define KEYBOARD_ZOOM_IN 69
# define KEYBOARD_ZOOM_OUT 78
# define KEYBOARD_DEPTH_UP 47
# define KEYBOARD_DEPTH_DOWN 43
# define KEYBOARD_INC_LENGHT 86
# define KEYBOARD_DEC_LENGHT 88
# define KEYBOARD_INC_HEIGHT 91
# define KEYBOARD_DEC_HEIGHT 84
# define KEYBOARD_ROT_LEFT 83
# define KEYBOARD_ROT_RIGHT 82

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
	int color;
	int bpp;
	int size_line;
	int endian;
	int window_width;
	int window_height;
	void *win;
	void *mlx;
	void *img_ptr;
	char *data_ptr;
	t_point_lst *t_point;
} t_initialise_window;

int		ft_fdf_atoi(char *argv);
void 	ft_fdf_print_list(t_point_lst *t_point);
void	ft_draw(t_point_lst *t_point, t_initialise_window *stack);
void	ft_get_arguments(t_point_lst *t_point, char **argv);
void	ft_get_coordinates(t_point_lst *t_point, t_initialise_window *window);
void 	ft_initialise_array(t_point_lst *t_point, char **argv);
int		ft_expose(t_point_lst *t_point, t_initialise_window *window);
int		ft_keyboard_input(int keycode, t_initialise_window *window);
int		*ft_putpixel_to_image(t_initialise_window *window, int x, int y);
void display_control(t_initialise_window *init);


#endif
