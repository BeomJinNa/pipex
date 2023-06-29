/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:42:23 by bena              #+#    #+#             */
/*   Updated: 2023/06/29 18:39:39 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAN_H
# define CLEAN_H

# include "s_data.h"

int	clean_malloc(t_data *data);
int	clean_mallocs(t_data *data);
int	clean_infile(t_data *data);
int	clean_inout(t_data *data);
int	clean_all(t_data *data);
#endif
