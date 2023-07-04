/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 22:21:21 by bena              #+#    #+#             */
/*   Updated: 2023/07/04 09:57:03 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_line_not_equal_to_limiter(char *line, const char *lt,
				const size_t ltsize);

void	here_doc(const char *limiter)
{
	char			*line;
	const size_t	lsize = ft_strlen(limiter);

	line = get_next_line(0);
	while (line != NULL && is_line_not_equal_to_limiter(line, limiter, lsize))
	{
		ft_putstr_fd(line, 1);
		free(line);
		line = get_next_line(0);
	}
	if (line != NULL)
		free(line);
	exit(0);
}

static int	is_line_not_equal_to_limiter(char *line, const char *lt,
		const size_t ltsize)
{
	return (!(ft_strlen(line) == ltsize + 1
			&& ft_strncmp(line, (char *)lt, ltsize) == 0));
}
