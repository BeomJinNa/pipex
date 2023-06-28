/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:01:08 by bena              #+#    #+#             */
/*   Updated: 2023/06/28 19:42:33 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "s_data.h"

char	*get_path(char **ep)
{
	char	**ptr;

	ptr = ep;
	while (*ptr != NULL)
	{
		if (ft_strncmp(*ptr, "PATH=", 5) == 0)
			return (*ptr);
		ptr++;
	}
	write(2, "The PATH environment variable could not be found.\n", 50);
	return (NULL);
}
