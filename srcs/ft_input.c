/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:42:03 by vziegler          #+#    #+#             */
/*   Updated: 2023/03/16 20:37:54 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_input(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (argv[i - 1] != 'f' || argv[i - 2] != 'd' || argv[i - 3] != 'f')
	{
		ft_putendl_fd("Error! Wrong input file. Ask Chat Gpt if you are not smart enough!", 2);
		exit(1);
	}
}
