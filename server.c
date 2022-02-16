/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <ahjadani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:30:06 by ahjadani          #+#    #+#             */
/*   Updated: 2022/02/16 20:20:23 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data g_data;

void signal_handler(int sig, siginfo_t *info, void *p)
{
    (void)p;
    (void)info;
    //printf("si_pid %d\n", info->si_pid);
    // if (info->si_uid != 0)
    // {
    //     g_data.bits = 0;
    //     g_data.c = 0;
    // }
    sig -= SIGUSR1;
    g_data.bits = g_data.bits << 1 | sig;
    g_data.c++;
    if (g_data.c == 8)
    {
        write(1, &g_data.bits, 1);
        g_data.bits = 0;
        g_data.c = 0;
    }
    
}

int main(void)
{
    struct sigaction sgn;
    g_data.bits = 0;
    g_data.c = 0;
    ft_header_server();
    printf("The PID is: %d\n", getpid());
    sgn.sa_sigaction = &signal_handler;
    sgn.sa_flags = SA_SIGINFO;
    
    sigaction(SIGUSR1, &sgn, NULL);
    sigaction(SIGUSR2, &sgn, NULL);
    while(pause());
}
