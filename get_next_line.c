/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:28:54 by zbentalh          #+#    #+#             */
/*   Updated: 2022/10/24 15:51:14 by zbentalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char    *line(int fd,char *str)
{
    char *buffer;
    int i;

    buffer = malloc(sizeof(char) * (BUFFER_ZISE + 1));
    if (buffer == NULL)
    {
        free(buffer);
        return (NULL);
    }
    i = 1;
    while (! ft_strchr(str,'\n') && i != 0)
    {
        i = read(fd, buffer, BUFFER_SIZE);
        if (i == -1)
        {
            free(buffer);
            return (NULL);
        }
        buffer[i]= '\0';
        str = ft_strjoin(str,buffer);
    }
    free(buffer);
    return(str);
}

char    *get_next_line(int fd)
{
    static char *next;
    char    *l;

    l = NULL;
    if (fd < 0 || BUFFER_ZISE <= 0)
        return (0);
    next = line(fd,next);
    if (next == NULL)
        return (NULL);
    l = ft_line(next);
    next = mzl(next);
    if(l[0] == '\0')
    {
        free(l);
        free(next);
        return(NULL);
    }
    return (l);
}