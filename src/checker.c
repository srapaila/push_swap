/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:32:57 by srapaila          #+#    #+#             */
/*   Updated: 2025/04/17 17:28:01 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	read_and_execute(t_stack **a, t_stack **b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (!is_valid_move(line))
			return (free(line), 0);
		execute_move(line, a, b);
		free(line);
	}
	if (line)
		free(line);
	line = NULL;
	return (1);
}

void	execute_move(char *move, t_stack **a, t_stack **b)
{
	if (ft_strcmp(move, "sa\n") == 0)
		sa(a, false);
	else if (ft_strcmp(move, "sb\n") == 0)
		sb(b, false);
	else if (ft_strcmp(move, "ss\n") == 0)
		ss(a, b, false);
	else if (ft_strcmp(move, "ra\n") == 0)
		ra(a, false);
	else if (ft_strcmp(move, "rb\n") == 0)
		rb(b, false);
	else if (ft_strcmp(move, "rr\n") == 0)
		rr(a, b, false);
	else if (ft_strcmp(move, "rra\n") == 0)
		rra(a, false);
	else if (ft_strcmp(move, "rrb\n") == 0)
		rrb(b, false);
	else if (ft_strcmp(move, "rrr\n") == 0)
		rrr(a, b, false);
	else if (ft_strcmp(move, "pa\n") == 0)
		pa(a, b, false);
	else if (ft_strcmp(move, "pb\n") == 0)
		pb(a, b, false);
}

int	is_valid_move(char *line)
{
	const char	*moves[] = {"sa\n", "sb\n", "ss\n", "pa\n", \
						"pb\n", "ra\n", "rb\n", "rr\n", \
						"rra\n", "rrb\n", "rrr\n", NULL};
	int			i;

	i = 0;
	while (moves[i])
	{
		if (ft_strcmp(line, moves[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = check_argvs(argc, argv);
	if (!a && argc > 1)
		return (write(2, "Error\n", 6), EXIT_FAILURE);
	if (check_dup(a))
		return (write(2, "Error\n", 6), free_lst(&a), EXIT_FAILURE);
	if (!read_and_execute(&a, &b))
		return (write(2, "Error\n", 6), free_lst(&a), EXIT_FAILURE);
	if (stack_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_lst(&a);
	return (EXIT_SUCCESS);
}
