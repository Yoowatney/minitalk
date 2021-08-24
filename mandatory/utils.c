/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyoo <yoyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 21:06:42 by yoyoo             #+#    #+#             */
/*   Updated: 2021/08/21 21:25:33 by yoyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_kill(int pid, int sig, char c)
{
	if (kill(pid, sig) == -1)
	{
		if (c == 'k')
			ft_putstr_fd("Kill error\n", 1);
		else if (c == 'p')
			ft_putstr_fd("Invalid PID\n", 1);
		exit(0);
	}
}
