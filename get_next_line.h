/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:20:47 by lkrief            #+#    #+#             */
/*   Updated: 2022/11/14 15:22:56 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

//get_next_line_utils.c
size_t	ft_strlen(const char *s);
int		ft_belongs(const char *set, char s);
void	ft_reset(char *buff);
char	*ft_strdup(char *src);
char	*ft_strjoin(char const *s1, char const *s2);

//get_next_line.c
char	*one_line(char *buff, int fd);
char	*get_next_line(int fd);

#endif