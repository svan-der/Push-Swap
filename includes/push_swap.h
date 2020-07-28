/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 14:39:14 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/28 18:12:20 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "psw_env.h"

//Regular text
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define RESET "\e[0m"
#define MAGHB "\e[1;45m"

typedef struct		s_part
{
	int				*parts;
	size_t			len;
	int				max;
	int				min;
	struct s_part	*prev;
	struct s_part	*next;
}					t_part;

char	*presort_simple(t_pw_var *stvar, t_stack *current);
void	sort_top(t_pw_var *stvar, t_stack *top);
void	sort_bottom(t_pw_var *stvar, t_stack *bottom);
int		calc_shortest_dist_top(t_pw_var *stvar, t_stack *top, t_stack *bottom);
char	*find_solution(t_pw_var *stvar, t_stack *current, char *oper);
t_stack *find_high(t_pw_var *stvar, char c, int *index);
void	check_top_b(t_pw_var *stvar);
void	sort_short_opts(t_pw_var *stvar);

void	f_double_solution(t_pw_var *stvar, char *oper_a, char *oper_b, int i);
// int		check_dble(t_pw_var *stvar, char *op_a, char *op_b, int i);
int		check_dble(t_pw_var *stvar, char *instr);
char	*presort_stack_b(t_pw_var *stvar, t_stack *current, int *i);

int		calc_dist_top_b(t_pw_var *stvar, t_stack *top, t_stack *bottom);
void	find_part(t_pw_var *stvar, int i);
char	*find_pos(t_pw_var *stvar, t_stack *current, t_stack *temp, int *j);
void	find_min(t_stack *current, int min, int *j);
void	find_max(t_stack *current, int max, int *j);
char	*check_double(t_pw_var *stvar, char *instr, int i, t_stack *n);
void	set_index(t_stack **stack_a, int *sorted, int argc);
char	*fastest_rotate(t_pw_var *stvar, char c, int *index);
int		sort_short_stack(t_pw_var *stvar, int argc);
int		do_op(t_pw_var *stvar, char *str, char c, int i);
int		presort_list(t_pw_var *stvar);
void	find_dist_top(t_stack *stack, int num);
void	find_distance(t_stack *stack_a, int num, int *sorted);
char	*find_low(t_pw_var *stvar, char c, int *index);
void	update_stack(t_pw_var *stvar, char c);

void	print_partition_list(t_part *partition);
void 	update_size(t_pw_var *stvar, char *str, int inst);
void	push_half(t_pw_var *stvar, int *list, int argc);
void	push_short(t_pw_var *stvar, int *list, int argc);
void    ft_stackdelone(t_stack **alst, void (*del)(int *, size_t));
void	ft_stackdel(t_stack **stack_lst, void (*del)(int *, size_t));
void	push_back(t_pw_var *stvar, t_part *part_var);
int		conquer_list(t_pw_var *stvar, int *list);
void    insertion_sort(int *list, int argc, int *min, int *max);
int		part_addnew(t_part **part_var, int *list, int argc);
void	ft_addpart(t_part **part_var, t_part *new);
t_part	*create_part(int argc, int *list);
void	part_sort(t_pw_var *stvar, int argc, int i);
int		sort_five_stack(t_pw_var *stvar, char c, int argc);
void    sort_three_part(t_stack **stack, t_pw_var *stvar, int min, int max);
void	sort_short(t_pw_var *stvar, char c, int len);
void	sort_two(char c, t_pw_var *stvar);
int    	sort_three(t_pw_var *stvar, int min, int max);
int		sort_threeb(t_pw_var *stvar, int min, int max);
int    	divide_list(t_pw_var *stvar);
int		divide_and_presort(t_pw_var *stvar, int *sorted_list);
// int		divide_and_presort(t_pw_var *stvar, t_part *part_var, int *sorted_list);
void    print_array(int *list, int argc);
void	set_min_max(t_pw_var *stvar, char c);
// void	set_min_max(t_part *part_var);
void	set_min_maxarray(t_pw_var *stvar, int *list, int len);
t_part	*setup_part(t_pw_var *stvar, t_part *part_var, int *list);
int     find_median_array(int *list, int index);
int 	*lst_cpy(t_pw_var *stvar);
void    *ft_calloc(size_t count, size_t size);
int     run_pw(t_pw_var *stvar);
int     main(int argc, char **argv);

#endif
