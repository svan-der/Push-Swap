/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   psw_env.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 14:43:24 by svan-der      #+#    #+#                 */
/*   Updated: 2020/06/20 13:30:51 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSW_ENV_H
# define PSW_ENV_H
# include "list.h"
# include "libft.h"
# include "libdefs.h"
# include "mathlib.h"
# include "get_next_line.h"
# include "ft_printf.h"
# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

typedef enum		e_error
{
	INVALID = 0,
	MEM_ERROR = 1,
	ERROR = 2,
}					t_error;

typedef enum		e_sort
{
	sa, ra, rra, sb, rb, \
	rrb, ss, rr, rrr, pa, pb\
}					t_sort;

typedef struct		s_inst
{
	char			*operation;
	size_t			content_size;
	t_sort			option;
	struct s_inst	*prev;
	struct s_inst	*next;
	// struct s_inst	*tail;
}					t_inst;

typedef struct		s_stack
{
	int				num;
	int				dist;
	int				dist_top;
	int				index;
	int				part_id;
	struct s_stack	*prev;
	struct s_stack	*next;
	struct s_stack	*tail;
}					t_stack;

typedef struct		s_pw_var
{
	int				argc;
	int				index;
	int				sort_index;
	int				median;
	int				max;
	int				min;
	int				total_ins;
	int				*sorted;
	int				*list;
	t_list			*argv;
	t_inst			*inst_lst;
	t_stack			*stack_a;
	t_stack			*stack_b;
}					t_pw_var;

typedef int	(*t_operates)(t_pw_var *stvar);

/*
** Sorting operations
*/

int					swap_a(t_pw_var *stvar);
int					swap_b(t_pw_var *stvar);
int					swap_ss(t_pw_var *stvar);
int					push_b(t_pw_var *stvar);
int					push_a(t_pw_var *stvar);
int					rotate_a(t_pw_var *stvar);
int					rotate_b(t_pw_var *stvar);
int					rotate_rr(t_pw_var *stvar);
int					rotate_reva(t_pw_var *stvar);
int					rotate_revb(t_pw_var *stvar);
int					rotate_rrr(t_pw_var *stvar);

/*
** Stack handling functions
*/

void				initialize_operations(t_operates function_array[10]);
int					print_stack(t_stack **stack_a, int ret);
int					print_stack_b(t_stack **stack_b, int ret);
void				ft_stackaddend(t_stack **stack_lst, t_stack *new);
int					add_num(char *str, int sign, t_pw_var *stvar);
int					stack_new(t_stack **stack_a, int num);
void				stack_push(t_stack **stack, t_stack *new);
int					stack_addnew(t_stack **stack, int num);
void				ft_stackpop(t_stack **aparent, t_stack *elem);
t_stack				*create_stack(int num);
t_stack				*fill_stack_begin(t_stack **stack, t_stack *new);
// t_stack				*ft_stackpop(t_stack **stack_lst);

/*
** instruction handling functions
*/

// int					get_instruction(t_pw_var *stvar);
// void				put_instruction(t_inst **inst_lst, char *line);
int					print_instructions(t_inst *inst_lst, int ret);
// int					check_instruction(t_stack **stack_a, t_stack **stack_b,
// 					char *line);
t_inst				*create_instruction(int i, char *line);

/*
** print functions
*/

void				add_tail(t_stack **stack);
void				print_tail(t_stack *tail);

void				print_input_list(t_stack *stack, int *list);
void				print_inst_list(t_inst *instr);
void				print_stack_list(t_stack *stack, char c);
void				print_pw_var(t_pw_var *stvar);

int					execute_instruction(t_pw_var *stvar);
void				print_inst(t_inst *instr);
void				free_inst_list(t_inst **inst_lst);
void				free_stack_list(t_stack **stack_a, t_stack **stack_b);
int 				dispatch_sort(t_pw_var *stvar, char *str, int ins);
void				sort_and_check(t_inst *inst_lst, int ret);
void				print_backwards(t_stack *stack);
void				content_delete(int *content, size_t size);
t_stack				*reverse_list(t_stack **new);
int					check_sorted(t_stack **stack_a, t_stack **stack_b);
int					check_argv(char *str, t_pw_var *stvar);
int					check_dup(t_stack **stack_a);
// void				debug(t_stack **stack_a, t_stack **stack_b);
int					error_handler(int ret);
void				debug(t_pw_var *stvar);
int					run_checker(t_pw_var *stvar);
int					ft_exit(t_pw_var *stvar);
#endif
