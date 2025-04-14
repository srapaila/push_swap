/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:48:09 by srapaila          #+#    #+#             */
/*   Updated: 2025/04/14 19:36:28 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_to_b(t_stack **a, t_stack **b)
{
    t_stack *cheapest_node;

    cheapest_node = get_cheapest(*a);
    if (cheapest_node->above_median
        && cheapest_node->target_pos->above_median)
        r_both_stacks(a, b, cheapest_node);
    else if (!(cheapest_node->above_median)
            && !(cheapest_node->target_pos->above_median))
        rr_both_stacks(a, b, cheapest_node);
    pre_push(a, cheapest_node, 'a');
    pre_push(b, cheapest_node->target_pos, 'b');
    pb(a, b);
}

void r_both_stacks(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
    while(*b != cheapest_node->target_pos && *a != cheapest_node)
        rr(a, b);
    assign_index(*a);
    assign_index(*b);
}
void rr_both_stacks(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
    while(*b != cheapest_node->target_pos && *a != cheapest_node)
        rrr(a, b);
    assign_index(*a);
    assign_index(*b);
}

void pre_push(t_stack **stack, t_stack *top_node, char name)
{
    while (*stack != top_node)
    {
        if (name == 'a')
        {
            if(top_node->above_median)
                ra(stack);
            else
                rra(stack);
        }
        else if (name == 'b')
        {   
            if(top_node->above_median)
                rb(stack);
            else
                rrb(stack);
        }
    }
}

t_stack *get_max_node(t_stack *stack)
{
    long max;
    t_stack *max_pos;

    if (!stack)
        return (NULL);
    max = LONG_MIN;
    while(stack)
    {
        if (stack->nbr > max)
        {
            max = stack->nbr;
            max_pos = stack;
        }
        stack = stack->next;
    }
    return (max_pos);
}