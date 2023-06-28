/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:20:07 by bena              #+#    #+#             */
/*   Updated: 2023/06/28 20:15:12 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "fileio.h"
#include "clean.h"
#include "pipe.h"

char	*get_path(char **ep);

int	init_pipex(t_data *data, int ac, char **av, char **ep)
{
	data->number_of_cmds = ac - 3;
	data->cmds = &av[2];
	data->ep = ep;
	data->path = get_path(ep);
	if (data->path == NULL)
		return (-1);
	data->pid = (pid_t *)malloc(sizeof(pid_t) * data->number_of_cmds);
	if (data->pid == NULL)
		return (-1);
	if (open_infile(&data->infile, av[1]))
		return (clean_malloc(data));
	if (open_outfile(&data->outfile, av[ac - 1]))
		return (clean_infile(data));
	data->pipe = create_pipes(data->number_of_cmds - 1);
	if (data->pipe == NULL)
		return (clean_inout(data));
	return (0);
}
