/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:58:44 by srapaila          #+#    #+#             */
/*   Updated: 2025/04/17 17:31:02 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*two_args(char **argv)
{
	t_stack	*a;
	char	**tmp;
	long	j;
	int		i;

	a = NULL;
	i = -1;
	tmp = ft_split(argv[1], 32);
	while (tmp[++i])
	{
		if (!is_valid_number(tmp[i]))
		{
			free_str(tmp);
			free_lst(&a);
			return (write(2, "Error\n", 6), NULL);
		}
		j = ft_atol(tmp[i]);
		lst_add_back(&a, new_node(j));
		if (!a)
			return (NULL);
	}
	free_str(tmp);
	return (a);
}

t_stack	*multiple_args(int argc, char **argv)
{
	t_stack	*a;
	long	j;
	int		i;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
		{
			free_lst(&a);
			return (write(2, "Error\n", 6), NULL);
		}
		j = ft_atol(argv[i]);
		lst_add_back(&a, new_node(j));
		if (!a)
			return (NULL);
		i++;
	}
	return (a);
}

t_stack	*check_argvs(int argc, char **argv)
{
	if (argc < 2)
		return (NULL);
	if (argc == 2)
		return (two_args(argv));
	else
		return (multiple_args(argc, argv));
}
