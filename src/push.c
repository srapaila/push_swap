/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:57:10 by srapaila          #+#    #+#             */
/*   Updated: 2025/04/08 17:22:37 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    if(*b)
    {
        tmp = *b;
        *b = (*b)->next;
        tmp->next = *a;
        *a = tmp;
        write(1, "pa\n", 3);
    }
    // printf("Operazione: pa\n");
    // printf("Pila A: ");
    // print_stack(*a);
    // printf("Pila B: ");
    // print_stack(*b);
}

void pb(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    if(!*a)
        return ;
    if(*b && (*a)->nbr < (*b)->nbr)
        rb(b);
    if(*a)
    {
        tmp = *a;
        *a = (*a)->next;
        tmp->next = *b;
        *b = tmp;
        write(1, "pb\n", 3);
    }
    // printf("Operazione: pb\n");
    // printf("Pila A: ");
    // print_stack(*a);
    // printf("Pila B: ");
    // print_stack(*b);
}
