/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 08:24:08 by nspeedy           #+#    #+#             */
/*   Updated: 2022/02/23 13:42:12 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* This function recieves a signal from the server after
message has been sent and recieved*/

static void	response(int sig)
{
	(void)sig;
	if (sig == SIGUSR1)
	{
		ft_printf("The server acknowledges you\n");
		exit(0);
	}
}

/* This function sends a char to the server. By bit shifting through
each char and sending SIGURSR1 if the current bit is 1(on) - (c >> shift & 1)
or SIGUSR2 if the bit is 0(off) then shift decreases and the next
bit is checked*/

static void	bit_send(int pid, char c)
{
	int	shift;

	shift = 7;
	while (shift >= 0)
	{
		if (c >> shift & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_printf("SIGUSR1 fail\n");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_printf("SIGUSR2 fail\n");
		}
		shift--;
		usleep(200);
	}
}

int	main(int ac, char *arg[])
{
	int					i;
	struct sigaction	cdata;

	cdata.sa_handler = &response;
	sigemptyset(&cdata.sa_mask);
	if (ac != 3)
	{
		ft_printf("Correct input ./client <server-pid> <message>\n");
		return (1);
	}
	i = 0;
	while (1)
	{
		sigaction(SIGUSR1, &cdata, 0);
		while (arg[2][i] != '\0')
		{
			bit_send(ft_atoi(arg[1]), arg[2][i]);
			i++;
		}
		if (arg[2][i] == '\0')
			bit_send(ft_atoi(arg[1]), arg[2][i]);
		pause();
	}
	return (0);
}
