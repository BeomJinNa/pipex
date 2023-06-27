/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileio.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:04:10 by bena              #+#    #+#             */
/*   Updated: 2023/06/27 20:04:32 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEIO_H
# define FILEIO_H

int	open_infile(int *fd, char *path);
int	open_outfile(int *fd, char *path);
#endif
