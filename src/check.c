/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 20:32:27 by srapaila          #+#    #+#             */
/*   Updated: 2025/04/07 19:33:11 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_dup(t_stack *a)
{
	t_stack *tmp;

	while(a)
	{
		tmp = a->next;
		while(tmp)
		{
			if(a->nbr == tmp->nbr)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return(0);
}

int stack_sorted(t_stack *a)
{
    int i;

    i = a->nbr;
    while (a)
    {
        if (i > a->nbr)
            return (0);
        i = a->nbr;
        a = a->next;
    }
    return (1);
}

bool is_valid_number(const char *str)
{
    int i;

    i = 0;
    while(str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
        i++;
    if(str[i] == '+' || str[i] == '-')
        i++;
    if(!ft_isdigit(str[i]))
        return (false);
    while(ft_isdigit(str[i]))
        i++;
    return (str[i] == '\0' || str[i] == ' ' ||
            (str[i] >= '\t' && str[i] <= '\r'));
}

