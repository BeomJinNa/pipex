/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_data.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:51:22 by bena              #+#    #+#             */
/*   Updated: 2023/06/27 20:03:58 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_DATA_H
# define S_DATA_H

typedef struct s_data
{
	int	infile;
	int	outfile;
	int	(*pipe)[2];
	int	number_of_cmds;
}	t_data;
#endif
