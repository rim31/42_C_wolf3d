/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 17:50:12 by oseng             #+#    #+#             */
/*   Updated: 2016/03/31 12:17:35 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "./libft/libft.h"
# include "./minilibx_macos/mlx.h"
# include <math.h>
# define Y 25
# define X 25

typedef struct		s_env
{
	int				ret;
	int				picture;
	char			i;
	char			j;
	int				a;
	int				b;
	double			d;
	int				small;
	int				up;
	char			***tabl;
	int				rmoveup;
	int				rmovedown;
	int				rmoveleft;
	int				rmoverigth;
	int				moveup;
	int				movedown;
	int				moveleft;
	int				moverigth;
	int				run;
	char			**map;
	int				bpp;
	int				size_line;
	int				color;
	int				lvl;
	char			*data;
	int				endian;
	void			*mlx;
	void			*win;
	void			*image;
	char			**tab;
	int				centerx;
	int				centery;
	float			width;
	float			higth;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planx;
	double			plany;
	double			angle;
	double			dircamx;
	int				length;
	double			x;
	double			y;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	double			pas;
	int				mapx;
	int				mapy;
	double			sidedx;
	double			sidedy;
	double			deltadx;
	double			deltady;
	double			perpwalld;
	double			hit;
	double			side;
	double			stepx;
	double			stepy;
	double			xx;
	double			yy;
	double			ii;
	double			jj;
	void			*texture;
	unsigned char	*data1;
	int				pxlh;
	int				pxlw;
	void			*sky;
	unsigned char	*data2;
	int				pxlh2;
	int				pxlw2;
	int				endian2;
	void			*wall;
	unsigned char	*data3;
	int				bpp2;
	int				size_line2;
	int				pxlh3;
	int				pxlw3;
	double			shellx;
	double			shelly;
	void			*mur;
	int				drawstartx;
	int				drawstarty;
	int				texx;
	int				texy;
}					t_env;

void				ft_poseshell(t_env *a);
void				ft_error(void);
void				ft_texture(t_env *a, int y);
void				ft_step(t_env *a);
void				ft_ray(t_env *a);
int					ft_move(t_env *a);
void				ft_shoot(t_env *e);
void				mlx_pixel_put_to_image(int x, int y, t_env *e);
void				ft_start_screen(t_env a);
t_env				ft_parse(char *str);
int					my_keyrelease_funct(int keyrelease, t_env *a);
int					my_key_funct(int keypress, t_env *a);
int					my_mouse_fct(int x, int y, t_env *e);
int					my_mouse_funct(int button, int x, int y, t_env *e);
t_env				ft_init(t_env *a);
int					ft_map(t_env *a);
void				ft_small(t_env *a);
#endif
