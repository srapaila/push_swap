/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:57:10 by srapaila          #+#    #+#             */
/*   Updated: 2025/04/17 17:35:20 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b, bool print)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	if (*b)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = *a;
		*a = tmp;
		if (print)
			ft_printf("pa\n");
	}
}

void	pb(t_stack **a, t_stack **b, bool print)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	if (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = *b;
		*b = tmp;
		if (print)
			ft_printf("pb\n");
	}
}
