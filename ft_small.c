/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 15:37:24 by oseng             #+#    #+#             */
/*   Updated: 2016/03/28 09:08:17 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
**draw the shell int the map inr green colour
*/

static void	ft_shell(t_env *a)
{
	if (a->map[(int)(a->xx)][(int)(a->yy)] != '0' || a->xx > X || a->xx < 0 ||
			a->yy > Y || a->yy < 0)
		ft_error();
	if (fabs(a->xx - a->posx) < 0.5 && fabs(a->yy - a->posy) < 0.5 &&
			a->small == 1)
	{
		ft_putendl("\nVictory !!!\nTry another level ;-)\n😎  🔥  🤗\n");
		exit(0);
	}
	if (a->map[(int)(a->xx + a->ii)][(int)(a->yy)] != '0')
		a->ii *= -1;
	if (a->map[(int)(a->xx)][(int)(a->yy + a->jj)] != '0')
		a->jj *= -1;
	a->xx += a->ii;
	a->yy += a->jj;
}

/*
**posx,y : my position on the map
**shell  : green pixel ont the map
*/

static void	ft_point(t_env *a)
{
	int		i;
	int		j;
	int		nb;

	nb = 2;
	i = -1;
	while (i++ < nb)
	{
		j = -1;
		while (j++ < nb)
		{
			a->color = 0xff0000;
			mlx_pixel_put_to_image(a->width / 2 - 20 + nb *
				(int)a->posx + i, nb * (int)a->posy + j, a);
			ft_shell(a);
			a->color = 0x00FF00;
			mlx_pixel_put_to_image(a->width / 2 - 20 + nb *
					(int)a->xx + i, nb * (int)a->yy + j, a);
		}
	}
}

void		ft_small(t_env *a)
{
	int		x;
	int		y;

	a->color = 0xCCCCCCCC;
	y = -1;
	while (y++ < Y - 1)
	{
		x = -1;
		while (x++ < X - 1)
		{
			if (a->map[y][x] != '0')
			{
				mlx_pixel_put_to_image(a->width / 2 - 20 + 2 * y, 2 * x, a);
				mlx_pixel_put_to_image(a->width / 2 - 20 + 2 * y + 1, 2 * x, a);
				mlx_pixel_put_to_image(a->width / 2 - 20 + 2 * y, 2 * x + 1, a);
				mlx_pixel_put_to_image(a->width / 2 - 20 + 2 * y + 1,
						2 * x + 1, a);
			}
		}
	}
	ft_point(a);
}
