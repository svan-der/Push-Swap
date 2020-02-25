/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   psw_env.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 14:43:24 by svan-der       #+#    #+#                */
/*   Updated: 2020/02/25 17:17:07 by svan-der      ########   odam.nl         */
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
# include "push_swap.h"

typedef struct		s_inst
{
	char			*operation;
	size_t			content_size;
	struct s_inst	*prev;
	struct s_inst	*next;
}					t_inst;

typedef struct		s_part
{
	int				**part;
	int				*len;
	int				max;
	int				min;
}					t_part;

typedef struct		s_stack
{
	int				num;
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
	t_list			*argv;
	t_inst			*inst_lst;
	t_stack			*stack_a;
	t_stack			*stack_b;
	int				partition[];
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
void				fill_stack(t_stack **stack_a, int num);
t_stack				*create_stack(int num);
int					rotate_a(t_stack **stack_a);
int					rotate_b(t_stack **stack_b);
int					rotate_rr(t_stack **stack_a, t_stack **stack_b);
int					rotate_reva(t_stack **stack_a);
int					rotate_revb(t_stack **stack_b);
void				fill_stack_begin(t_stack **stack_a, int num);
void				print_backwards(t_stack *stack);
void				ft_stackaddend(t_stack **stack_lst, t_stack *new);
void				stack_push(t_stack **stack, t_stack *new);
t_stack				*ft_stackpop(t_stack **stack_lst);
t_stack				*reverse_list(t_stack **new);
int					check_sorted(t_stack *stack_a, t_stack *stack_b);
int					check_argv(char *str, t_format *stvar);
void				debug(t_stack **stack_a, t_stack **stack_b);
int					run_checker(t_format *stvar);
int					check_instruction(t_stack **stack_a, t_stack **stack_b, char *line);
#endif