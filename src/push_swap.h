/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:45:04 by srapaila          #+#    #+#             */
/*   Updated: 2025/04/15 19:53:47 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
    int    nbr;
    int    index;
    int     push_cost;
    bool    above_median;
    bool    cheapest;
    struct s_stack  *target_node;
    struct s_stack  *next;
}           t_stack;

// main
t_stack *check_argvs(int argc, char **argv);
t_stack *multiple_args(int argc, char **argv);
t_stack *two_args(char **argv);

//lst_utils
t_stack	*new_node(int content);
t_stack	*lst_last(t_stack *lst);
int     lst_size(t_stack *lst);
void	lst_add_back(t_stack **lst, t_stack *new);

//utils
int	ft_atol(const char *str);
void free_str(char **str);
void free_lst(t_stack **lst);
t_stack *get_cheapest(t_stack *stack);

//utils_sort_five
void push_two_min(t_stack **a, t_stack **b);
void find_two_min(t_stack *stack, int *min1, int *min2);
void ft_swap(int *a, int *b);
int get_max(t_stack **stack);
int get_min(t_stack **stack);

//check
int check_dup(t_stack *a);
int stack_sorted(t_stack *a);
bool is_valid_number(const char *str);

//operations
void pa(t_stack **a, t_stack **b);
void pb(t_stack **a, t_stack **b);
void sa(t_stack **a, bool print);
void sb(t_stack **b, bool print);
void ss(t_stack **a, t_stack **b, bool print);
void ra(t_stack **a, bool print);
void rb(t_stack **b, bool print);
void rr(t_stack **a, t_stack **b, bool print);
void rra(t_stack **a, bool print);
void rrb(t_stack **b, bool print);
void rrr(t_stack **a, t_stack **b, bool print);
void print_stack(t_stack *stack);


//push_swap
void push_swap(t_stack **a, t_stack **b);
void sort_three(t_stack **a);
void sort_five(t_stack **a, t_stack **b);
void sort_all(t_stack **a, t_stack **b);

//sort_utils
void init_a(t_stack *a, t_stack *b);
void assign_index(t_stack *stack);
void    set_target_a(t_stack *a, t_stack *b);
void calculate_cost_a(t_stack *a, t_stack *b);
void set_cheapest(t_stack *stack);

//sort_utils2
t_stack *get_max_node(t_stack *stack);
void push_to_b(t_stack **a, t_stack **b);
void r_both_stacks(t_stack **a, t_stack **b, t_stack *cheapest_node);
void rr_both_stacks(t_stack **a, t_stack **b, t_stack *cheapest_node);
void pre_push(t_stack **stack, t_stack *top_node, char name);

//sort_utils3
void final_sort(t_stack **a);
t_stack *get_min_node(t_stack *stack);
void    set_target_b(t_stack *a, t_stack *b);
void init_b(t_stack *a, t_stack *b);
void push_to_a(t_stack **a, t_stack **b);

//index_utils
void put_index(t_stack **a);
t_stack  *sort_list(t_stack* lst);
t_stack *stack_dup(t_stack *src);

#endif
