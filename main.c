/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipion <wipion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 11:54:51 by wipion            #+#    #+#             */
/*   Updated: 2026/01/25 22:45:17 by wipion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>
int	ft_atol(const char *str)
{
	long long int	nbr;
	long long int	i;
	int	sign;

	nbr = 0;
	i = 0;
	sign = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		nbr = (nbr * 10) + (str[i] - 48);
		i++;
	}
	if (sign == 1)
		return (nbr * -1);
	return (nbr);
}

int checkduplicate(int *tab /*, int len*/)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (tab[i] != 'l')
    {
        //j = i;
        j = 0;
        while (tab[j] != 'l')
        {
            if (tab[i] == tab[j] && j != i)
                return (-1);
            j++;
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
        if (!str || str[0] == 'l')
            return (NULL);
        i = 0;
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
                if ((num[i][j] == '-' && num[i][j + 1] == '-')|| (num[i][j] == '+' && (num[i][j + 1] == '+')))
                    return (NULL);
                if (ft_isdigit(num[i][j]) == 0 && num[i][j] != '-' && num[i][j] != '+' && num[i][j] != '/' )
                    return (NULL);
                j++;
            }
            k += j;
            i++;
        }
        len = len + k - j;
        newtab = malloc(sizeof(int) * len) ;
        if (!newtab)
        {
            free(newtab);
            return (NULL);
        }
	
        //ft_bzero(newtab, len);
        j = 0;
        while (num[j])
        {
            newtab[j] = ft_atol(num[j]);
            free(num[j]);
            j++;
        }
        newtab[j] = 'l';
        if (checkduplicate(newtab) == -1)
            return (NULL);
        newtab[j] = '\0';
        free(num);
        return (newtab);
}
#include <unistd.h>
int     main(int ac, char **av)
{
    int *reallist;
    int *fakelist;
    t_list  *tmp;
    int    j;
    char    *str;
    t_list  *startnode;
    int len;
    int i;
    i = 1;
    j = 0;
    len = 1;
    if (ac < 2)
    {
        write(2, "Error\n", 6);
        return (-1);
    }
    if (av[1] == NULL || av[1][0] == '\0')
    {
        write(2, "Error\n", 6);
        return (-1);
    }
    while (av[i])
    {
        len += ft_strlen(av[i]) + 1;
        i++;
    }
    len++;
    
    i = 1;
     printf ("%i", len);
    if (ac > 3)
    {
        len = 0;
        while (av[i])
        {
            len += ft_strlen(av[i]);
            i++;
        }
        str = malloc(sizeof(char) * (len + i));
        if (!str)
        {
		    free(str);
		    return (-1);
        }
        i = 1;
        while (av[i])
        {
            ft_strlcat(str, av[i], len + i);
            ft_strlcat(str, " ", len + i);
            i++;
        }
        i = 0;
        reallist = checkstring(str);
        fakelist = checkstring(str);
        free(str);
    }
    else
    {
        while (av[i][j])
        {
            if (av[i][j] == ' ' && av[i][j + 1] == ' ')
            {
                write(2, "Error\n", 6);
                return (-1);
            }
            j++;
        }

        reallist = checkstring(av[1]);
        fakelist = checkstring(av[1]);
    }
    i = 0;
    len = 0;
    if (!reallist )
    {
        free(reallist);
        write(2, "Error\n", 6);
        return (-1);
    }
    if (reallist[0] == '\0')
        len++;
    while (reallist[len] != '\0')
        len++;
    mergesort(reallist,0, len - 1);
     /*while (i < len)
    {
        printf("%i : %i\n", i,reallist[i]);
        i++;
    }*/
    while (reallist[i] != fakelist[0])
        i++;
    startnode = createlist(fakelist[0], i);
    tmp = startnode;
    i = 1;
    while (i < len && startnode->next != NULL)
    {
        j = 0;
        while (fakelist[i] != reallist[j])
            j++;
        /*if (j== 2)
            j--;*/
        //printf("%i\n",j);
        addafter(startnode,fakelist[i], j);
        startnode=startnode->next;
        i++;
    }
    i=0;
    j = 0;
    //deleteelement(startnode);
    startnode = tmp;
    /*while (i < len)
    {
        //printf("%i : %i\n",i,stackb[i]);
        printf("%i: %i\n", startnode->index, startnode->number);
        startnode=startnode->next;
        i++;
    }*/
    //printf("%i\n", startnode->next->index);
    tmp = startnode->next;
    while (j < len)
    {
            if (startnode->prev->index == j && startnode->index != j)
            {
                 write(1, "rra\n",4);
                 //write(1, "pb\n",3);
                 //startnode = startnode->next;
            }
            /*if (startnode->next->index == j && startnode->index == j)
            {
                 write(1, "sa\n",3);
                 //startnode = startnode->next;
            }*/
            if (startnode->index == j)
            {
                write(1, "pb\n",3);
                //deleteelement(startnode);
                //startnode = startnode->next;
                j++;
            }
            else {
                if (startnode->next->index != j || j == 0)
                    write (1, "ra\n", 3);
                startnode = startnode->next;
            }
            /*if (startnode->index == j)
            {
                 write(1, "sa\n",3);
                 //startnode = startnode->next;
            }*/
    }
    /*i = 0;
    while (i < len)
    {
        write(1, "rb\n", 3);
        i++;
    }*/
    i = 0;
    while (i < len)
    {
        write(1, "pa\n", 3);
        i++;
    }
    i = 0;
    startnode = tmp;
    /*while (i < len)
    {
        //printf("%i : %i\n",i,stackb[i]);
        printf("%i : %i\n", startnode->index, startnode->number);
        startnode=startnode->next;
        i++;
    }*/
    //deleteelement(startnode);
    free(reallist);
    return (0);
}