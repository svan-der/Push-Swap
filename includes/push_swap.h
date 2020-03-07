/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 14:39:14 by svan-der       #+#    #+#                */
/*   Updated: 2020/03/07 21:29:25 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/includes/libft.h"
# include "psw_env.h"

typedef struct		s_part
{
	int				*parts;
	int				len;
	int				max;
	int				min;
	struct s_part	*prev;
	struct s_part	*next;
}					t_part;

int     main(int argc, char **argv);
int     run_pw(t_format *stvar);
void    *ft_calloc(size_t count, size_t size);
int     *lst_cpy(t_stack *stack, int argc);
int     find_median_array(int *list, int index);
void	set_min_max(t_part *part_var);
void    print_array(int *list, int argc);
void    divide_list(t_format *stvar, t_part *part_var);
void    sort_three(t_stack **temp, t_format *stvar, int min, int max);
void	sort_two(t_stack **stack_a, t_stack **stack_b, t_format *stvar);
void	sort_short(t_format *stvar, t_part **part_var);
void    sort_threeb(t_stack **temp, t_format *stvar, int min, int max, int len);
void	part_sort(t_format *stvar, t_part *part_var, int argc);
void    insertion_sort(int *list, int argc, int *min, int *max);
void	conquer_list(t_format *stvar, t_part *part_var);
void	push_back(t_format *stvar, t_part *part_var, int argc, int sum);
void	ft_stackpop(t_stack **aparent, t_stack *elem);
void	ft_stackdel(t_stack **stack_lst, void (*del)(int *, size_t));
void    ft_stackdelone(t_stack **alst, void (*del)(int *, size_t));

#endif
