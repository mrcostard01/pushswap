/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipion <wipion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 15:53:37 by wipion            #+#    #+#             */
/*   Updated: 2026/01/11 21:29:28 by wipion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


void merge(int *arr, int left,  int mid, int right)
{
    int     i;
    int     j;
    int     k;
    int     half1;
    int     half2;
    int     *tmparr1;
    int     *tmparr2;

    i = 0;
    j = 0;
    k = 0;
    half1 = mid - left + 1;
    half2 = right - mid;
    tmparr1 = malloc(sizeof(int) * half1);
    if(!tmparr1)
        free(tmparr1);
    tmparr2 = malloc(sizeof(int) * half2);
    if(!tmparr2)
        free(tmparr2);
    
    while (i < half1)
    {
        tmparr1[i] = arr[left + i];
        i++;
    }
    while (j < half2)
    {
        tmparr2[j] = arr[mid + 1 +j];
        j++;
    }

    i = 0;
    j = 0;
    k = left;
    while (i < half1 && j < half2)
    {
        if (tmparr1[i] <= tmparr2[j])
        {
            arr[k] = tmparr1[i];
            i++;
        }
        else
        {
            arr[k] = tmparr2[j];
            j++;
        }
        k++;
    }
    while (i < half1)
    {
        arr[k] = tmparr1[i];
        i++;
        k++;
    }
    while (j < half2)
    {
        arr[k] = tmparr2[j];
        j++;
        k++;
    }

}

void mergesort (int arr[], int left, int right)
{
    int mid;

    mid = 0;
    if (left < right)
    {
            mid = left + (right - left) / 2;
            mergesort(arr, left, mid);
            mergesort(arr, mid + 1, right);
            merge(arr, left, mid, right);
    }
}