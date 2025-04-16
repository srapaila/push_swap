/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:43:06 by srapaila          #+#    #+#             */
/*   Updated: 2025/04/16 15:06:49 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_swap(t_stack **a, t_stack **b)
{
    int size;

    size = lst_size(*a);

    if (size == 2 && (*a)->nbr > (*a)->next->nbr)
        sa(a, true);
    else if (size == 3)
        sort_three(a);
    else
        sort_all(a, b);
}

void sort_three(t_stack **a)
{
    int top;
    int mid;
    int bot;

    top = (*a)->nbr;
    mid = (*a)->next->nbr;
    bot = (*a)->next->next->nbr;

    if (top > mid && mid < bot && top < bot)
        sa(a, true);
    else if (top > mid && mid < bot)
        ra(a, true);
    else if (top < mid && mid > bot && bot < top)
        rra(a, true);
    else if (top < mid && mid > bot && bot > top)
    {
        rra(a, true);
        sa(a, true);
    }
    else if (top > mid && mid > bot)
    {
        ra(a, true);
        sa(a, true);
    }
}

void sort_all(t_stack **a, t_stack **b)
{
    int size;

    size = lst_size(*a);
    if (size-- > 3 && !stack_sorted(*a))
        pb(a, b);
    if (size-- > 3 && !stack_sorted(*a))
        pb(a, b);
    while (size-- > 3 && !stack_sorted(*a))
    {
        init_a(*a, *b);
        push_to_b(a, b);
    }
    sort_three(a);
    while (*b)
    {
        init_b(*a, *b);
        push_to_a(a, b);
    }
    assign_index(*a);
    final_sort(a);
}

