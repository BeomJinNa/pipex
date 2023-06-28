/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_excutable_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:43:54 by bena              #+#    #+#             */
/*   Updated: 2023/06/28 17:46:42 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static char	*remove_matrix(char **matrix);

char	*get_excutable_path(char *path, char *command)
{
	char	**path_arr;
	char	**ptr;
	char	*output;

	path_arr = ft_split(path + 5, ':');
	if (path_arr == NULL)
		return (NULL);
	ptr = path_arr;
	while (*ptr != NULL)
	{
		output = ft_strjoin(*ptr, command);
		if (output == NULL)
			return (remove_matrix(path_arr));
		if (access(*ptr, F_OK | X_OK) == 0)
		{
			free(output);
			output = ft_strdup(*ptr);
			remove_matrix(path_arr);
			return (output);
		}
		ptr++;
	}
	return (remove_matrix(path_arr));
}

static char	*remove_matrix(char **matrix)
{
	char	**ptr;

	ptr = matrix;
	if (ptr != NULL)
	{
		while (*ptr != NULL)
		{
			free(*ptr);
			ptr++;
		}
		free(matrix);
	}
	return (NULL);
}
