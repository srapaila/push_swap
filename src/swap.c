/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:50:20 by srapaila          #+#    #+#             */
/*   Updated: 2025/04/15 19:57:11 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack **a, bool print)
{
    int tmp;

    if(*a && (*a)->next)
    {
        tmp = (*a)->nbr;
        (*a)->nbr = (*a)->next->nbr;
        (*a)->next->nbr = tmp;
        if(print)
            ft_printf("sa\n");
    }
}

void sb(t_stack **b, bool print)
{
    int tmp;

    if(*b && (*b)->next)
    {
        tmp = (*b)->nbr;
        (*b)->nbr = (*b)->next->nbr;
        (*b)->next->nbr =tmp;
        if(print)
            ft_printf("sb\n");
    }
}

void ss(t_stack **a, t_stack **b, bool print)
{
    sa(a, false);
    sb(b, false);
    if(print)
            ft_printf("ss\n");
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
