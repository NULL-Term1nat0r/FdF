/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 22:43:12 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/17 03:01:21 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	ft_gettime(t_stack *stack)
{
	mach_timespec_t	current_time;

	clock_get_time(stack->clock_service, &current_time);
	return ((current_time.tv_sec - stack->start_time.tv_sec)
		+ (current_time.tv_nsec - stack->start_time.tv_nsec) / 1000000000.0);
}
