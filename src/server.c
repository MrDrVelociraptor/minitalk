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

static void handle(int sig)
{
    static unsigned char    byte;
    static int              shift;

    shift <<= 1;
    shift += 1;
    byte <<= 1;
    if (sig == SIGUSR1)
    {
        signal(SIGUSR1, handle);
        byte++;
    }
    else if (sig == SIGUSR2)
        signal(SIGUSR2, handle);
    if (shift == 8)
    {
        write(1, &byte, 1);
        byte = 0;
        shift = 0;
    }
} 

int main(void)
{
    print_pid();
    signal(SIGUSR1, handle);
    signal(SIGUSR2, handle);
    while (1)    
        pause();
}