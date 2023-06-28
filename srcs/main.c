/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:38:49 by bena              #+#    #+#             */
/*   Updated: 2023/06/28 12:57:51 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include "s_data.h"
#include "pipe.h"

int			init_pipex(t_data *data, int ac, char **av, char **ep);
static int	pipex(int ac, char **av, char **ep);
static int	pipex_bonus(int ac, char **av, char **ep);
static int	return_error(void);

int	main(int ac, char **av, char **ep)
{
	if (ft_strncmp("here_doc", av[1], 9))
		if (pipex(ac, av, ep))
			return (return_error);
	else
		if (pipex_bonus(ac, av, ep))
			return (return_error);
	return (0);
}

static int	pipex(int ac, char **av, char **ep)
{
	t_data	data;

	if (init_pipex(&data, ac, av, ep))
		return (-1);
	if (alloc_process(&data))
		return (close_all(&data));
	wait_child_processes(&data);
	remove_pipes(data.pipe, number_of_cmds);
	close(data.infile);
	close(data.outfile);
	free(data.pid);
	free(data.path);
	return (0);
}

static int	pipex_bonus(int ac, char **av, char **ep)
{
	return (0);
}

static int	return_error(void)
{
	perror("Error");
	return (-1);
}
