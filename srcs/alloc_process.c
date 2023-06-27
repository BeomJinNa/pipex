/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:45:34 by bena              #+#    #+#             */
/*   Updated: 2023/06/27 23:55:26 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	run_process(t_data *data, int index);
static void	init_process(t_data *data, int index);

int	alloc_process(t_data *data)
{
	int		i;
	pid_t	pid;

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
	//이 부분에서 패스 검사 후 획득하기
	//main 함수에서 환경변수 얻어올 것
	//main 함수에서 path 환경변수 분석하기
	if (access("cmd", F_OK | X_OK))
		return (-1);
	*pid = fork(void);
	if (*pid < 0)
		return (-1);
	if (pid > 0)
		return (pid);
	init_process(data, index);
//	execve(path, cmd, envp)
}

static void	init_process(t_data *data, int index)
{
	int	i;

	if (index == 0)
		dup2(data->infile, 0);
	else
		dup2(data->pipe[index - 1][0], 0);
	if (index == data->number_of_cmds - 1)
		dup2(data->outfile, 1);
	else
		dup2(data->pipe[index][1], 1);
	free(pid);
	i = 0;
	while (i < data->number_of_cmds - 1)
	{
		if (i != index - 1)
			close(data->pipe[i][0]);
		if (i != index)
			close(data->pipe[i][1]);
		if (index != 0)
			close(data->infile);
		if (index != data->number_of_cmds)
			close(data->oufile);
	}
	free(pipe);
}
