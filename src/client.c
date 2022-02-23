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

static void    bit_send(int pid, char c)
{
    int byte;

    byte = 7;
    while (byte >= 0)
    {
        if ((c >> byte) & 1)
        {
            if (kill(pid, SIGUSR1) == -1)
                ft_printf("SIGUSR1 fail\n");
        }
        else
        {
            if (kill(pid, SIGUSR2) == -1)
                ft_printf("SIGUSR2 fail\n");
        }
        byte--;
        usleep(200);
    }
}

int main(int ac, char *arg[])
{
    int pid;
    int i;

    pid = ft_atoi(arg[1]);
    i = 0;
    if (ac != 3)
        printf("Correct input ./client <server-pid> <message>\n");
    while (arg[2][i] != '\0')
    {
        bit_send(pid, arg[2][i]);
        i++;
    }
    return (1);
}