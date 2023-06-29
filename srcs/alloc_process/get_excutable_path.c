/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_excutable_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:43:54 by bena              #+#    #+#             */
/*   Updated: 2023/06/29 14:35:47 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static char	*remove_matrix(char **matrix);
static char	*get_joined_path(char *str, char *suffix);

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
		output = get_joined_path(*ptr, command);
		if (output == NULL)
			return (remove_matrix(path_arr));
		if (access(output, F_OK | X_OK) == 0)
		{
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

static char	*get_joined_path(char *str, char *suffix)
{
	char	*output;
	char	*temp;

	temp = NULL;
	if (str[ft_strlen(str) - 1] != '/')
	{
		temp = ft_strjoin(str, "/");
		if (temp == NULL)
			return (NULL);
		output = ft_strjoin(temp, suffix);
	}
	else
		output = ft_strjoin(str, suffix);
	if (temp != NULL)
		free (temp);
	return (output);
}
