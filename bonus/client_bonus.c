/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyoo <yoyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 19:51:14 by yoyoo             #+#    #+#             */
/*   Updated: 2021/08/22 01:08:02 by yoyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int		send(int pid, char *msg)
{
	char	idx;

	while (*msg)
	{
		idx = 0;
		while (idx < 8)
		{
			if (((unsigned char)*msg >> (7 - idx)) % 2 == 1)
				ft_kill(pid, SIGUSR1, 'k');
			else
				ft_kill(pid, SIGUSR2, 'k');
			idx++;
			usleep(50);
		}
		msg++;
	}
	return (1);
}

void	send_num(int pid, unsigned int num)
{
	int idx;

	idx = 8;
	while (idx)
	{
		if ((num >> 7) % 2 == 1)
		{
			ft_kill(pid, SIGUSR1, 'k');
		}
		else
			ft_kill(pid, SIGUSR2, 'k');
		usleep(100);
		num = num << 1;
		idx--;
	}
}

void	success(int sig)
{
	sig++;
	ft_putstr_fd("\nReceived a signal\n", 1);
}


int		main(int argc, char *argv[])
{
	int pid;

	signal(SIGUSR1, success);
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
		send_num(pid, 127);
	}
	return (0);
}

