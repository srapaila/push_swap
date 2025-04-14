/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:16:08 by srapaila          #+#    #+#             */
/*   Updated: 2025/04/11 17:19:08 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void put_index(t_stack **a)
{
    t_stack *lst;
    t_stack *current;
    t_stack *tmp;
    int i;

    lst = stack_dup(*a);
    sort_list(lst);
    tmp = *a;
    while(tmp)
    {
        i = 0;
        current = lst;
        while(current)
        {
            if (current->nbr == tmp->nbr)
            {
                tmp->index = i;
                break;
            }
            current = current->next;
            i++;
        }
        tmp = tmp->next;
    }
    free_lst(&lst);
}

t_stack  *sort_list(t_stack *src)
{
    t_stack *lst;
    t_stack *head;
    t_stack *i;

    lst = src;
    head = src;
    while(lst)
    {
        i = lst->next;
        while(i)
        {
            if (lst->nbr > i->nbr)
                ft_swap(&lst->nbr, &i->nbr);
            i = i->next;
        }
        lst = lst->next;
    }
    return (head);
}


t_stack *stack_dup(t_stack *src)
{
    t_stack *dest;
    t_stack *tmp;

    dest = NULL;
    tmp = src;
    while (tmp)
    {
        lst_add_back(&dest, new_node(tmp->nbr));
        tmp = tmp->next;
    }
    return (dest);
}