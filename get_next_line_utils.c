/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:21:51 by lkrief            #+#    #+#             */
/*   Updated: 2022/11/13 07:43:15 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_belongs(const char *set, char s)
{
	int	i;

	if (!set)
		return (0);
	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

void	ft_reset(char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	while (buff[i])
		buff[j++] = buff[i++];
	buff[j] = '\0';
	if (j == 0)
		buff[BUFFER_SIZE + 1] = 1;
}

char	*ft_strdup(char *src)
{
	int		i;
	int		size_src;
	char	*copy;

	if (!src)
		return (NULL);
	size_src = ft_strlen(src);
	copy = malloc(sizeof(*copy) * (size_src + 2));
	if (!copy)
		return (NULL);
	i = -1;
	while (++i < size_src)
		copy[i] = src[i];
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char const *res, char const *buff)
{
	size_t	i;
	size_t	j;
	char	*join;

	if (buff[0] == 0)
		return (NULL);
	if (res == NULL)
		return (ft_strdup((char *)buff));
	join = malloc(sizeof(*join) * (ft_strlen(res) + ft_strlen(buff) + 1));
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	while (res[i])
		join[j++] = res[i++];
	i = 0;
	while (buff[i] && buff[i] != '\n')
		join[j++] = buff[i++];
	if (buff[i] == '\n')
	{
		join[j++] = '\n';
		join[j] = '\0';
	}
	return (join);
}