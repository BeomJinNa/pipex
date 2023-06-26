/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_infile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:51:53 by bena              #+#    #+#             */
/*   Updated: 2023/06/26 23:10:19 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	open_infile(int *fd, char **av)
{
	if (access(av[1], F_OK | R_OK))
	{
		perror("Error");
		return (-1);
	}
	*input_file = open(av[1], O_RDONLY);
	if (input_file == -1)
	{
		perror("Error");
		return (-1);
	}
	return (0);
}
