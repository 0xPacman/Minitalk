/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <ahjadani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:29:53 by ahjadani          #+#    #+#             */
/*   Updated: 2022/02/17 12:01:00 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(void)
{
	write(2, "🚫 Error!\n", 13);
	exit(1);
}

void	ft_msg(int sig)
{
	if (sig == SIGUSR1)
		write(1, "📩 Message recieved!\n", 24);
}

void	ft_send_bit(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1) 
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(600);
		i--;
	}
}

void	ft_send_str(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_send_bit(str[i], pid);
		i++;
	}
	ft_send_bit('\0', pid);
}

int	main(int argc, char *argv[])
{
	char	*str;
	int		pid;

	ft_header_client();
	signal(SIGUSR1, ft_msg);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (!pid)
			ft_error();
		str = argv[2];
		if (!str)
			ft_error();
		ft_send_str(str, pid);
	}
	else
	{
		write(2, "🚫 Error!\n", 13);
		write (1, "Usage: ./client [PID] [MESSAGE]\n", 33);
		exit(1);
	}
}
