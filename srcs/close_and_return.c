/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_and_return.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:40:19 by bena              #+#    #+#             */
/*   Updated: 2023/06/27 20:49:10 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	close_one(int infile)
{
	close(infile);
	return (-1);
}

int	close_two(int infile, int outfile)
{
	close(infile);
	close(outfile);
	return (-1);
}
