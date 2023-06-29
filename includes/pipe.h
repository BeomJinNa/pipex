/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:05:25 by bena              #+#    #+#             */
/*   Updated: 2023/06/29 11:19:13 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

typedef int	t_pipe[2];

t_pipe	*create_pipes(int number_of_pipes);
t_pipe	*remove_pipes(int (*pipe)[2], int index);
#endif
