/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:13:59 by srapaila          #+#    #+#             */
/*   Updated: 2025/04/08 17:25:07 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_stack **a)
{
    t_stack *last;
    t_stack *prev;

    if(*a && (*a)->next)
    {
        last = *a;
        prev = NULL;
        while(last->next)
        {
            prev = last;
            last = last->next;
        }
        prev->next = NULL;
        last->next = *a;
        *a = last;
        write(1, "rra\n", 4);
    }
    // printf("Operazione: rra\n");
    // printf("Pila A: ");
    // print_stack(*a);
}

void rrb(t_stack **b)
{
    t_stack *last;
    t_stack *prev;

    if(*b && (*b)->next)
    {
        last = *b;
        prev = NULL;
        while(last->next)
        {
            prev = last;
            last = last->next;
        }
        prev->next = NULL;
        last->next = *b;
        *b = last;
        write(1, "rrb\n", 4);
        // printf("Operazione: rrb\n");
        // printf("Pila B: ");
        // print_stack(*b);
    }
}

void rrr(t_stack **a, t_stack **b)
{
    rra(a);
    rrb(b);
    write(1, "rrr\n", 4);
    // printf("Operazione: pb\n");
    // printf("Pila A: ");
    // print_stack(*a);
    // printf("Pila B: ");
    // print_stack(*b);
}
