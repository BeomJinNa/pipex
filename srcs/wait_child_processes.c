/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_child_processes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:34:21 by bena              #+#    #+#             */
/*   Updated: 2023/06/28 23:29:23 by bena             ###   ########.fr       */
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
		wait(NULL);
		i++;
	}
}
