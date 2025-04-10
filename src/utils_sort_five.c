/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:42:08 by marvin            #+#    #+#             */
/*   Updated: 2025/04/06 12:42:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_two_min(t_stack **a, t_stack **b)
{
    int min1;
    int min2;
    int size;
    int i;

    find_two_min(*a, &min1, &min2);
    size = lst_size(*a);
    i = 0;
    while (i < size && lst_size(*b) < 2)
    {
        if((*a)->nbr == min1 || (*a)->nbr == min2)
            pb(a, b);
        else
            ra(a);
        i++;
    }
}

void find_two_min(t_stack *stack, int *min1, int *min2)
{
    t_stack *current;

    if (!stack)
        return ;
    *min1 = stack->nbr;
    *min2 = stack->next->nbr;
    if (*min1 > *min2)
        ft_swap(min1, min2);
    current = stack->next->next;
    while (current)
    {
        if (current->nbr < *min1)
        {
            *min2 = *min1;
            *min1 = current->nbr;
        }
        else if (current->nbr < *min2)
        {
            *min2 = current->nbr;
        }
        current = current->next;
    }
}

void ft_swap(int *a, int *b)
{
    long tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int get_min(t_stack **stack)
{
    t_stack *current = *stack;
    int min;

    min = current->nbr;
    while(current)
    {
        if (current->nbr < min)
            min = current->nbr;
        current = current->next;
    }
    return (min);
}

int get_max(t_stack **stack)
{
    t_stack *current = *stack;
    int max;

    max = current->nbr;
    while(current)
    {
        if (current->nbr > max)
            max = current->nbr;
        current = current->next;
    }
    return (max);
}
