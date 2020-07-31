/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 14:39:14 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/31 19:32:52 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "psw_env.h"

typedef struct		s_part
{
	int				*parts;
	size_t			len;
	int				max;
	int				min;
	struct s_part	*prev;
	struct s_part	*next;
}					t_part;

/*
** Sort short stack functions
*/

int					sort_five_stack(t_pw_var *stvar, char c, int argc);
void				sort_two(char c, t_pw_var *stvar);
int					sort_three(t_pw_var *stvar, int min, int max);
void				sort_short_opts(t_pw_var *stvar);

/*
** Presort list functions
*/

void				set_min_max(t_pw_var *stvar, char c);
int					find_median_array(int *list, int index);
void				insertion_sort(int *list, int argc);

/*
** Divide and presort in partitions
*/

int					divide_list(t_pw_var *stvar, int argc, int index);
int					divide_and_presort(t_pw_var *stvar);
void				part_sort(t_pw_var *stvar, int argc, int i);
void				push_back_part(t_pw_var *stvar, int argc);
int					sort_short_stack(t_pw_var *stvar, int argc);

char				*presort_simple(t_pw_var *stvar, t_stack *current);
void				sort_top(t_pw_var *stvar, t_stack *top);
void				sort_bottom(t_pw_var *stvar, t_stack *bottom);
int					shortest_dist(t_pw_var *stvar, t_stack *top, t_stack *btm);
void				find_solution(t_pw_var *stvar, t_stack *current);
t_stack				*find_high(t_pw_var *stvar, char c, int *index);
void				check_top_b(t_pw_var *stvar);

void				find_part(t_pw_var *stvar, int i);
void				find_max(t_stack *current, int max, int *j);
char				*fastest_rotate(t_pw_var *stvar, char c, int *index);

int					do_op(t_pw_var *stvar, char *str, char c, int i);
void				set_index(t_stack **stack_a, int *sorted, int argc);

t_stack				*find_top_part(t_pw_var *stvar, int i);
t_stack				*find_bottom_part(t_pw_var *stvar, int i);
void				find_distance(t_stack *stack_a, int num, int *sorted);
char				*find_low(t_pw_var *stvar, char c, int *index);

int					run_pw(t_pw_var *stvar);
int					main(int argc, char **argv);

#endif
