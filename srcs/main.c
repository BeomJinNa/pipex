/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:38:49 by bena              #+#    #+#             */
/*   Updated: 2023/06/26 23:31:17 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"

int			open_infile(int *fd, char **av);
int			get_through_pipe(int *infile, char **av, int number_of_exec);
static int	pipex(int ac, char **av);
static int	pipex_bonus(int ac, char **av);
static int	return_error(void);

int	main(int ac, char **av)
{
	if (ft_strncmp("here_doc", av[1], 9))
		if (pipex(ac, av))
			return (return_error);
	else
		if (pipex_bonus(ac, av))
			return (return_error);
	return (0);
}

static int	pipex(int ac, char **av)
{
	int	infile;

	if (open_infile(&infile, av))
		return (-1);
	if (get_through_pipe(&infile, &av[1], ac - 3))
	{
		close(infile);
		return (-1);
	}
	close(infile);
	return (0);
}

static int	pipex_bonus(int ac, char **av)
{
	return (0);
}

static int	return_error(void)
{
	perror("Error");
	return (-1);
}
