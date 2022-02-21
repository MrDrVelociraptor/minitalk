/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 08:24:08 by nspeedy           #+#    #+#             */
/*   Updated: 2022/02/14 08:24:11 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"

static void    bit_sender(pid_t pid, char c)
{
    int     i = 0;

    while (i >= 0)
    {
        if (c >> i & 1)
        {
            if (kill(pid, SIGUSR1) == -1)
                ft_printf("Negative on the SIGUSR1\n");
        }
        else
        {
            if (kill(pid, SIGUSR2) == -1)
                ft_printf("Negative on the SIGUSR2\n");
        }
        i--;
        usleep(234); 
    }
}

static void    sig_handle(int pid, char *msg)
{
    int i = 0;

    while (msg[i] != '\0')
    {
        bit_sender(pid, msg[i]);
        i++;
    }
    bit_sender(pid, msg[i]);
    msg[strlen(msg) + 1] = '\0';
}

int main(int argc, char *argv[])
{
    if (argc != 3)
        ft_printf("<PID> [message]");
    sig_handle(ft_atoi(argv[1]), argv[2]);
    return (1);
}