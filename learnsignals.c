/* ************************************************************************************************ */
/*                                                                                                  */
/*                                                        :::   ::::::::   ::::::::  :::::::::::    */
/*   learnsignals.c                                    :+:+:  :+:    :+: :+:    :+: :+:     :+:     */
/*                                                      +:+         +:+        +:+        +:+       */
/*   By: ahjadani <ahjadani@student.1337.ma>           +#+      +#++:      +#++:        +#+         */
/*                                                    +#+         +#+        +#+      +#+           */
/*   Created: 2022/02/13 19:04:37 by ahjadani        #+#  #+#    #+# #+#    #+#     #+#             */
/*   Updated: 2022/02/13 19:04:37 by ahjadani     ####### ########   ########      ###.ma           */
/*                                                                                                  */
/* ************************************************************************************************ */


#include "minitalk.h"

void handle_sig(int sig/*, siginfo_t *info , void *other*/)
{
	printf("sig: %d\n", sig);
}

int main()
{
	ft_header_server();
	struct sigaction sgn;
	printf("The PID is: %d\n", getpid());	
	// sgn.sa_sigaction = handle_sig;
	// signal(SIGQUIT, SIG_IGN);
	// signal(SIGTSTP, SIG_IGN);
	signal(SIGINT, handle_sig);
	while (pause());
}