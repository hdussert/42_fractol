/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 10:31:57 by hdussert          #+#    #+#             */
/*   Updated: 2018/04/29 11:46:28 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_init(int fd, char **line)
{
	char	buff[1];

	if (fd < 0 || line == NULL || read(fd, buff, 0) == -1 || BUFF_SIZE <= 0)
		return (-1);
	return (1);
}

void	*ft_strjoinclean(char *s1, char *s2)
{
	unsigned long	len;
	char			*str;
	unsigned long	i;
	unsigned long	j;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	free(s1);
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (str);
}

void	*ft_read(int fd)
{
	char		buff[BUFF_SIZE + 1];
	int			ret;
	char		*tmp;

	ret = read(fd, buff, BUFF_SIZE);
	if (ret == 0)
		return (NULL);
	tmp = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, BUFF_SIZE);
	while (ret > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoinclean(tmp, buff);
		ret = read(fd, buff, BUFF_SIZE);
	}
	return (tmp);
}

void	*ft_strsubclean(char *dst, char *src, unsigned int start, size_t len)
{
	char			*str;
	unsigned long	i;

	if (!src || len == 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	i = 0;
	while (i < len)
	{
		str[i] = src[start + i];
		if (src[start + i] == '\0')
			break ;
		i++;
	}
	if (dst)
	{
		free(dst);
		dst = NULL;
	}
	return (str);
}

int		get_next_line(int const fd, char **line)
{
	static char		*rest = NULL;
	unsigned long	i;

	if (ft_init(fd, line) == -1)
		return (-1);
	if (rest == NULL)
		rest = ft_read(fd);
	if (rest == NULL)
		return (0);
	i = 0;
	while (rest[i] != '\n' && rest[i] != '\0')
		i++;
	*line = ft_strsub(rest, 0, i);
	if (rest[i] == '\0' || i == ft_strlen(rest) - 1)
	{
		if (rest)
			free(rest);
		rest = NULL;
	}
	else
		rest = ft_strsubclean(rest, rest, i + 1, ft_strlen(rest) - i);
	return (1);
}
