/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:23:06 by sgarcia           #+#    #+#             */
/*   Updated: 2018/06/07 18:55:54 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "./../libft/src/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_game
{
	char		user;
	char		adv;
	char		*line;
	char		**area;
	char		**copy;
	char		**piece;
	int			i;
	int			j;
	int			xarr;
	int			yarr;
	int			xpie;
	int			ypie;
	int			xres;
	int			yres;
	int			xsave;
	int			ysave;
	int			score_res;
	int			score;
	int			fd;
}				t_game;

t_game			algorithm(t_game game);
t_game			distance_target_third(t_game game, int posx, int posy, int y);
void			print_coord(int y, int x);

#endif
