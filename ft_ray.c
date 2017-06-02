/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 09:49:09 by oseng             #+#    #+#             */
/*   Updated: 2016/03/28 13:32:02 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
**step : vect direction
**sidexy : distance
*/

void	ft_step(t_env *a)
{
	if (a->raydirx < 0)
	{
		a->stepx = -1;
		a->sidedx = (a->rayposx - a->mapx) * a->deltadx;
	}
	else
	{
		a->stepx = 1;
		a->sidedx = (a->mapx + 1.0 - a->rayposx) * a->deltadx;
	}
	if (a->raydiry < 0)
	{
		a->stepy = -1;
		a->sidedy = (a->rayposy - a->mapy) * a->deltady;
	}
	else
	{
		a->stepy = 1;
		a->sidedy = (a->mapy + 1.0 - a->rayposy) * a->deltady;
	}
}

/*
**dircam : position vartical ray
**deltad : position every intersection
*/

void	ft_ray(t_env *a)
{
	a->dircamx = (2 * a->x / a->width) - 1;
	a->rayposx = a->posx;
	a->rayposy = a->posy;
	a->raydirx = a->dirx + a->planx * a->dircamx;
	a->raydiry = a->diry + a->plany * a->dircamx;
	a->mapx = (int)a->rayposx;
	a->mapy = (int)a->rayposy;
	a->deltadx = sqrt(1 + pow(a->raydiry, 2) / pow(a->raydirx, 2));
	a->deltady = sqrt(1 + pow(a->raydirx, 2) / pow(a->raydiry, 2));
	a->hit = 0;
}
