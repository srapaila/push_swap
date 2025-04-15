/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:07:44 by srapaila          #+#    #+#             */
/*   Updated: 2025/04/15 19:50:39 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_stack **a, bool print)
{
    t_stack *last;

    if(*a && (*a)->next)
    {
        last = *a;
        while(last->next)
            last = last->next;
        last->next = *a;
        *a = (*a)->next;
        last->next->next = NULL;
        if(print)
            ft_printf("ra\n");
    }
}

void rb(t_stack **b, bool print)
{
    t_stack *last;

    if(*b && (*b)->next)
    {
        last = *b;
        while(last->next)
            last = last->next;
        last->next = *b;
        *b = (*b)->next;
        last->next->next = NULL;
        if(print)
            ft_printf("rb\n");
    }
}

void rr(t_stack **a, t_stack **b, bool print)
{
    ra(a, false);
    rb(b, false);
    if(print)
        ft_printf("rr\n");
}
