/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:20:47 by lkrief            #+#    #+#             */
/*   Updated: 2022/11/29 01:35:22 by lkrief           ###   ########.fr       */
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
size_t	ft_strlen_gnl(const char *s);
int		ft_belongs_gnl(const char *set, char s);
void	ft_reset_gnl(char *buff);
char	*ft_strjoin_gnl(char const *res, char const *buff);

//get_next_line.c
void	aux_gnl(char **res, char *buff);
char	*one_line_gnl(char *buff, int fd);
char	*get_next_line(int fd);

#endif