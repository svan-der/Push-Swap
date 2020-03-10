/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   psw_env.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 14:43:24 by svan-der       #+#    #+#                */
/*   Updated: 2020/03/10 17:49:49 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSW_ENV_H
# define PSW_ENV_H
# include "../libft/includes/list.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/libdefs.h"
# include "../libft/includes/mathlib.h"
# include "../libft/includes/get_next_line.h"
# include "checker.h"

typedef struct		s_inst
{
	char			*operation;
	size_t			content_size;
	struct s_inst	*prev;
	struct s_inst	*next;
}					t_inst;

typedef struct		s_stack
{
	int				*num;
	size_t			len;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_format
{
	int				argc;
	int				index;
	int				sort_index;
	int				median;
	int				max;
	int				min;
	int				total_ins;
	t_list			*argv;
	t_inst			*inst_lst;
	t_stack			*stack_a;
	t_stack			*stack_b;
}					t_format;

int					print_instructions(t_inst *inst_lst, int ret);
t_inst				*create_instruction(char *line);
void				put_instruction(t_inst **inst_lst, char *line);
void				sort_and_check(t_inst *inst_lst, int ret);
int					swap_a(t_stack **stack_a);
int					swap_b(t_stack **stack_b);
int					swap_ss(t_stack **stack_a, t_stack **stack_b);
int					print_stack(t_stack *stack_a, int ret);
int					print_stack_b(t_stack *stack_b, int ret);
int					push_a(t_stack **stack_a, t_stack **stack_b);
int					push_b(t_stack **stack_a, t_stack **stack_b);
int					stack_new(t_stack **stack_a, int num);
t_stack				*create_stack(int num);
int					rotate_a(t_stack **stack_a);
int					rotate_b(t_stack **stack_b);
int					rotate_rr(t_stack **stack_a, t_stack **stack_b);
int					rotate_reva(t_stack **stack_a);
int					rotate_revb(t_stack **stack_b);
void				fill_stack_begin(t_stack **stack_a, t_stack *new);
void				print_backwards(t_stack *stack);
void				ft_stackaddend(t_stack **stack_lst, t_stack *new);
void				stack_push(t_stack **stack, t_stack *new);
int					stack_addnew(t_stack **stack, int num);
void				ft_stackpop(t_stack **aparent, t_stack *elem);
void				content_delete(int *content, size_t size);
// t_stack				*ft_stackpop(t_stack **stack_lst);
t_stack				*reverse_list(t_stack **new);
int					check_sorted(t_stack *stack_a, t_stack *stack_b);
int					check_argv(char *str, t_format *stvar);
// void				debug(t_stack **stack_a, t_stack **stack_b);
int					error_handler(int ret);
void				debug(t_format *stvar);
int					run_checker(t_format *stvar);
int					check_instruction(t_stack **stack_a, t_stack **stack_b, char *line);
#endif
