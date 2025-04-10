/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:50:20 by srapaila          #+#    #+#             */
/*   Updated: 2025/04/08 17:25:16 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack **a)
{
    int tmp;

    if(*a && (*a)->next)
    {
        tmp = (*a)->nbr;
        (*a)->nbr = (*a)->next->nbr;
        (*a)->next->nbr = tmp;
        write(1, "sa\n", 3);
    }
    // printf("Operazione: sa\n");
    // printf("Pila A: ");
    // print_stack(*a);
}

void sb(t_stack **b)
{
    int tmp;

    if(*b && (*b)->next)
    {
        tmp = (*b)->nbr;
        (*b)->nbr = (*b)->next->nbr;
        (*b)->next->nbr =tmp;
        write(1, "sb\n", 3);
    }
    // printf("Operazione: sb\n");
    // printf("Pila B: ");
    // print_stack(*b);
}

void ss(t_stack **a, t_stack **b)
{
    sa(a);
    sb(b);
    write(1, "ss\n", 3);
    // printf("Operazione: ss\n");
    // printf("Pila A: ");
    // print_stack(*a);
    // printf("Pila B: ");
    // print_stack(*b);
}


// void print_stack(t_stack *stack)
// {
//     t_stack *current = stack;
//     printf("[ ");
//     while (current)
//     {
//         printf("%d ", current->nbr);
//         current = current->next;
//     }
//     printf("]\n");
// }
