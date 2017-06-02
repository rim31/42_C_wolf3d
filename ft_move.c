/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 15:17:44 by oseng             #+#    #+#             */
/*   Updated: 2016/03/31 18:46:42 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_poseshell(t_env *a)
{
	a->shellx = a->x - 65;
	a->shelly = a->y - 65;
	a->color = 0xFFFFFF;
}

static void	ft_enemie(t_env *a)
{
	a->shellx = 800;
	a->shelly = 800;
	if (a->lvl == 1)
	{
		if (fabs(a->xx - a->posx) + fabs(a->yy - a->posy) < 2 &&
		a->small == 1)
		{
			if (!(a->wall = mlx_xpm_file_to_image(a->mlx, "img/shell2.xpm",
							&a->pxlh3, &a->pxlw3)))
				ft_error();
		}
		else if (fabs(a->xx - a->posx) + fabs(a->yy - a->posy) < 9 &&
		a->small == 1)
		{
			if (!(a->wall = mlx_xpm_file_to_image(a->mlx, "img/shell1.xpm",
							&a->pxlh3, &a->pxlw3)))
				ft_error();
		}
		else
		{
			if (!(a->wall = mlx_xpm_file_to_image(a->mlx, "img/shell0.xpm",
							&a->pxlh3, &a->pxlw3)))
				ft_error();
		}
	}
}

static void	ft_pers(t_env *a)
{
	if (a->moveleft == 1)
	{
		if (!(a->texture = mlx_xpm_file_to_image(a->mlx, "img/toadg.xpm",
				&a->pxlh, &a->pxlw)))
			ft_error();
	}
	else if (a->moverigth == 1)
	{
		if (!(a->texture = mlx_xpm_file_to_image(a->mlx, "img/toadd.xpm",
				&a->pxlh, &a->pxlw)))
			ft_error();
	}
	else
	{
		if (!(a->texture = mlx_xpm_file_to_image(a->mlx, "img/toad.xpm",
					&a->pxlh, &a->pxlw)))
			ft_error();
	}
	ft_enemie(a);
}

static void	ft_move1(t_env *a, double center)
{
	double	oldd;
	double	oldp;

	if (a->moveleft == 1)
		center = -5 * M_PI / 180;
	else if (a->moverigth == 1)
		center = 5 * M_PI / 180;
	oldd = a->dirx;
	a->dirx = a->dirx * cos(-center) - a->diry * sin(-center);
	a->diry = oldd * sin(-center) + a->diry * cos(-center);
	oldp = a->planx;
	a->planx = a->planx * cos(-center) - a->plany * sin(-center);
	a->plany = oldp * sin(-center) + a->plany * cos(-center);
}

int			ft_move(t_env *a)
{
	double	center;

	center = 0.0;
	if (a->moveup == 1)
	{
		if (a->map[(int)(a->posx + a->dirx * a->pas)]
		[(int)(a->posy)] == '0')
			a->posx += a->dirx * a->pas;
		if (a->map[(int)(a->posx)]
		[(int)(a->posy + a->diry * a->pas)] == '0')
			a->posy += a->diry * a->pas;
	}
	else if (a->movedown == 1)
	{
		if (a->map[(int)(a->posx - a->dirx * a->pas)]
		[(int)a->posy] == '0')
			a->posx -= a->dirx * a->pas;
		if (a->map[(int)(a->posx)]
		[(int)(a->posy - a->diry * a->pas)] == '0')
			a->posy -= a->diry * a->pas;
	}
	ft_move1(a, center);
	ft_pers(a);
	ft_map(a);
	return (0);
}
