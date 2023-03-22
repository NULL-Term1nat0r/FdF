/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 11:16:04 by nristorc          #+#    #+#             */
/*   Updated: 2023/03/22 03:22:12 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../Get_next_line/get_next_line_bonus.h"
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <mach/mach.h>
# include <mach/clock.h>
// # include "../minilibx_macos/mlx_int.h"
# include "../minilibx_macos/mlx.h"

# define COLOR_WHITE 0xFFFFFF
# define COLOR_RED  0xFF0000
// # define COLOR_BLUE 0x0000FF
# define COLOR_BLUE 0xFF0000
# define COLOR_GREEN 0x00FF00
# define COLOR_YELLOW 0xFFFF00
# define COLOR_PINK 0xFF00FF
# define COLOR_CYAN 0x00FFFF
# define COLOR_ORANGE 0xFF90FF
# define COLOR_PURPLE 0xA437FF

# define KEYBOARD_A                     0x00
# define KEYBOARD_S                     0x01
# define KEYBOARD_D                     0x02
# define KEYBOARD_F                     0x03
# define KEYBOARD_H                     0x04
# define KEYBOARD_G                     0x05
# define KEYBOARD_Z                     0x06
# define KEYBOARD_X                     0x07
# define KEYBOARD_C                     0x08
# define KEYBOARD_V                     0x09
# define KEYBOARD_B                     0x0B
# define KEYBOARD_Q                     0x0C
# define KEYBOARD_W                     0x0D
# define KEYBOARD_E                     0x0E
# define KEYBOARD_R                     0x0F
# define KEYBOARD_Y                     0x10
# define KEYBOARD_T                     0x11
# define KEYBOARD_1                     0x12
# define KEYBOARD_2                     0x13
# define KEYBOARD_3                     0x14
# define KEYBOARD_4                     0x15
# define KEYBOARD_6                     0x16
# define KEYBOARD_5                     0x17
# define KEYBOARD_Equal                 0x18
# define KEYBOARD_9                     0x19
# define KEYBOARD_7                     0x1A
# define KEYBOARD_Minus                 0x1B
# define KEYBOARD_8                     0x1C
# define KEYBOARD_0                     0x1D
# define KEYBOARD_RightBracket          0x1E
# define KEYBOARD_O                     0x1F
# define KEYBOARD_U                     0x20
# define KEYBOARD_LeftBracket           0x21
# define KEYBOARD_I                     0x22
# define KEYBOARD_P                     0x23
# define KEYBOARD_L                     0x25
# define KEYBOARD_J                     0x26
# define KEYBOARD_Quote                 0x27
# define KEYBOARD_K                     0x28
# define KEYBOARD_Semicolon             0x29
# define KEYBOARD_Backslash             0x2A
# define KEYBOARD_Comma                 0x2B
# define KEYBOARD_Slash                 0x2C
# define KEYBOARD_N                     0x2D
# define KEYBOARD_M                     0x2E
# define KEYBOARD_Period                0x2F
# define KEYBOARD_Grave                 0x32
# define KEYBOARD_KeypadDecimal         0x41
# define KEYBOARD_KeypadMultiply        0x43
# define KEYBOARD_KeypadPlus            0x45
# define KEYBOARD_KeypadClear           0x47
# define KEYBOARD_KeypadDivide          0x4B
# define KEYBOARD_KeypadEnter           0x4C
# define KEYBOARD_KeypadMinus           0x4E
# define KEYBOARD_KeypadEquals          0x51
# define KEYBOARD_Keypad0               0x52
# define KEYBOARD_Keypad1               0x53
# define KEYBOARD_Keypad2               0x54
# define KEYBOARD_Keypad3               0x55
# define KEYBOARD_Keypad4               0x56
# define KEYBOARD_Keypad5               0x57
# define KEYBOARD_Keypad6               0x58
# define KEYBOARD_Keypad7               0x59
# define KEYBOARD_Keypad8               0x5B
# define KEYBOARD_Keypad9               0x5C
# define KEYBOARD_PLUS 43
# define KEYBOARD_MINUS 45

# define KEYBOARD_Return                     0x24
# define KEYBOARD_Tab                        0x30
# define KEYBOARD_Space                      0x31
# define KEYBOARD_Delete                     0x33
# define KEYBOARD_Escape                     0x35
# define KEYBOARD_Command                    0x37
# define KEYBOARD_Shift                      0x38
# define KEYBOARD_CapsLock                   0x39
# define KEYBOARD_Option                     0x3A
# define KEYBOARD_Control                    0x3B
# define KEYBOARD_RightShift                 0x3C
# define KEYBOARD_RightOption                0x3D
# define KEYBOARD_RightControl               0x3E
# define KEYBOARD_Function                   0x3F
# define KEYBOARD_F17                        0x40
# define KEYBOARD_VolumeUp                   0x48
# define KEYBOARD_VolumeDown                 0x49
# define KEYBOARD_Mute                       0x4A
# define KEYBOARD_F18                        0x4F
# define KEYBOARD_F19                        0x50
# define KEYBOARD_F20                        0x5A
# define KEYBOARD_F5                         0x60
# define KEYBOARD_F6                         0x61
# define KEYBOARD_F7                         0x62
# define KEYBOARD_F3                         0x63
# define KEYBOARD_F8                         0x64
# define KEYBOARD_F9                         0x65
# define KEYBOARD_F11                        0x67
# define KEYBOARD_F13                        0x69
# define KEYBOARD_F16                        0x6A
# define KEYBOARD_F14                        0x6B
# define KEYBOARD_F10                        0x6D
# define KEYBOARD_F12                        0x6F
# define KEYBOARD_F15                        0x71
# define KEYBOARD_Help                       0x72
# define KEYBOARD_Home                       0x73
# define KEYBOARD_PageUp                     0x74
# define KEYBOARD_ForwardDelete              0x75
# define KEYBOARD_F4                         0x76
# define KEYBOARD_End                        0x77
# define KEYBOARD_F2                         0x78
# define KEYBOARD_PageDown                   0x79
# define KEYBOARD_F1                         0x7A
# define KEYBOARD_LeftArrow                  0x7B
# define KEYBOARD_RightArrow                 0x7C
# define KEYBOARD_DownArrow                  0x7D
# define KEYBOARD_UpArrow                    0x7E

# define KEYBOARD_ESC 0x35

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
	double angle_x;
	double angle_y;
	double angle_z;
	int move_x;
	int move_y;
	int factor_x;
	double factor_z;

	int draw_loop;
	int isometric_mode;
	int c_x;
	int c_y;
	int wc_x;
	int wc_y;

	int				speed;

	int color_rgb;
	int color_a;
	int color_r;
	int color_g;
	int color_b;
	int color_change;
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

	clock_serv_t	clock_service;
	mach_timespec_t	start_time;
	double			last_update_time;
} t_stack;

int		ft_fdf_atoi(char *argv);
int		ft_get_color(char *argv);
void	ft_fdf_print_list(t_stack *stack);
void	ft_draw(t_stack *stack);
void	ft_get_arguments(t_stack *stack, char **argv);
void	ft_get_coordinates(t_stack *stack);
void	ft_initialise_array(t_stack *stack, char **argv);
int		ft_keyboard_input(int keycode, t_stack *stack);
void	ft_putpixel_to_image(t_stack *stack, int x, int y, int color);
void	display_control(t_stack *init);
void	ft_create_image(t_stack *stack);
void	ft_reset_image(t_stack *stack);
void	ft_cy(t_stack *stack);
void	ft_cx(t_stack *stack);
void	ft_input(char *argv);
double	ft_gettime(t_stack *stack);
int		ft_hex_to_color(t_stack *stack, const char *str);

void ft_free_2d_int_array(t_stack *stack, int **array);
void ft_free_2d_char_array(int num, char **array);
void ft_free_1d_char_array(t_stack *stack, char *array);
void ft_free_stack(t_stack *stack);

int ft_rgb_to_color(int a, int r, int g, int b);
void ft_draw_sidebar(t_stack *stack);

// int		ft_hex_to_int(char hex);

#endif
