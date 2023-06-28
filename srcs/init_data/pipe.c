/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:19:29 by bena              #+#    #+#             */
/*   Updated: 2023/06/28 17:55:39 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	(*remove_pipes(int (*pipe)[2], int index))[2];

int	(*create_pipes(int number_of_pipes))[2]
{
	int	(*output)[2];
	int	i;

	output = (int (*)[2])malloc(sizeof(int [2]) * number_of_pipes);
	if (output == NULL)
		return (NULL);
	i = -1;
	while (++i < number_of_pipes)
		if (pipe(output[i]))
			return (remove_pipes(output, i));
	return (output);
}

int	(*remove_pipes(int (*pipe)[2], int index))[2]
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