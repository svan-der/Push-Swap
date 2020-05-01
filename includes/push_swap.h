/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 14:39:14 by svan-der      #+#    #+#                 */
/*   Updated: 2020/04/30 17:37:05 by svan-der      ########   odam.nl         */
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

void 	update_size(t_pw_var *stvar, char *str, int inst);
void	push_half(t_pw_var *stvar, t_part *part_var, int *list, int argc);
void	push_short(t_pw_var *stvar, t_part *part_var);
void    ft_stackdelone(t_stack **alst, void (*del)(int *, size_t));
void	ft_stackdel(t_stack **stack_lst, void (*del)(int *, size_t));
void	push_back(t_pw_var *stvar, t_part *part_var);
int		conquer_list(t_pw_var *stvar, t_part *part_var, int *list);
void    insertion_sort(int *list, int argc, int *min, int *max);
int		part_addnew(t_part **part_var, int *list, int argc);
void	ft_addpart(t_part **part_var, t_part *new);
t_part	*create_part(int argc, int *list);
void	part_sort(t_pw_var *stvar, int argc);
void    sort_three_part(t_stack **stack, t_pw_var *stvar, int min, int max);
void	sort_short(t_pw_var *stvar, char c, int len);
void	sort_two(t_stack **stack_a, t_stack **stack_b, t_pw_var *stvar);
int    	sort_three(t_stack **temp, t_pw_var *stvar, int min, int max);
void    divide_list(t_pw_var *stvar, t_part *part_var);
int		divide_and_presort(t_pw_var *stvar, t_part *part_var, int *sorted_list);
void    print_array(int *list, int argc);
void	set_min_max(t_part *part_var);
void	set_min_maxarray(t_pw_var *stvar, int *list, int len);
t_part	*setup_part(t_pw_var *stvar, t_part *part_var, int *list);
int     find_median_array(int *list, int index);
int 	*lst_cpy(t_stack *stack, int *new);
void    *ft_calloc(size_t count, size_t size);
int     run_pw(t_pw_var *stvar);
int     main(int argc, char **argv);

#endif
