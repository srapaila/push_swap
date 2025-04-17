/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:13:59 by srapaila          #+#    #+#             */
/*   Updated: 2025/04/17 17:36:00 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a, bool print)
{
	t_stack	*last;
	t_stack	*prev;

	if (*a && (*a)->next)
	{
		last = *a;
		prev = NULL;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *a;
		*a = last;
		if (print)
			ft_printf("rra\n");
	}
}

void	rrb(t_stack **b, bool print)
{
	t_stack	*last;
	t_stack	*prev;

	if (*b && (*b)->next)
	{
		last = *b;
		prev = NULL;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *b;
		*b = last;
		if (print)
			ft_printf("rrb\n");
	}
}

void	rrr(t_stack **a, t_stack **b, bool print)
{
	rra(a, false);
	rrb(b, false);
	if (print)
		ft_printf("rrr\n");
}
