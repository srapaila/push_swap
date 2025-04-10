/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 19:57:25 by srapaila          #+#    #+#             */
/*   Updated: 2025/04/10 19:23:05 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ft_atol(const char *str)
{
	long long int	num;
	int	sign;
	int	i;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
        if(!ft_isdigit(str[i]))
            return(write(2, "Error\n", 6), -1);
		num = num * 10 + (str[i] - '0');
		i++;
	}
    if ((sign * num) > 2147483647 || (sign * num) < -2147483648)
            return(write(2, "Error\n", 6), -1);
	return (num * sign);
}

void free_str(char **str)
{
    char *tmp;


    if(!str)
        return ;
    while (*str)
    {
        tmp = *str;
        str++;
        free(tmp);
    }
    *str = NULL;
}
void free_lst(t_stack **lst)
{
    t_stack *tmp;

    if(!lst)
        return ;
    while(*lst)
    {
        tmp = (*lst)->next;
        (*lst)->nbr = 0;
        free(*lst);
        *lst = tmp;
    }

}

int ft_min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int ft_abs(int n)
{
    if (n < 0)
        return (-n);
    return (n);
}

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
