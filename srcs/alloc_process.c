/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:45:34 by bena              #+#    #+#             */
/*   Updated: 2023/06/29 18:42:25 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "s_data.h"

char		*get_excutable_path(char *path, char *command);
static int	run_process(t_data *data, int index);
static void	init_process(t_data *data, int index);
static void	close_unused_resources(t_data *data, int index);
static void	terminate_current_process(t_data *data, int index);

int	alloc_process(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->number_of_cmds)
	{
		data->pid[i] = run_process(data, i);
		if (data->pid[i] == -1)
			return (-1);
		i++;
	}
	return (0);
}

static int	run_process(t_data *data, int index)
{
	char	*path;
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid > 0)
		return (pid);
	init_process(data, index);
	path = get_excutable_path(data->path, data->cmds[index][0]);
	if (path == NULL)
		terminate_current_process(data, index);
	execve(path, data->cmds[index], data->ep);
	free(path);
	terminate_current_process(data, index);
	return (0);
}

static void	init_process(t_data *data, int index)
{
	if (index == 0)
		dup2(data->infile, 0);
	else
		dup2(data->pipe[index - 1][0], 0);
	if (index == data->number_of_cmds - 1)
		dup2(data->outfile, 1);
	else
		dup2(data->pipe[index][1], 1);
	close_unused_resources(data, index);
}

static void	close_unused_resources(t_data *data, int index)
{
	int	i;

	free(data->pid);
	i = 0;
	while (i < data->number_of_pipes)
	{
		if (i != index - 1)
			close(data->pipe[i][0]);
		if (i != index)
			close(data->pipe[i][1]);
		i++;
	}
	if (index != 0)
		close(data->infile);
	if (index != data->number_of_cmds - 1)
		close(data->outfile);
}

static void	terminate_current_process(t_data *data, int index)
{
	if (index != 0)
		close(data->pipe[index - 1][0]);
	if (index < data->number_of_cmds - 1)
		close(data->pipe[index][1]);
	if (index == 0)
		close(data->infile);
	if (index == data->number_of_cmds - 1)
		close(data->outfile);
	free(data->pipe);
	exit(1);
}
