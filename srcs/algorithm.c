/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 18:06:49 by sgarcia           #+#    #+#             */
/*   Updated: 2018/06/07 18:56:17 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static t_game	distance_target_nd(t_game game)
{
	int		x;
	int		y;

	y = 0;
	while (game.copy[y])
	{
		x = 0;
		while (game.copy[y][x])
		{
			if (game.copy[y][x] == game.user)
				game = distance_target_third(game, x, y, 0);
			x++;
		}
		y++;
	}
	return (game);
}

static t_game	put_piece(t_game game)
{
	int		x;
	int		y;

	y = 0;
	while (game.piece[y])
	{
		x = 0;
		while (game.piece[y][x])
		{
			if (game.piece[y][x] == '*')
				game.copy[y + game.ysave][x + game.xsave] = game.user;
			x++;
		}
		y++;
	}
	return (game);
}

static t_game	distance_target(t_game game)
{
	int		x;
	int		y;

	y = 0;
	game.copy = tabdup(game.area);
	while (game.copy[y])
	{
		x = 0;
		while (game.copy[y][x])
		{
			if (game.copy[y][x] == game.user)
				game.copy[y][x] = '.';
			x++;
		}
		y++;
	}
	game = put_piece(game);
	game = distance_target_nd(game);
	return (game);
}

static t_game	check_piece(t_game game, int x, int y, int check)
{
	game.i = -1;
	while (game.piece[++game.i] && check < 2)
	{
		game.j = 0;
		x = game.xsave;
		while (game.piece[game.i][game.j] && check < 2)
		{
			if ((game.piece[game.i][game.j] == '*' && (game.area[y][x] == '.' ||
		game.area[y][x] == game.user)) || (game.piece[game.i][game.j] == '.'))
			{
				if (game.piece[game.i][game.j] == '*' &&
						game.area[y][x] == game.user)
					check++;
				game.j++;
				x++;
			}
			else
				check += 2;
		}
		y++;
	}
	if (check == 1)
		game = distance_target(game);
	return (game);
}

t_game			algorithm(t_game game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	game.adv = (game.user == 'X') ? 'O' : 'X';
	while (game.area[y] && (y + game.ypie <= game.yarr))
	{
		x = 0;
		while (game.area[y][x] && x + game.xpie <= game.xarr)
		{
			if ((game.piece[0][0] == '*' && (game.area[y][x] == '.' ||
		game.area[y][x] == game.user)) || game.piece[0][0] == '.')
			{
				game.xsave = x;
				game.ysave = y;
				game = check_piece(game, x, y, 0);
			}
			x++;
		}
		y++;
	}
	print_coord(game.yres, game.xres);
	return (game);
}
