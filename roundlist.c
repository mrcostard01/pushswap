/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roundlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipion <wipion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 20:34:26 by wipion            #+#    #+#             */
/*   Updated: 2026/01/11 20:57:51 by wipion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list  *createlist (void)
{
    t_list *root = malloc(sizeof(*root));
    if (root != NULL)
    {
        root->prev = root;
        root->next = root;
    }
    return (root);
}

void addbefore (t_list *element, int number, int index)
{
    t_list  *new_element = malloc(sizeof(*new_element));
    if ( new_element != NULL)
    {
        new_element->number = number;
        new_element->index = index;
        new_element->prev = element->prev;
        new_element->prev = element;
        element->prev->next = new_element;
        element->prev = new_element;
    }
}

void addafter (t_list *element, int number, int index)
{
    t_list  *new_element = malloc(sizeof(*new_element));
    if ( new_element != NULL)
    {
        new_element->number = number;
        new_element->index = index;
        new_element->prev = element;
        new_element->next = element->next;
        element->next->prev = new_element;
        element->next = new_element;
    }
}

void deleteelement (t_list *element)
{
    element->prev->next = element->next;
    element->next->prev = element->prev;
    free(element);
}