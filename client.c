/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyoo <yoyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 19:51:14 by yoyoo             #+#    #+#             */
/*   Updated: 2021/08/21 21:33:29 by yoyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		send(int pid, char *msg)
{
	char	idx;

	while (*msg)
	{
		idx = 0;
		while (idx < 8)
		{
			if ((*msg >> (7 - idx)) % 2)
				ft_kill(pid, SIGUSR1, 'k');
			else
				ft_kill(pid, SIGUSR2, 'k');
			idx++;
			usleep(100);
		}
		msg++;
	}
	return (1);
}


int		main(int argc, char *argv[])
{
	int pid;

	if (argc != 3)
	{
		ft_putstr_fd(" Usage : ./client pid message\n", 1);
		return (1);
	}
	else
	{
		pid = ft_atoi(argv[1]);
		ft_kill(pid, 0, 'p');
		send(pid, argv[2]);
	}
	return (0);
}

