/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipion <wipion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 11:54:51 by wipion            #+#    #+#             */
/*   Updated: 2026/01/11 20:16:03 by wipion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

int checkduplicate(int *tab)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (tab[i])
    {
        j = i;
        while (tab[j])
        {
            j++;
            if (tab[i] == tab[j])
                return (-1);
        }
        i++;
    }
    return (0);
}

int *checkstring(char *str)
{
        char **num;
        int    *newtab;
        int     len;
        int     i;
        int     k;
        int     j;

        i = 0;
        j = 0;
        k = 0;
        len = 0;
        if (!str || str[0] == '\0')
            return (NULL);
        num = ft_split(str, ' ');
        if (!num)
        {
            free(num);
            return (NULL);
        }
        while (num[i])
        {
            j = 0;
            while (num[i][j])
            {
                if (ft_isdigit(num[i][j]) == 0)
                    return (NULL);
                j++;
            }
            k += j;
            i++;
        }
        len = len + k;
        newtab = malloc(sizeof(int) * len) ;
        if (!newtab)
        {
            free(newtab);
            return (NULL);
        }
        ft_bzero(newtab, len);
        j = 0;
        while (num[j])
        {
            newtab[j] = ft_atoi(num[j]);
            free(num[j]);
            j++;
        }
        newtab[j] = '\0';
        if (checkduplicate(newtab) == -1)
            return (NULL);
        free(num);
        return (newtab);
}
#include <unistd.h>
int     main(int ac, char **av)
{
    int *reallist;
    int *fakelist;
    int len;
    int i;
    i = 0;
    len = 0;
    if (ac < 2 || ac > 3)
    {
        write(2, "Error\n", 6);
        return (-1);
    }
    if (av[1] == NULL)
    {
        write(2, "Error\n", 6);
        return (-1);
    }
    reallist = checkstring(av[1]);
    fakelist = checkstring(av[1]);
    if (!reallist || reallist == 0)
    {
        write(2, "Error\n", 6);
        return (-1);
    }
    while (reallist[len] != '\0')
        len++;
    mergesort(reallist,0, len - 1);
    while (reallist[i])
    {
        printf("%i\n", reallist[i]);
        i++;
    }
    free(reallist);
    free(fakelist);

}