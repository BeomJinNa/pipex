/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_argv_to_have_heredoc.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 23:14:55 by bena              #+#    #+#             */
/*   Updated: 2023/06/29 23:43:08 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "m_heredoc.h"

static char	*create_heredoc(char const *s1, char const *s2);

int	convert_argv_to_have_heredoc(char **av, int *flag)
{
	char	*heredoc;

	*flag = 0;
	heredoc = create_heredoc(av[1], av[2]);
	if (heredoc == NULL)
		return (-1);
	av[1] = HEREDOC_FILENAME;
	av[2] = heredoc;
	*flag = 1;
	return (0);
}

static char	*create_heredoc(char const *s1, char const *s2)
{
	char	*str;
	char	*ptr_from;
	char	*ptr_to;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (str == NULL)
		return (NULL);
	ptr_to = str;
	ptr_from = (char *)s1;
	while (*ptr_from)
		*ptr_to++ = *ptr_from++;
	*ptr_to++ = ' ';
	ptr_from = (char *)s2;
	while (*ptr_from)
		*ptr_to++ = *ptr_from++;
	*ptr_to = '\0';
	return (str);
}
