/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_and_return.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:40:19 by bena              #+#    #+#             */
/*   Updated: 2023/06/27 22:08:38 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "s_data.h"

int	clean_pid_and_infile(t_data *data)
{
	free(data.pid);
	close(infile);
	return (-1);
}

int	clean_pid_and_inout(t_data *data)
{
	free(data.pid);
	close(infile);
	close(outfile);
	return (-1);
}

int	clean_all(t_data *data)
{
	int	i;

	free(data.pid);
	close(data->infile);
	close(data->outfile);
	i = 0;
	while (i < data->number_of_cmds)
	{
		close(data->pipe[i][0]);
		close(data->pipe[i][1]);
		i++;
	}
	return (-1);
}
