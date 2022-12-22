/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fsnelder <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/23 12:10:28 by fsnelder      #+#    #+#                 */
/*   Updated: 2022/06/02 13:25:55 by fsnelder      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <stdio.h>

static void	ft_putcount(long int i)
{
	if (i < 0)
	{
		write (1, "-", 1);
		i *= -1;
	}
	if (i > 9)
		ft_putcount(i / 10);
	i = i % 10 + '0';
	write (1, &i, 1);
}

void	ft_count(void)
{
	static int	count;

	count++;
	ft_putcount(count);
	write(1, "\n", 1);
}

void	ft_keyaction(mlx_key_data_t keydata, t_includes_t *i)
{
	if (keydata.key == MLX_KEY_W)
	{
		if (rules(i, 3))
			i->player->instances[0].y -= 128;
	}
	if (keydata.key == MLX_KEY_A)
	{
		if (rules(i, 4))
			i->player->instances[0].x -= 128;
	}
	if (keydata.key == MLX_KEY_S)
	{
		if (rules(i, 5))
			i->player->instances[0].y += 128;
	}
	if (keydata.key == MLX_KEY_D)
	{
		if (rules(i, 6))
			i->player->instances[0].x += 128;
	}
}

void	create_hooks(mlx_key_data_t keydata, void *param)
{
	t_includes_t	*i;

	i = param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			ft_exit(i);
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_A
			|| keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_D)
			ft_keyaction(keydata, i);
	}
}
