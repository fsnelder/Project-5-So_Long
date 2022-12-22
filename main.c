/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fsnelder <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/23 12:09:48 by fsnelder      #+#    #+#                 */
/*   Updated: 2022/06/02 13:26:25 by fsnelder      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static char	*ft_strjoinandfree1(char *s1, char *s2)
{
	unsigned int	j;
	unsigned int	k;
	char			*s3;

	if (!s2)
		return (0);
	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s3 == 0)
		return (0);
	j = 0;
	k = 0;
	while (s1[j] != '\0')
	{
		s3[j] = s1[j];
		j++;
	}
	while (s2[k] != '\0')
	{
		s3[j + k] = s2[k];
		k++;
	}
	free(s1);
	s3[j + k] = '\0';
	return (s3);
}

void	**free_string(char **temp)
{
	int	j;

	j = 0;
	while (temp[j] != '\0')
	{
		free(temp[j]);
		j++;
	}
	free(temp);
	temp = NULL;
	return (0);
}

char	**create_map(char **argv, t_includes_t *i)
{
	int		fd;
	char	*line;
	char	*newlyread;

	line = NULL;
	newlyread = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error(i);
	line = get_next_line(fd);
	newlyread = ft_strdup(line);
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			newlyread = ft_strjoinandfree1(newlyread, line);
		free(line);
	}
	i->map = ft_split(newlyread, '\n');
	free(newlyread);
	return (i->map);
}

int	error(t_includes_t *i)
{
	if (i->map)
		free_string(i->map);
	write (2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_includes_t	i;

	if (argc != 2)
		error(&i);
	i.map = create_map(argv, &i);
	i = overallcheck(&i);
	map_init(&i);
	return (0);
}
