/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fsnelder <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 13:33:22 by fsnelder      #+#    #+#                 */
/*   Updated: 2022/06/02 13:31:24 by fsnelder      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 20
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

void		*ft_calloc(size_t count, size_t size);
void		*ft_realloc(char *ptr, size_t size, size_t quant);
void		*ft_memmove_gnl(char *dst, char *src, size_t len);
size_t		ft_check_end(char *str);
void		ft_bzero(void *s, size_t n);
char		*ft_join_last_data(char *str_newline, char *s_buff);
char		*get_next_line(int fd);

#endif
