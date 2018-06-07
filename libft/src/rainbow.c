/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:28:04 by sgarcia           #+#    #+#             */
/*   Updated: 2018/05/31 16:58:11 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rainbow(int index)
{
	char	c;

	c = (index % 7 + 1) + 48;
	if (index == -1)
		write(1, "\033[37m", 5);
	else
	{
		write(1, "\033[3", 3);
		write(1, &c, 1);
		write(1, "m", 1);
	}
}
