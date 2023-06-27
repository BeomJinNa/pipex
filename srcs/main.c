/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:38:49 by bena              #+#    #+#             */
/*   Updated: 2023/06/27 20:51:31 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include "s_data.h"
#include "fileio.h"
#include "pipe.h"
#include "closes.h"

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
	t_data	data;

	data.number_of_cmds = ac - 3;
	if (open_infile(&data.infile, av[1]))
		return (-1);
	if (open_outfile(&data.outfile, av[ac - 1]))
		return (close_one(data.infile));
	data.pipe = create_pipes(data.number_of_cmds - 1);
	if (data.pipe == NULL)
		return (close_two(data.infile, data.outfile));
	alloc_process(&data);
	wait_child_processes(&data);
	remove_pipes(pipe);
	close(data.infile);
	close(data.outfile);
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
