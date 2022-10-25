/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:33:19 by zbentalh          #+#    #+#             */
/*   Updated: 2022/10/24 23:17:07 by zbentalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strlen(char *a)
{
	int	i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		k;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	if(s1 == NULL)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	k = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc(k + 1);
	if (!dest)
		return (0);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = 0;
	free(s1);
	return (dest);
}
char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char) c)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == (char) c)
		return ((char *)str + i);
	return (0);
}

char	*ft_line(char *str)
{
	size_t	i;
	char	*dst;

	if(str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	dst = malloc(i + 2);
	if (!dst)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		dst[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*mzl(char *src)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	while (src[i] != '\n' && src[i] != '\0')
		i++;
	if (src[i] == '\0')
	{
		free(src);
		return (0);
	}
	str = malloc(ft_strlen(src) - i + 1);
	if (str == NULL)
		return (NULL);
	i = i + 1;
	j = 0;
	while (src[i] != '\0')
		str[j++] = src[i++];
	str[j] = '\0';
	free(src);
	return (str);
}
