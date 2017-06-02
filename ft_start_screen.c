/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 18:42:23 by oseng             #+#    #+#             */
/*   Updated: 2016/03/31 13:36:39 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
**try to texture
*/

void	ft_texture(t_env *a, int y)
{
	int		lineheight;
	int		d;
	double	sizewall;

	if (a->side == 0)
		sizewall = a->rayposy + a->perpwalld * a->raydiry;
	else
		sizewall = a->rayposx + a->perpwalld * a->raydirx;
	sizewall -= floor((sizewall));
	a->texx = (int)(sizewall * (double)(255));
	lineheight = (int)(a->higth / a->perpwalld);
	a->texx = 255 - a->texx - 1;
	d = y * 256 - a->higth * 128 + lineheight * 128;
	a->texy = ((d * 379) / lineheight) / 256;
	a->data3 = (unsigned char*)mlx_get_data_addr(a->mur, &a->bpp2,
		&a->size_line2, &a->endian2);
	a->color = *(unsigned int*)(&a->data3[a->texy * a->size_line2 +
		a->texx * a->bpp / 8]);
}

void	ft_start_screen(t_env a)
{
	if (a.map[(int)(a.posx)][(int)(a.posy)] != '0' || a.posx > X ||
		a.posy > Y || a.posx < 0 || a.posy < 0 || a.width < 1 || a.higth < 1)
		ft_error();
	if (a.map[(int)(a.xx)][(int)(a.yy)] != '0' || a.xx > X ||
			a.xx < 0 || a.yy > Y || a.yy < 0)
		ft_error();
	a.mlx = mlx_init();
	a.win = mlx_new_window(a.mlx, a.width, a.higth, "mlx 42");
	a.image = mlx_new_image(a.mlx, a.width, a.higth);
	if (!(a.sky = mlx_xpm_file_to_image(a.mlx, "img/sky.xpm", &a.pxlh2,
					&a.pxlw2)) && a.small == 1)
		ft_error();
	if (!(a.mur = mlx_xpm_file_to_image(a.mlx, "img/mur1.xpm", &a.pxlh3,
					&a.pxlw3)) && a.lvl == 0)
		ft_error();
	mlx_mouse_hook(a.win, my_mouse_funct, &a);
	mlx_hook(a.win, 6, 0, my_mouse_fct, &a);
	mlx_hook(a.win, 2, (1L << 0), my_key_funct, &a);
	mlx_hook(a.win, 3, (1L << 1), my_keyrelease_funct, &a);
	mlx_loop_hook(a.mlx, ft_move, &a);
	mlx_loop(a.mlx);
}
