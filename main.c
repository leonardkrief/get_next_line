/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:24:40 by leonardkrie       #+#    #+#             */
/*   Updated: 2022/11/13 08:26:58 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

int	main(void)
{
	int	fd;
	char *tt;

	fd = open("./multiple_line_with_nl", O_RDONLY);
	
	tt = get_next_line(fd);
	printf("%s", tt);
	free(tt);
	tt = get_next_line(fd);
	printf("%s", tt);
	free(tt);
	tt = get_next_line(fd);
	printf("%s", tt);
	free(tt);
	tt = get_next_line(fd);
	printf("%s", tt);
	free(tt);
	tt = get_next_line(fd);
	printf("%s", tt);
	free(tt);
	tt = get_next_line(fd);
	printf("%s", tt);
	free(tt);


	

	// printf("%s", get_next_line(fd));
	close(fd);
}
