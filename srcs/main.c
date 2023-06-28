/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:38:49 by bena              #+#    #+#             */
/*   Updated: 2023/06/28 23:40:27 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "s_data.h"
#include "pipe.h"
#include "clean.h"

int			init_pipex(t_data *data, int ac, char **av, char **ep);
int			alloc_process(t_data *data);
void		wait_child_processes(t_data *data);
static int	pipex(int ac, char **av, char **ep);
static int	pipex_bonus(int ac, char **av, char **ep);
static int	return_error(void);
static void	print_usage(void);

int	main(int ac, char **av, char **ep)
{
	if (ac >= 2)
	{
		if (ft_strncmp("here_doc", av[1], 9))
		{
			if (ac >= 5)
				if (pipex(ac, av, ep))
					return (return_error());
			if (ac < 5)
				print_usage();
		}
		else
		{
			if (ac >= 6)
				if (pipex_bonus(ac, av, ep))
					return (return_error());
			if (ac < 6)
				print_usage();
		}
	}
	else
		print_usage();
	return (0);
}

static int	pipex(int ac, char **av, char **ep)
{
	t_data	data;

	if (init_pipex(&data, ac, av, ep))
		return (-1);
	if (alloc_process(&data))
		return (clean_all(&data));
	wait_child_processes(&data);
	remove_pipes(data.pipe, data.number_of_cmds);
	close(data.infile);
	close(data.outfile);
	free(data.pid);
	return (0);
}

static int	pipex_bonus(int ac, char **av, char **ep)
{
	(void)ac;
	(void)av;
	(void)ep;
	return (0);
}

static int	return_error(void)
{
	perror("Error");
	return (-1);
}

static void	print_usage(void)
{
	ft_printf("Usage: ./pipex %s %s %s %s %s\n",
		"{<infile> or \"here_doc\" LIMITER}",
		"<command1>",
		"<command2>",
		"...",
		"<outfile>");
}
