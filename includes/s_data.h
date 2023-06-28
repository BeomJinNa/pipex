/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_data.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:51:22 by bena              #+#    #+#             */
/*   Updated: 2023/06/28 17:01:01 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_DATA_H
# define S_DATA_H

# include <unistd.h>

typedef struct s_data
{
	int		infile;
	int		outfile;
	int		(*pipe)[2];
	int		number_of_cmds;
	char	*path;
	char	**cmds;
	char	**ep;
	pid_t	*pid;
}			t_data;
#endif
