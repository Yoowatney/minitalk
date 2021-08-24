/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyoo <yoyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 23:04:47 by yoyoo             #+#    #+#             */
/*   Updated: 2021/08/24 23:28:55 by yoyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include "../libft/libft.h"

typedef struct s_buf
{
	unsigned char		c;
	char				i;
}				t_buf;

void	ft_kill(int pid, int sig, char c);

#endif
