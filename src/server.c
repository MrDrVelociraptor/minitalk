/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:35:49 by nspeedy           #+#    #+#             */
/*   Updated: 2022/02/20 11:35:51 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void    print_pid(void)
{
    ft_printf("Server pid is: %d\n", getpid());
    ft_printf("Open client terminal\n");
    ft_printf("Run the client with ./client <PID> message\n");

}

static void    handle(int sig)
{
    static char bits;
    static int  count;
    int         pid;

    bits = 0;
    count = 0;
    pid = getpid();
    if (sig == SIGUSR1)
        bits |= (1 << count);
    count++;
    if (count == 8)
    {
        ft_printf("%c", bits);
        if (!bits)
            kill(pid, SIGUSR1);
        bits = 0;
        count = 0;
    }
}

int main(void)
{
    print_pid();
    while (1)
    {
        signal(SIGUSR1, handle);
        signal(SIGUSR2, handle);
        pause();
    }
    return (0);
}