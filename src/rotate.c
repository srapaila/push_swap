/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:07:44 by srapaila          #+#    #+#             */
/*   Updated: 2025/04/08 17:25:42 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_stack **a)
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
        write(1, "ra\n", 3);
        // printf("Operazione: ra\n");
        // printf("Pila A: ");
        // print_stack(*a);
    }
}

void rb(t_stack **b)
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
        // write(1, "rb\n", 3);
        // printf("Operazione: rb\n");
        // printf("Pila B: ");
        // print_stack(*b);
    }
}

void rr(t_stack **a, t_stack **b)
{
    ra(a);
    rb(b);
    write(1, "rr\n", 3);
    // printf("Operazione: rr\n");
    // printf("Pila A: ");
    // print_stack(*a);
    // printf("Pila B: ");
    // print_stack(*b);
}
