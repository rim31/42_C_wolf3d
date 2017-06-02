/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 18:39:15 by oseng             #+#    #+#             */
/*   Updated: 2016/03/31 17:49:27 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_env	ft_initialize(t_env *a)
{
	a->x = -1;
	a->y = -1;
	a->posx = 12;
	a->posy = 12;
	a->dirx = -1;
	a->diry = 0;
	a->planx = 0;
	a->plany = 1;
	a->width = 600;
	a->higth = 600;
	a->run = 1;
	a->xx = 23;
	a->yy = 2;
	a->ii = 0.00005;
	a->jj = 0.00005;
	a->pas = 0.1;
	a->shellx = 800;
	a->shelly = 800;
	a->lvl = 1;
	return (*a);
}

int				main(int argc, char **argv)
{
	t_env		*a;

	ft_putstr("\033[92mEnter a number level between : 1 <-> 4\n\033[0m");
	ft_putstr("\033[88m...and find the shell⭐️\n\033[0m");
	if (X != 25 || Y != 25)
		ft_error();
	if (argc == 2)
	{
		a = malloc(sizeof(t_env));
		*a = ft_init(a);
		if (ft_atoi(argv[1]) >= 1 && ft_atoi(argv[1]) <= 4)
		{
			ft_putstr("\033[92mBONUS: S key, spacebar, mouse, map...\n\033[0m");
			*a = ft_parse(argv[1]);
			*a = ft_initialize(a);
			ft_start_screen(*a);
		}
		else
			ft_putstr("\033[96mERROR :-P\n\033[0m");
		free(a);
	}
	return (0);
}
