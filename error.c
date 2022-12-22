/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fsnelder <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/23 12:10:13 by fsnelder      #+#    #+#                 */
/*   Updated: 2022/06/02 13:25:31 by fsnelder      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_includes_t	overallcheck(t_includes_t *i)
{
	int	width;
	int	len;

	width = (check_mapwidth(i) - 1);
	len = (check_maplen(i) - 1);
	i->len = len;
	i->width = width;
	if (width == len)
		error(i);
	check_edges(i, len, width);
	check_isvalid(i, width);
	check_collectibles(len, width, i);
	check_exit(len, width, i);
	check_start(len, width, i);
	return (*i);
}

int	check_mapwidth(t_includes_t *i)
{
	int	x;

	x = 0;
	while (i->map[0][x] != '\0')
		x++;
	return (x);
}

int	check_maplen(t_includes_t *i)
{
	int	y;

	y = 0;
	while (i->map[y] != '\0')
		y++;
	return (y);
}

void	check_edges(t_includes_t *i, int len, int width)
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	while (x < width && y < len)
	{
		while (x <= width)
		{
			if ((i->map[0][x] != '1') || (i->map[len][x] != '1'))
				error(i);
			x++;
		}
		while (y <= len)
		{
			if ((i->map[y][0] != '1') || (i->map[y][width] != '1'))
				error(i);
			y++;
		}
		break ;
	}
}

void	check_isvalid(t_includes_t *i, int width)
{
	int	x;
	int	y;
	int	var;

	y = 0;
	x = 0;
	while (i->map[y] != '\0')
	{
		x = 0;
		while (i->map[y][x] != '\0')
		{
			var = i->map[y][x];
			if (var != '0' && var != '1' && var != 'C'
				&& var != 'P' && var != 'E')
				error(i);
			x++;
		}
		if (x - 1 != width)
			error(i);
		y++;
	}
}
