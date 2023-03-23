/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trigonomic_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:07:24 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/23 12:35:18 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	ft_cos(int angle)
{
	double	rad_angle;
	double	c;

	rad_angle = angle * 3.14 / 180;
	c = cos(rad_angle);
	return (c);
}

double	ft_sin(int angle)
{
	double	rad_angle;
	double	c;

	rad_angle = angle * 3.14 / 180;
	c = sin(rad_angle);
	return (c);
}
