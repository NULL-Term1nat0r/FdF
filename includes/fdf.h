/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 11:16:04 by nristorc          #+#    #+#             */
/*   Updated: 2023/03/13 01:27:16 by estruckm         ###   ########.fr       */
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
# include <sys/time.h>
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
# define KEYBOARD_Z 122
# define KEYBOARD_W 13
# define KEYBOARD_B 11
# define KEYBOARD_R 15
# define KEYBOARD_G 5
# define KEYBOARD_H 4
# define KEYBOARD_Y 16
# define KEYBOARD_C 8
# define KEYBOARD_P 35

# define KEYBOARD_PLUS 43
# define KEYBOARD_MINUS 45

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

# define RADIANT 0.016

typedef struct s_stack
{
	int **data_x;
	int **data_y;
	int **data_z;
	int **tmp_x;
	int **tmp_y;
	int **tmp_z;
	int **data_color;
	int rows;
	int coloums;

	int s_x;
	int s_y;
	double angle;
	int rotate_x;
	int rotate_y;
	int offset_x;
	int offset_y;
	int factor_x;
	int factor_z;

	int c_x;
	int c_y;
	int wc_x;
	int wc_y;

	int				speed;

	int color;
	int color_background;
	int bpp;
	int size_line;
	int endian;
	int stack_width;
	int stack_height;
	void *win;
	void *mlx;
	void *img_ptr;
	char *data_ptr;
} t_stack;

int		ft_fdf_atoi(char *argv);
void 	ft_fdf_print_list(t_stack *stack);
void	ft_draw(t_stack *stack);
void	ft_get_arguments(t_stack *stack, char **argv);
void	ft_get_coordinates(t_stack *stack);
void 	ft_initialise_array(t_stack *stack, char **argv);
int		ft_keyboard_input(int keycode, t_stack *stack);
int		*ft_putpixel_to_image(t_stack *stack, int x, int y, int color);
void	display_control(t_stack *init);
void	ft_create_image(t_stack *stack);
void	ft_reset_image(t_stack *stack);
void	ft_rotate(t_stack *stack);
void	ft_cy(t_stack *stack);
void	ft_cx(t_stack *stack);

#endif
