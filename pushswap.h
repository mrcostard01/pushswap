/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipion <wipion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 18:34:17 by wipion            #+#    #+#             */
/*   Updated: 2026/01/11 21:27:01 by wipion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_list
{
    int             number;
    int             index;
    struct s_list   *prev;
    struct s_list   *next;
} t_list;

t_list  *createlist (void);
void addbefore (t_list *element, int number, int index);
void addafter (t_list *element, int number, int index);
void deleteelement (t_list *element);
void mergesort (int *arr, int left, int right);
int *checkstring(char *str);
#endif