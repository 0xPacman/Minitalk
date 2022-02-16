/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <ahjadani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:29:53 by ahjadani          #+#    #+#             */
/*   Updated: 2022/02/16 19:47:31 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_send_bit(char c, int pid)
{
    int i;
    i = 7;
    while(i >= 0)
    {
        if (c >> i & 1)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        usleep(600);
        i--;
    }
    
}

void ft_send_str(char *str, int pid)
{
    int i;
    i = 0;
    while(str[i])
    {
        ft_send_bit(str[i], pid);       
        i++;
    }
}

int main(int argc, char *argv[])
{
    char *str;
    int pid;

    if (argc == 3)
    {
        pid = atoi(argv[1]);
        if (!pid)
        {
            write(1, "Error!", 7);
            exit(1);
        }
        str = argv[2];
        if (!str)
        {
            write(1, "Error!", 7);
            exit(1);
        }
        ft_send_str(str, pid);
    }
    else
    {
        write(1, "Error!", 7);
        exit(1);
    }
    return (0);
}

// 'A' == 65
// 0100 0001

// SIGUSR2 SIGUSR1 SIGUSR2 SIGUSR2  SIGUSR2  SIGUSR2  SIGUSR2  SIGUSR1

// if (sig == SIGUSR1)
//     + 1
//     else
//     + 0