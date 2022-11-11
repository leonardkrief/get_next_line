/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:24:43 by leonardkrie       #+#    #+#             */
/*   Updated: 2022/10/03 20:12:35 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i++])
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	join = malloc(sizeof(*join) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		join[j++] = s1[i++];
	i = 0;
	while (s2[i])
		join[j++] = s2[i++];
	join[j] = '\0';
	return (join);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		size_src;
	char	*copy;

	if (!src)
		return (NULL);
	size_src = ft_strlen(src);
	copy = malloc(sizeof(*copy) * (size_src + 1));
	if (copy == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (i < size_src)
		{
			copy[i] = src[i];
			i++;
		}
		copy[i] = '\0';
	}
	return (copy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	i;
	char	*dst;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	i = 0;
	while (i < len && start + i < len_s)
		i++;
	dst = malloc(sizeof(*dst) * (i + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len && start + i < len_s)
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
