/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 15:30:58 by oseng             #+#    #+#             */
/*   Updated: 2016/04/04 09:18:02 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_check(char *str)
{
	if (ft_strcmp(str, "1111111111111111111111111") != 0)
		ft_error();
}

void		ft_error(void)
{
	ft_putendl("error 😜");
	exit(0);
}

static int	ft_open(char *str)
{
	int		fd;

	if (ft_strcmp(str, "1") == 0)
	{
		if ((fd = open("map/map1.wolf", O_RDONLY)) == -1)
			exit(0);
	}
	else if (ft_strcmp(str, "2") == 0)
	{
		if ((fd = open("map/map3.wolf", O_RDONLY)) == -1)
			exit(0);
	}
	else if (ft_strcmp(str, "3") == 0)
	{
		if ((fd = open("map/map4.wolf", O_RDONLY)) == -1)
			exit(0);
	}
	else if ((fd = open("map/map2.wolf", O_RDONLY)) == -1)
		exit(0);
	return (fd);
}

static int	ft_parse0(t_env e, char *str)
{
	int		fd;
	int		a;
	char	*line;

	a = 0;
	e.x = 0;
	e.y = 0;
	fd = 0;
	fd = ft_open(str);
	while ((e.ret = get_next_line(fd, &line)) > 0)
	{
		if (e.y > 0 && e.x != X)
			ft_error();
		if (e.y == 0)
			e.x = ft_strlen(line);
		e.y++;
		free(line);
	}
	if (e.y != Y)
		ft_error();
	return (e.y);
}

t_env		ft_parse(char *str)
{
	int		fd;
	char	*line;
	t_env	e;

	e.a = 0;
	e.x = 0;
	fd = 0;
	e.y = ft_parse0(e, str);
	if (!(e.map = (char**)malloc(sizeof(char*) * e.y)))
		ft_error();
	fd = ft_open(str);
	while ((e.ret = get_next_line(fd, &line)) > 0)
	{
		if (!(e.map[e.a] = (char*)malloc(sizeof(char) * ft_strlen(line))))
			ft_error();
		e.map[e.a] = ft_strdup(line);
		if (e.a == 0 || e.a == 24)
			ft_check(e.map[e.a]);
		if (e.map[e.a][0] != '1' || e.map[e.a][24] != '1')
			ft_error();
		e.a++;
		free(line);
	}
	close(fd);
	return (e);
}
