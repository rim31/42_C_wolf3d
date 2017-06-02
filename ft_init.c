/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 09:40:23 by oseng             #+#    #+#             */
/*   Updated: 2016/03/25 18:43:28 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_env	ft_init(t_env *a)
{
	a->d = 0;
	a->a = 0;
	a->yy = 12;
	a->xx = 12;
	a->small = 0;
	a->up = 0;
	a->posx = 12;
	a->posy = 12;
	a->dircamx = -1;
	a->dircamx = 0;
	a->planx = 0;
	a->plany = 1;
	a->rmoveup = 0;
	a->rmovedown = 0;
	a->rmoveleft = 0;
	a->rmoverigth = 0;
	a->moveup = 0;
	a->movedown = 0;
	a->moveleft = 0;
	a->moverigth = 0;
	return (*a);
}
