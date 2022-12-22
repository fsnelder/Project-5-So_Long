/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setcoordinates.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fsnelder <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/23 12:10:47 by fsnelder      #+#    #+#                 */
/*   Updated: 2022/06/02 13:29:09 by fsnelder      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_includes_t	check_collectibles(int len, int width, t_includes_t *i)
{
	int	collectible;
	int	x;
	int	y;

	y = 0;
	collectible = 0;
	while (y < len)
	{
		x = 0;
		while (x < width)
		{
			if (i->map[y][x] == 'C')
			{
				i->xcoll = x;
				i->ycoll = y;
				collectible++;
			}
			x++;
		}
		y++;
	}
	i->collectcount = collectible;
	if (collectible != 1)
		error(i);
	return (*i);
}

t_includes_t	check_exit(int len, int width, t_includes_t *i)
{
	int	exit;
	int	x;
	int	y;

	y = 0;
	exit = 0;
	while (y < len)
	{
		x = 0;
		while (x < width)
		{
			if (i->map[y][x] == 'E')
			{
				i->xexit = x;
				i->yexit = y;
				exit++;
			}
			x++;
		}
		y++;
	}
	if (exit != 1)
		error(i);
	return (*i);
}

t_includes_t	check_start(int len, int width, t_includes_t *i)
{
	int	start;
	int	x;
	int	y;

	y = 0;
	start = 0;
	while (y < len)
	{
		x = 0;
		while (x < width)
		{
			if (i->map[y][x] == 'P')
			{
				i->xstart = x;
				i->ystart = y;
				start++;
			}
			x++;
		}
		y++;
	}
	if (start != 1)
		error(i);
	return (*i);
}
