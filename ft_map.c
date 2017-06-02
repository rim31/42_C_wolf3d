/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 09:41:30 by oseng             #+#    #+#             */
/*   Updated: 2016/04/04 14:54:35 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** distance's projection correction : eye fish
*/

static void		ft_distance(t_env *a)
{
	if (a->side == 0)
		a->perpwalld = fabs((a->mapx - a->rayposx + (1 - a->stepx) / 2) /
		a->raydirx);
	else
		a->perpwalld = fabs((a->mapy - a->rayposy + (1 - a->stepy) / 2) /
		a->raydiry);
}

/*
**draw th floor
** can add the bonus : mouse vision on Y, by adding up according
**the mouse's position
*/

static	void	ft_floor(t_env *a, int drawend)
{
	if (drawend < 0)
		drawend = a->higth + a->up;
	a->y = drawend - 1;
	while (a->y++ < a->higth - a->up)
	{
		a->color = 0x03993B;
		mlx_pixel_put_to_image((int)a->x, (int)a->y + a->up, a);
	}
	a->y = drawend - 1;
	a->color = (a->small == 1) ? 0xFFCC00FF : 0xCC00FF;
	while (a->y++ < a->higth + a->up)
		mlx_pixel_put_to_image((int)a->x, a->higth - (int)a->y - 1 + a->up, a);
}

/*
**hline : heigth do draw
**drawstart & drawend : limit to the screen
**4 colours due position's player on the map  and the hit side
*/

static void		ft_draw(t_env *a)
{
	int			hline;
	int			drawstart;
	int			drawend;

	hline = abs((int)(a->higth / a->perpwalld));
	drawstart = (int)(-hline / 2 + a->higth / 2);
	drawend = (int)(hline / 2 + a->higth / 2);
	if (drawstart < 0)
		drawstart = 0;
	if (drawend >= a->higth)
		drawend = a->higth - 1;
	a->y = drawstart + a->up - 1;
	while (a->y++ < drawend + a->up)
	{
		a->color = (a->posx > a->mapx) ? 0x69B7B5 : 0xE5E976;
		if (a->side == 1)
			a->color = (a->posy > a->mapy) ? 0xEC0000 : 0xCCCCCC;
		if (a->lvl == 0)
			ft_texture(a, a->y);
		if (a->hit == 2)
			ft_poseshell(a);
		mlx_pixel_put_to_image((int)a->x, (int)a->y, a);
	}
	ft_floor(a, drawend);
}

/*
**sidx,y : go to the case forward
**deltadx,y : rise the ray
**side : orientation of the wall
*/

static void		ft_wall(t_env *a)
{
	while (a->hit == 0)
	{
		if (a->sidedx < a->sidedy)
		{
			a->sidedx += a->deltadx;
			a->mapx += a->stepx;
			a->side = 0;
		}
		else
		{
			a->sidedy += a->deltady;
			a->mapy += a->stepy;
			a->side = 1;
		}
		if (a->mapx == (int)a->xx && a->mapy == (int)a->yy)
			a->hit = 2;
		if (a->map[a->mapx][a->mapy] != '0' || a->mapx < 0 || a->mapy < 0 ||
			a->mapx > 24 || a->mapy > 24)
			a->hit = 1;
	}
}

int				ft_map(t_env *a)
{
	a->data = (char*)mlx_get_data_addr(a->image, &a->bpp, &a->size_line,
			&a->endian);
	a->x = -1;
	while (a->x++ <= a->width)
	{
		if (a->small != 0)
			ft_small(a);
		ft_ray(a);
		ft_step(a);
		ft_wall(a);
		ft_distance(a);
		ft_draw(a);
	}
	if (a->small == 1)
		mlx_put_image_to_window(a->mlx, a->win, a->sky,
				-400 + 20 * a->diry + 20 * a->dirx, -300);
	mlx_put_image_to_window(a->mlx, a->win, a->image, 0, 0);
	if (a->small == 1)
		mlx_put_image_to_window(a->mlx, a->win, a->texture,
				(int)(a->width / 2 - 66 / 2), a->higth - 89);
	if (a->lvl == 1)
		mlx_put_image_to_window(a->mlx, a->win, a->wall, a->shellx, a->shelly);
	return (0);
}
