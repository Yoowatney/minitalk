/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyoo <yoyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 23:40:48 by yoyoo             #+#    #+#             */
/*   Updated: 2021/08/21 22:30:14 by yoyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig)
{
	static t_buf buf;

	buf.c = buf.c << 1;
	buf.i++;
	if (sig == SIGUSR1)
		buf.c++;
	if (buf.i == 8)
	{
		write(1, &buf.c, 1);
		buf.c = 0;
		buf.i = 0;
	}
}

void		display_pid(void)
{
	ft_putstr_fd("Server PID :", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
}

int		main(void)
{
	struct sigaction	act;

	act.sa_handler = handler;
	act.sa_flags = 0;
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
