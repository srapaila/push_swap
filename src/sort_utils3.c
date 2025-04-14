/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:31:32 by srapaila          #+#    #+#             */
/*   Updated: 2025/04/14 20:09:26 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_b(t_stack *a, t_stack *b)
{
    assign_index(a);
    assign_index(b);
    set_target_b(a, b);
}

void    set_target_b(t_stack *a, t_stack *b)
{
    t_stack *target_node;
    t_stack *current_a;
    long   best_match_index;
    
    while (b)
    {
        current_a = a;
        best_match_index = LONG_MAX;
        while(current_a)
        {
            if(current_a->nbr > b->nbr && \
                current_a->nbr < best_match_index)
            {
                best_match_index = current_a->nbr;
                target_node = current_a;
            }
            current_a = current_a->next;
        }
        if(best_match_index == LONG_MAX)
            b->target_pos = get_min_node(a);
        else
            b->target_pos = target_node;
        b = b->next;
    }
}

t_stack *get_min_node(t_stack *stack)
{
    long min;
    t_stack *min_pos;

    if (!stack)
        return (NULL);
    min = LONG_MAX;
    while(stack)
    {
        if (stack->nbr < min)
        {
            min = stack->nbr;
            min_pos = stack;
        }
        stack = stack->next;
    }
    return (min_pos);
}

void push_to_a(t_stack **a, t_stack **b)
{
    if (!*b || !(*b)->target_pos)
        return ;
    pre_push(a, (*b)->target_pos, 'a');
    pa(a, b);
}

void final_sort(t_stack **a)
{
    t_stack *min_node;

    min_node = get_min_node(*a);
    while((*a)->nbr != min_node->nbr)
    {
        if (min_node->above_median)
            ra(a);
        else
            rra(a);
    }
}