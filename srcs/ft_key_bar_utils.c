/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_bar_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:44:34 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/23 13:00:00 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*ft_create_double_string(double *variable, char *description)
{
	char	*value;
	char	*output_string;

	value = ft_itoa(*variable);
	output_string = ft_strjoin(description, value);
	free(value);
	return (output_string);
}

char	*ft_create_int_string(int variable, char *description, char *dest)
{
	char	num_buf[8];

	ft_memset(dest, 0, 26);
	ft_memset(num_buf, 0, 8);
	ft_itoa_s(variable, num_buf);
	ft_memmove(dest, description, ft_strlen(description));
	ft_memmove(dest + ft_strlen(dest), num_buf, ft_strlen(num_buf));
	return (dest);
}
