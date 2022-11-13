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
	*res = ft_strjoin(*res, buff);
	if (tmp)
		free(tmp);
}

char	*one_line(char *buff, int fd)
{
	int		ret;
	char	*res;

	res = NULL;
	ret = read(fd, buff, BUFFER_SIZE);
	while (buff[0] && !ft_belongs(buff, '\n') && ret)
	{
		buff[ret] = '\0';
		aux(&res, buff);
		buff[0] = 0;
		ret = read(fd, buff, BUFFER_SIZE);
	}
	if ((buff[0] && !buff[BUFFER_SIZE + 1]) || (BUFFER_SIZE == 1 && ret))
	{
		if (ret > 0)
			buff[ret] = '\0';
		aux(&res, buff);
		ft_reset(buff);
	}
	return (res);
}

char *get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];

	if (fd == -1 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (NULL);
	buff[BUFFER_SIZE] = '\0';
	return (one_line(buff, fd));
}