/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:00:24 by sgarcia           #+#    #+#             */
/*   Updated: 2018/06/07 18:55:31 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_game	distance_target_third(t_game game, int posx, int posy, int y)
{
	int		x;
	int		res;

	while (game.copy[y])
	{
		x = 0;
		while (game.copy[y][x])
		{
			if (game.copy[y][x] == game.adv)
			{
				res = calc_val_absolue((calc_val_absolue(posx, '-', x)),
						'+', (calc_val_absolue(posy, '-', y)));
				if (game.score_res >= res || game.score_res == -1)
				{
					game.xres = game.xsave;
					game.yres = game.ysave;
					game.score_res = res;
				}
			}
			x++;
		}
		y++;
	}
	return (game);
}

void	print_coord(int y, int x)
{
	write (1, &y, 1);
	write (1, " ", 1);
	write (1, &x, 1);
	write (1, "\n", 1);
}
