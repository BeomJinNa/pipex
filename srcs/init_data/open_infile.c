/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_infile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:51:53 by bena              #+#    #+#             */
/*   Updated: 2023/06/28 17:50:50 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	open_infile(int *fd, char *path)
{
	if (access(path, F_OK | R_OK))
		return (-1);
	*fd = open(path, O_RDONLY);
	if (*fd == -1)
		return (-1);
	return (0);
}
