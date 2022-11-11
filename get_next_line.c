/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:24:40 by leonardkrie       #+#    #+#             */
/*   Updated: 2022/10/03 19:40:42 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_gnl(char *s, char *tmp)
{
	if (tmp)
		free(tmp);
	if (s)
		free(s);
}

char	*first_gnl(char *buff)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	res = NULL;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
	{
		res = malloc(sizeof(*res) * (i + 2));
		if (!res)
			return (NULL);
		j = -1;
		while (++j <= i)
			res[j] = buff[j];
		res[i + 1] = '\0';
		j = 0;
		while (i + 1 + j <= BUFFER_SIZE)
		{
			buff[j] = buff[i + 1 + j];
			j++;
		}
	}
	return (res);
}

char	*gnl_strjoin(char *res, char *buff)
{
	char	*s;
	char	*tmp;
	int		i;

	if (res == NULL)
		return (ft_strdup(buff));
	if (buff == NULL)
		return (res);
	else
	{
		i = 0;
		tmp = NULL;
		while (buff[i] && buff[i] != '\n')
			i++;
		s = res;
		if (!buff[i])
			res = ft_strjoin(res, buff);
		else
		{
			tmp = first_gnl(buff);
			res = ft_strjoin(res, tmp);
		}
		free_gnl(s, tmp);
	}
	return (res);
}

char	*get_next_line(int fd)
{
	int			ret;
	char		*res;
	char		*tmp;
	static char	buff[BUFFER_SIZE + 1];

	if (fd == -1)
		return (NULL);
	ret = BUFFER_SIZE;
	if (buff[0] == '\0')
		ret = read(fd, buff, BUFFER_SIZE);
	buff[ret] = '\0';
	res = NULL;
	tmp = first_gnl(buff);
	while (!tmp && ret && buff[0] != '\0')
	{
		res = gnl_strjoin(res, buff);
		ret = read(fd, buff, BUFFER_SIZE);
		buff[ret] = '\0';
		tmp = first_gnl(buff);
	}
	res = gnl_strjoin(res, tmp);
	if (tmp)
		free(tmp);
	return (res);
}
