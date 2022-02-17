/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <ahjadani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:30:00 by ahjadani          #+#    #+#             */
/*   Updated: 2022/02/17 10:35:52 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_data
{
    int bits;
    int s_pid;
    char c;
} t_data;


void ft_header_server(void);
void ft_header_client(void);
void	ft_putnbr(int n);

#endif