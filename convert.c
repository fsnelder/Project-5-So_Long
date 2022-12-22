/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fsnelder <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/23 12:10:02 by fsnelder      #+#    #+#                 */
/*   Updated: 2022/06/02 13:28:52 by fsnelder      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	load_textures(t_images_t *i)
{
	i->background = mlx_load_png("images/background.png");
	i->wall = mlx_load_png("images/wall.png");
	i->exit = mlx_load_png("images/exit.png");
	i->player = mlx_load_png("images/player.png");
	i->collectible = mlx_load_png("images/collectible.png");
}

t_includes_t	texture_to_image(t_includes_t *i)
{
	i->collectible = mlx_new_image(i->mlx, i->width * 128, i->len * 128);
	i->collectible = mlx_texture_to_image(i->mlx, i->images.collectible);
	i->player = mlx_new_image(i->mlx, i->width * 128, i->len * 128);
	i->player = mlx_texture_to_image(i->mlx, i->images.player);
	i->exit = mlx_new_image(i->mlx, i->width * 128, i->len * 128);
	i->exit = mlx_texture_to_image(i->mlx, i->images.exit);
	return (*i);
}
