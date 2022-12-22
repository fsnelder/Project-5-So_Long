/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   createmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fsnelder <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/23 12:09:40 by fsnelder      #+#    #+#                 */
/*   Updated: 2022/06/02 13:33:34 by fsnelder      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_exit(void *param)
{
	t_includes_t	*i;

	i = param;
	free_string(i->map);
	mlx_delete_image(i->mlx, i->player);
	mlx_delete_image(i->mlx, i->exit);
	mlx_delete_image(i->mlx, i->collectible);
	mlx_delete_texture(i->images.background);
	mlx_delete_texture(i->images.wall);
	mlx_delete_texture(i->images.collectible);
	mlx_delete_texture(i->images.player);
	mlx_delete_texture(i->images.exit);
	mlx_close_window(i->mlx);
	if (i->mlx)
		mlx_terminate(i->mlx);
	exit(1);
}

void	map_init(t_includes_t *i)
{
	i->mlx = mlx_init((i->width + 1) * 128, (i->len + 1) * 128, "MLX42", false);
	if (!i->mlx)
		error(i);
	set_images(i);
	mlx_key_hook(i->mlx, &create_hooks, i);
	mlx_close_hook(i->mlx, &ft_exit, i);
	mlx_loop(i->mlx);
}

void	add_layout(t_includes_t *i)
{
	int	x;
	int	y;

	texture_to_image(i);
	y = 0;
	while (i->map[y])
	{
		x = 0;
		while (i->map[y][x])
		{
			if (i->map[y][x] == 67)
				mlx_image_to_window(i->mlx, i->collectible, 128 * x, 128 * y);
			else if (i->map[y][x] == 80)
				mlx_image_to_window(i->mlx, i->player, 128 * x, 128 * y);
			else if (i->map[y][x] == 69)
				mlx_image_to_window(i->mlx, i->exit, 128 * x, 128 * y);
			x++;
		}
		y++;
	}
}

void	set_images(t_includes_t *i)
{
	mlx_image_t	*back;
	mlx_image_t	*wall;
	int			x;
	int			y;

	y = 0;
	load_textures(&i->images);
	back = mlx_new_image(i->mlx, i->width * 128, i->len * 128);
	wall = mlx_new_image(i->mlx, i->width * 128, i->len * 128);
	back = mlx_texture_to_image(i->mlx, i->images.background);
	wall = mlx_texture_to_image(i->mlx, i->images.wall);
	while (i->map[y])
	{
		x = 0;
		while (i->map[y][x])
		{
			if (i->map[y][x] == '1')
				mlx_image_to_window(i->mlx, wall, 128 * x, 128 * y);
			else
				mlx_image_to_window(i->mlx, back, 128 * x, 128 * y);
			x++;
		}
		y++;
	}
	add_layout(i);
}
