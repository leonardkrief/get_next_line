/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:12:39 by lkrief            #+#    #+#             */
/*   Updated: 2022/11/13 16:04:39 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	aux(char **res, char *buff)
{
	char	*tmp;

	tmp = *res;
	if (*res == NULL)
		*res = ft_strdup(buff);
	else
		*res = ft_strjoin(*res, buff);
	if (tmp)
		free(tmp);
	/*
	tmp = *res;
	if (buff[BUFFER_SIZE + 1] == 0)
	{
		if (*res == NULL)
			*res = ft_strdup(buff);
		else
			*res = ft_strjoin(*res, buff);
	}
	if (tmp)
	free(tmp);
	*/
}

char	*one_line(char *buff, int fd)
{
	int		i;
	int		ret;
	char	*res;

	res = NULL;
	ret = read(fd, buff, BUFFER_SIZE);
	while (!ft_belongs(buff, '\n') && ret)
	{
		buff[ret] = '\0';
		aux(&res, buff);
		ret = read(fd, buff, BUFFER_SIZE);
	}
	if (buff[0])
	{
		buff[ret] = '\0';
		aux(&res, buff);
	}
	i = 0;
	while (res && res[i] && res[i] != '\n')
		i++;
	if (res && res[i] == '\n')
		res[i + 1] = '\0';
	ft_reset(buff);
	return (res);
}

char *get_next_line(fd)
{
	static char	buff[BUFFER_SIZE + 1];

	if (fd == -1)
		return (NULL);
	buff[BUFFER_SIZE] = '\0';
	return (one_line(buff, fd));
}