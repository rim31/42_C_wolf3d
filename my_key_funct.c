/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_key_funct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 18:24:02 by oseng             #+#    #+#             */
/*   Updated: 2016/03/31 12:05:16 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		ft_rotation(int keycode, t_env *e)
{
	if (keycode == 1)
	{
		if (e->small == 0)
			e->small = 1;
		else
			e->small = 0;
	}
	if (keycode == 49)
	{
		if (e->pas == 0.1)
			e->pas = 0.3;
		else
			e->pas = 0.1;
	}
	if (keycode == 0)
	{
		if (e->lvl == 1)
			e->lvl = 0;
		else
			e->lvl = 1;
	}
}

int				my_key_funct(int keypress, t_env *a)
{
	if (keypress == 53)
		exit(0);
	if (keypress == 126)
		a->moveup = 1;
	else if (keypress == 125)
		a->movedown = 1;
	if (keypress == 123)
		a->moveleft = 1;
	else if (keypress == 124)
		a->moverigth = 1;
	if (keypress == 1 || keypress == 49 || keypress == 0)
		ft_rotation(keypress, a);
	return (0);
}

int				my_keyrelease_funct(int keyrelease, t_env *a)
{
	if (keyrelease == 126)
		a->moveup = 0;
	else if (keyrelease == 125)
		a->movedown = 0;
	if (keyrelease == 123)
		a->moveleft = 0;
	else if (keyrelease == 124)
		a->moverigth = 0;
	return (0);
}

/*
**possibility to see up/down with the mouse : e->updown = -(y - e->higth / 2);
*/

int				my_mouse_fct(int x, int y, t_env *e)
{
	double		center;
	double		oldd;
	double		oldp;

	if (x > 0 && x < e->width && y > 0 && y < e->higth)
	{
		center = (x - e->width / 2) / e->width;
		oldd = e->dirx;
		e->dirx = e->dirx * cos(-center) - e->diry * sin(-center);
		e->diry = oldd * sin(-center) + e->diry * cos(-center);
		oldp = e->planx;
		e->planx = e->planx * cos(-center) - e->plany * sin(-center);
		e->plany = oldp * sin(-center) + e->plany * cos(-center);
	}
	return (0);
}

int				my_mouse_funct(int button, int x, int y, t_env *e)
{
	int			a;
	int			b;

	if (button == 1)
	{
		mlx_string_put(e->mlx, e->win, x, y, 0xff00ff, "pan");
		a = (int)e->width;
		b = (int)e->higth;
		usleep(250);
	}
	return (0);
}
