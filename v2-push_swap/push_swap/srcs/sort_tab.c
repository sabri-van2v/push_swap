/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:12:04 by marvin            #+#    #+#             */
/*   Updated: 2023/01/06 02:12:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int lower_number(int *arr, int max)
{
    int index;
    int lower;

    index = 0;
    lower = arr[0];
    while (index < max)
    {
        if (arr[index] < lower)
            lower = arr[index];
        index++;
    }
    return (lower);
}

void    sort_tab(t_tab *tab)
{
    int     number;
    int     i;
    int     tmp;
    int     index_tmp;

    i = 0;
    while (i < tab->len)
    {
        index_tmp = 0;
        number = lower_number(&tab.array[i], tab->len - i);
        while (tab->array[index_tmp] != number)
            index_tmp++;
        tmp = tab->array[index->tmp];
        tab->array[i] = number;
        tab->array[index_tmp] = tmp;
        i++;
    }
}