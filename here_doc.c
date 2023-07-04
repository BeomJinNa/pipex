/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 22:21:21 by bena              #+#    #+#             */
/*   Updated: 2023/06/29 23:43:45 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	here_doc(const char *limiter)
{
	char			*line;
	const size_t	limiter_size = ft_strlen(limiter);

	line = get_next_line(0);
	while (line != NULL && ft_strncmp(line, (char *)limiter, limiter_size + 1))
	{
		ft_putstr_fd(line, 1);
		free(line);
		line = get_next_line(0);
	}
	if (line != NULL)
		free(line);
	exit(0);
}
