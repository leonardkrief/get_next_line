/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:24:40 by leonardkrie       #+#    #+#             */
/*   Updated: 2022/10/03 06:29:16 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

int	main(void)
{
	int	fd;
	char *tt;
	char buf[BUFFER_SIZE];

	buf[BUFFER_SIZE - 1] = 0;

	fd = open("./test.txt", O_RDONLY);
	
	tt = get_next_line(fd);
	free(tt);
	tt = get_next_line(fd);
	free(tt);
	tt = get_next_line(fd);
	free(tt);
	tt = get_next_line(fd);
	free(tt);
	tt = get_next_line(fd);
	free(tt);
	tt = get_next_line(fd);
	free(tt);
	tt = get_next_line(fd);
	free(tt);
	tt = get_next_line(fd);
	free(tt);
		tt = get_next_line(fd);
	free(tt);


	

	// printf("%s", get_next_line(fd));
	close(fd);
}
