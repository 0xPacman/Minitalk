/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <ahjadani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:30:06 by ahjadani          #+#    #+#             */
/*   Updated: 2022/02/16 12:00:05 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int g_bits;
char g_c;

void signal_handler(int sig, siginfo_t *info, void *p)
{
    //write(1,"1", 1);
    // static int bits;
    // static int c;
    (void)p;
    //if ()
    if (sig == SIGUSR1)
        g_bits = g_bits << 1 | 1;
    if (sig == SIGUSR2)
        g_bits = g_bits << 1 | 0;
    g_c++;
    if (g_c == 8)
    {
        write(1, &g_bits, 1);
        g_bits = 0;
        g_c = 0;
    }
   // printf("siginfo %d\n", info->si_uid);
   // printf("sig %d\n", sig);
}

int main(void)
{
    struct sigaction sgn;
    g_bits = 0;
    g_c = 0;
    printf("The PID is: %d\n", getpid());
    sgn.sa_sigaction = &signal_handler;
    sigaction(SIGUSR1, &sgn, NULL);
    sigaction(SIGUSR2, &sgn, NULL);
    // kill(getpid(), SIGUSR1);
    // kill(getpid(), SIGUSR2);
    while(pause());
}
