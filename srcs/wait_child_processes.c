/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_child_processes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:34:21 by bena              #+#    #+#             */
/*   Updated: 2023/06/29 11:11:23 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "s_data.h"

void	wait_child_processes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_cmds)
	{
		waitpid(data->pid[i], NULL, 0);
		i++;
	}
}
