/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:15:47 by aez-zaou          #+#    #+#             */
/*   Updated: 2020/11/08 19:12:20 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 100

int		get_next_line(int fd, char **line);
int		check(char *buf);
void	my_bzero(void *s, size_t n);
void	*my_calloc(size_t count, size_t size);
char	*my_substr(char *s, unsigned int start, size_t len, int a);
size_t	my_strlen(const char *tab);
char	*my_strjoin(char *s1, char *s2);
int		f_u_moul(char **save, char **line, int fd, char **buf);
int		helper(char **line, char **save);

#endif
