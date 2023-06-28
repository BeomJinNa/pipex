/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:40:19 by bena              #+#    #+#             */
/*   Updated: 2023/06/28 12:36:12 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "s_data.h"

int	clean_malloc(t_data *data)
{
	free(data->path);
	return (-1);
}

int	clean_mallocs(t_data *data)
{
	free(data->path);
	free(data->pid);
	return (-1);
}

int	clean_infile(t_data *data)
{
	free(data->path);
	free(data->pid);
	close(data->infile);
	return (-1);
}

int	clean_inout(t_data *data)
{
	free(data->path);
	free(data->pid);
	close(data->infile);
	close(data->outfile);
	return (-1);
}

int	clean_all(t_data *data)
{
	int	i;

	free(data->path);
	free(data->pid);
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
