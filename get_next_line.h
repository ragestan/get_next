/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 23:17:48 by zbentalh          #+#    #+#             */
/*   Updated: 2022/10/24 23:22:37 by zbentalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

#ifndef BUFFER_ZISE
# define BUFFER_ZISE 1024
# endif

char    *get_next_line(int fd);
char    *line(int fd,char *str);
int		ft_strlen(char *a);
char	*ft_strjoin(char  *s1, char  *s2);
char	*ft_strchr( char *str, int c);
char	*ft_line(char *str);
char	*mzl(char *src);
#endif
