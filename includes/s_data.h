/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_data.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:51:22 by bena              #+#    #+#             */
/*   Updated: 2023/06/27 23:50:03 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_DATA_H
# define S_DATA_H

#include <unistd.h>

typedef struct s_data
{
	int		infile;
	int		outfile;
	int		(*pipe)[2];
	int		number_of_cmds;
	char	**cmds;
	pid_t	*pid;
	char	*path;
}			t_data;
#endif
