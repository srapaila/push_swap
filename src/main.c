/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:44:31 by srapaila          #+#    #+#             */
/*   Updated: 2025/04/17 17:29:49 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = check_argvs(argc, argv);
	if (!a)
		free_lst(&a);
	if (check_dup(a))
	{
		free_lst(&a);
		return (write(2, "Error\n", 6), -1);
	}
	if (!stack_sorted(a))
		push_swap(&a, &b);
	free_lst(&a);
	return (0);
}
