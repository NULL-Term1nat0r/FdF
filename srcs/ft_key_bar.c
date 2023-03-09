/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_bar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 02:17:03 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/08 23:06:29 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		display_control(t_stack *init)
{
	mlx_string_put(init->mlx, init->win, 5, 125, COLOR_WHITE,
	"Color_Basis: W = White, B = Blue, R = Red, G = Green");
	mlx_string_put(init->mlx, init->win, 5, 145, COLOR_WHITE,
	"Color_Altitude: H = White, Y = Yellow, C = Cyan, P = Pink");
	mlx_string_put(init->mlx, init->win, 5, 25, COLOR_WHITE,
	"Moves: Directional Arrows");
	mlx_string_put(init->mlx, init->win, 5, 5, COLOR_WHITE,
	"Zoom In & Out: + & -");
	mlx_string_put(init->mlx, init->win, 5, 65, COLOR_WHITE,
	"Increase & Decrease Depth: < & >");
	mlx_string_put(init->mlx, init->win, 5, 85, COLOR_WHITE,
	"Increase & Decrease Lenght: 4 & 6");
	mlx_string_put(init->mlx, init->win, 5, 105, COLOR_WHITE,
	"Increase & Decrease Height: 8 & 2");
	mlx_string_put(init->mlx, init->win, 5, 45, COLOR_WHITE,
	"Rotation X axis: 1 & 0");
}
