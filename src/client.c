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

static void    have_a_byte(char byte, int pid)
{
    int i;

    i = 7;
    while (i >= 0)
    {
        if (byte >> i & 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(234);
        i--;
    }
}

static void    the_sandwhich(char *str, int pid)
{
    int i;

    i = 0;
    while(str[i])
    {
        have_a_byte(str[i], pid);
        i++;
    }
}

int main(int argc, char *argv[])
{
    int     serv_pid;
    char    *msg;

    if (argc != 3)
        ft_printf("Client takes more args");
    serv_pid = ft_atoi(argv[1]);
    ft_printf("%d\n", serv_pid);
    msg = argv[2];
    ft_printf("%s\n", msg);
    the_sandwhich(msg, serv_pid);
    return (0);
}