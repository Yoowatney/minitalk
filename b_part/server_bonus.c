/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyoo <yoyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 23:40:48 by yoyoo             #+#    #+#             */
/*   Updated: 2021/08/21 21:15:11 by yoyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static	t_buf	buf;

void	handler(int sig, siginfo_t *info, void *context)
{
	buf.c = buf.c << 1;
	buf.i++;

	(void)context;
	(void)info;
	if (sig == SIGUSR1)
		buf.c++;
	if (buf.i == 8)
	{
		if (buf.c == 127)
			ft_kill(info->si_pid, SIGUSR1, 'k');
		else
			write(1, &buf.c, 1);
		buf.i = 0;
		buf.c = 0;
	}
}

void		display_pid()
{
	ft_putstr_fd("Server PID :", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
}

int		main(void)
{
    struct sigaction	act;

	act.sa_sigaction = handler;
    act.sa_flags = SA_SIGINFO;
	display_pid();
	if (sigaction(SIGUSR1, &act, NULL) == -1)
	{
		ft_putstr_fd("Sigaction error\n", 1);
		exit(1);
	}
	if (sigaction(SIGUSR2, &act, NULL) == -1)
	{
		ft_putstr_fd("Sigaction error\n", 1);
		exit(1);
	}
	while (1)
		pause();
	return (0);
}
