/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rules.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fsnelder <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/23 12:10:40 by fsnelder      #+#    #+#                 */
/*   Updated: 2022/06/02 13:27:07 by fsnelder      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	rules(t_includes_t *i, int actioncode)
{
	if (i->ystart < 0 || i->xstart > i->width
		|| i->ystart > i->len || i->xstart < 0)
		return (0);
	if (!check_wall(i, actioncode))
		return (0);
	ft_count();
	remove_collectible(i);
	find_exit(i);
	return (1);
}

int	check_wall(t_includes_t *i, int actioncode)
{
	if (actioncode == 3)
	{
		if (i->map[i->ystart - 1][i->xstart] == '1')
			return (0);
		i->ystart = i->ystart - 1;
	}
	if (actioncode == 4)
	{
		if (i->map[i->ystart][i->xstart - 1] == '1')
			return (0);
		i->xstart = i->xstart - 1;
	}
	if (actioncode == 5)
	{
		if (i->map[i->ystart + 1][i->xstart] == '1')
			return (0);
		i->ystart = i->ystart + 1;
	}
	if (actioncode == 6)
	{
		if (i->map[i->ystart][i->xstart + 1] == '1')
			return (0);
		i->xstart = i->xstart + 1;
	}
	return (1);
}

void	remove_collectible(t_includes_t *i)
{
	if (i->map[i->ystart][i->xstart] == 'C')
	{
		i->map[i->ystart][i->xstart] = '0';
		i->collectcount -= 1;
		mlx_delete_image(i->mlx, i->collectible);
	}	
}

int	find_exit(t_includes_t *i)
{
	if (i->collectcount == 0)
	{
		if (i->map[i->ystart][i->xstart] == 'E')
			ft_exit(i);
	}
	return (1);
}
