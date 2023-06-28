/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_outfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:51:53 by bena              #+#    #+#             */
/*   Updated: 2023/06/28 17:51:00 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	open_outfile(int *fd, char *path)
{
	if (access(path, F_OK | W_OK))
		return (-1);
	*fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*fd == -1)
		return (-1);
	return (0);
}
