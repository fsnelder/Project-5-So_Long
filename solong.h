/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solong.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fsnelder <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/23 12:11:01 by fsnelder      #+#    #+#                 */
/*   Updated: 2022/06/02 13:30:34 by fsnelder      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# include "libft.h"
# include "get_next_line.h"
# include "MLX42/MLX42.h"
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# include <fcntl.h>

typedef struct images {
	mlx_texture_t	*background;
	mlx_texture_t	*wall;
	mlx_texture_t	*collectible;
	mlx_texture_t	*player;
	mlx_texture_t	*exit;
}	t_images_t;

typedef struct includes {
	char		**map;
	int			width;
	int			len;
	int			xcoll;
	int			ycoll;
	int			collectcount;
	int			xexit;
	int			yexit;
	int			xstart;
	int			ystart;
	t_images_t	images;
	mlx_image_t	*player;
	mlx_image_t	*exit;
	mlx_image_t	*collectible;
	mlx_t		*mlx;
}		t_includes_t;

int				error(t_includes_t *i);
void			**free_string(char **i);
void			ft_count(void);

//various error checks
t_includes_t	overallcheck(t_includes_t *i);
int				check_mapwidth(t_includes_t *i);
int				check_maplen(t_includes_t *i);
void			check_edges(t_includes_t *i, int len, int width);
void			check_isvalid(t_includes_t *i, int width);
t_includes_t	check_collectibles(int len, int width, t_includes_t *i);
t_includes_t	check_exit(int len, int width, t_includes_t *i);
t_includes_t	check_start(int len, int width, t_includes_t *i);

//visualisation of the map
void			map_init(t_includes_t *i);
void			load_textures(t_images_t *i);
void			set_images(t_includes_t *i);
void			add_layout(t_includes_t *i);
t_includes_t	texture_to_image(t_includes_t *i);

//various keys and their corresponding action
void			create_hooks(mlx_key_data_t keydata, void *param);
void			ft_exit(void *param);

//rules of the game
int				rules(t_includes_t *i, int actioncode);
int				check_wall(t_includes_t *i, int actioncode);
void			remove_collectible(t_includes_t *i);
int				find_exit(t_includes_t *i);

#endif
