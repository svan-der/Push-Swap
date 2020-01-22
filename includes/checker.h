/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 16:24:14 by svan-der       #+#    #+#                */
/*   Updated: 2020/01/22 16:10:34 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../libft/includes/libft.h"
# include "../libft/includes/list.h"
# include "../libft/includes/get_next_line.h"

typedef struct		s_inst
{
	char			*operation;
	size_t			content_size;
	struct s_inst	*prev;
	struct s_inst	*next;
}					t_inst;

typedef struct		s_stack
{
	int				num;
	size_t			len;
	struct s_stack	*prev;
	struct s_stack	*next;
	struct s_stack	*tail;
}					t_stack;

typedef struct	s_format
{
	int			argc;
	size_t		*max;
	size_t		*min;
	t_list		*argv;
	t_inst		*inst_lst;
	t_stack		*stack_a;
	t_stack		*stack_b;
}				t_format;

int		get_instruction(t_format *stvar);
int		print_instructions(t_inst *inst_lst, int ret);
void	sort_and_check(t_inst *inst_lst, int ret);
int		swap_a(t_stack **stack_a);
int		swap_b(t_stack **stack_b);
int		swap_ss(t_stack **stack_a, t_stack **stack_b);
int		print_stack(t_stack *stack_a, int ret);
int		print_stack_b(t_stack *stack_b, int ret);
int		push_a(t_stack *stack_a, t_stack *stack_b);
int		push_b(t_stack **stack_a, t_stack **stack_b);
void	fill_stack(t_stack **stack_a, int num);
t_stack	*create_stack(int num);
void	fill_stack_begin(t_stack **stack_a, int num);
void	print_backwards(t_stack *stack);
void	ft_stackaddend(t_stack **stack_lst, t_stack *new);
void	debug(t_stack **stack_a, t_stack **stack_b);
#endif
