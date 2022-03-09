/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:35:49 by nspeedy           #+#    #+#             */
/*   Updated: 2022/02/23 13:46:50 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	print_pid(void)
{
	ft_printf("Server operational\n");
	ft_printf("Server pid is: %d\n", getpid());
	ft_printf("Open client in a different terminal\n");
	ft_printf("Run the client with ./client <PID> <message>\n");
}

static void	handle(int sig, siginfo_t *cl_pid, void *horse)
{
	static unsigned char	byte;
	static int				shift;

	(void)horse;
	byte <<= 1;
	shift++;
	if (sig == SIGUSR1)
		byte++;
	if (shift == 8)
	{
		write(1, &byte, 1);
		if (!byte)
		{
			kill(cl_pid->si_pid, SIGUSR1);
			ft_putchar_fd('\n', 1);
		}
		byte = 0;
		shift = 0;
	}
}

int	main(void)
{
	struct sigaction	sdata;

	sigemptyset(&sdata.sa_mask);
	sdata.sa_flags = SA_SIGINFO;
	sdata.sa_sigaction = &handle;
	print_pid();
	while (1)
	{
		sigaction(SIGUSR1, &sdata, 0);
		sigaction(SIGUSR2, &sdata, 0);
		pause();
	}
}
