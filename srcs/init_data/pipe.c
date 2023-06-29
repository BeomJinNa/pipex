/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:19:29 by bena              #+#    #+#             */
/*   Updated: 2023/06/29 11:22:40 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "pipe.h"

t_pipe	*create_pipes(int number_of_pipes)
{
	int	(*output)[2];
	int	i;

	output = (t_pipe *)malloc(sizeof(t_pipe) * number_of_pipes);
	if (output == NULL)
		return (NULL);
	i = -1;
	while (++i < number_of_pipes)
		if (pipe(output[i]))
			return (remove_pipes(output, i));
	return (output);
}

t_pipe	*remove_pipes(t_pipe *pipe, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		close(pipe[i][0]);
		close(pipe[i][1]);
		i++;
	}
	free(pipe);
	return (NULL);
}
