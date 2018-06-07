/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 16:09:39 by sgarcia           #+#    #+#             */
/*   Updated: 2018/06/07 18:42:13 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static t_game	init_game(t_game game)
{
	game.i = 0;
	game.j = 0;
	game.xarr = 0;
	game.yarr = 0;
	game.xpie = 0;
	game.ypie = 0;
	game.xres = -1;
	game.yres = -1;
	game.xsave = -1;
	game.ysave = -1;
	game.score_res = -1;
	game.score = 0;
	return (game);
}

static t_game	make_piece(t_game game)
{
	int		i;

	game.i = 0;
	game.ypie = atoi_end_index(&game.line);
	game.xpie = atoi_end_index(&game.line);
	game.piece = tabnew(game.xpie, game.ypie);
	i = 0;
	while (game.i < game.ypie)
	{
		get_next_line(0, &game.line);
		while (game.line[i])
		{
			game.piece[game.i][i] = game.line[i];
			i++;
		}
		if (i == game.xpie)
		{
			game.i++;
			i = 0;
		}
	}
	return (game);
}

static t_game	make_area(t_game game, int i, int j)
{
	game.area = tabnew(game.xarr, game.yarr);
	while (game.i < game.yarr)
	{
		while (game.line[i + j])
		{
			if (game.line[i + j] != '.' && game.line[i + j] != 'O' &&
					game.line[i + j] != 'X')
				i++;
			else
			{
				game.area[game.i][j] = game.line[i + j];
				j++;
			}
		}
		get_next_line(0, &game.line);
		i = 0;
		if (j == game.xarr)
		{
			game.i++;
			j = 0;
		}
	}
	return (game);
}

static t_game	count_column(t_game game, int nb)
{
	while (get_next_line(0, &game.line))
	{
		game.i = 0;
		while (game.line[game.i])
		{
			if (game.line[game.i] >= '0' && game.line[game.i] <= '9')
				nb++;
			if (nb > game.xarr)
				break ;
			game.i++;
		}
		if (nb > game.xarr)
			break ;
	}
	return (game);
}

int				main(void)
{
	t_game	game;

	get_next_line(0, &game.line);
	game.user = (game.line[10] == '1') ? 'O' : 'X';
	while (1)
	{
		game = init_game(game);
		get_next_line(0, &game.line);
		game.yarr = atoi_end_index(&game.line);
		game.xarr = atoi_end_index(&game.line);
		game = count_column(game, 0);
		game = make_area(game, 0, 0);
		game = make_piece(game);
		algorithm(game);
		tabfree(&game.piece);
		tabfree(&game.area);
	}
	return (0);
}
