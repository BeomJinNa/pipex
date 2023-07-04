/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:38:49 by bena              #+#    #+#             */
/*   Updated: 2023/07/04 11:29:26 by bena             ###   ########.fr       */
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
int			convert_argv_to_have_heredoc(char **av, int *flag);
static int	pipex(int ac, char **av, char **ep);
static int	free_heredoc(t_data *data, char **av);
static int	return_error(void);
static int	print_usage(void);

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
				return (print_usage());
		}
		else
		{
			if (ac >= 6)
				if (pipex(ac, av, ep))
					return (return_error());
			if (ac < 6)
				return (print_usage());
		}
	}
	else
		return (print_usage());
	return (0);
}

static int	pipex(int ac, char **av, char **ep)
{
	t_data	data;

	if (ft_strncmp("here_doc", av[1], 9))
		if (convert_argv_to_have_heredoc(av, &data.heredoc))
			return (-1);
	if (init_pipex(&data, ac, av, ep))
		return (free_heredoc(&data, av));
	if (alloc_process(&data))
	{
		free_heredoc(&data, av);
		return (clean_all(&data));
	}
	remove_pipes(data.pipe, data.number_of_cmds);
	if (data.heredoc == 0)
		close(data.infile);
	close(data.outfile);
	wait_child_processes(&data);
	free(data.pid);
	free_heredoc(&data, av);
	return (0);
}

static int	free_heredoc(t_data *data, char **av)
{
	if (data->heredoc)
		free(av[2]);
	return (-1);
}

static int	return_error(void)
{
	perror("Error");
	return (1);
}

static int	print_usage(void)
{
	ft_putstr_fd("Usage: ./pipex ", 2);
	ft_putstr_fd("{<infile> or \"here_doc\" LIMITER} ", 2);
	ft_putstr_fd("<command1> ", 2);
	ft_putstr_fd("<command2> ", 2);
	ft_putstr_fd("... ", 2);
	ft_putstr_fd("<outfile>\n", 2);
	return (1);
}
