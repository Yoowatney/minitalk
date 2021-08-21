/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyoo <yoyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 02:52:35 by yoyoo             #+#    #+#             */
/*   Updated: 2021/08/21 21:20:11 by yoyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../libft/libft.h"

typedef struct	s_buf{
	unsigned char		c;
	char				i;
	int					num;
}				t_buf;

void	ft_kill(int pid, int sig, char c);
