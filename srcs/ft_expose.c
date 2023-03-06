/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:47:54 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/06 03:05:27 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_expose(t_point_lst *t_point, t_initialise_window *window)
{
	ft_draw(t_point, window);
	mlx_destroy_image(window->mlx, window->img_ptr);
	mlx_put_image_to_window(window->mlx, window->win, window->img_ptr, 0, 0);
	return 0;
}
