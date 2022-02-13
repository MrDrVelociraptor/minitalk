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

int main(void)
{
    int id = fork();
    int n;
    if (id == 0)
    {
        n = 1;
    }
    else
    {
        n = 6;
    }
    if (id != 0)
        wait(0);
    int i;
    for (i = n; i < n + 5; i++)
    {
        ft_printf("%d ", i);
        //fflush(stdout);
    }
    if (id != 0)
        //ft_printf("\n");
        ft_printf("\nThe parent waited for the child to finish\n");
    return (0);
}
