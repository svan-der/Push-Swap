/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 16:24:14 by svan-der       #+#    #+#                */
/*   Updated: 2020/01/10 12:05:58 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libft/includes/libft.h"
# include "libft/includes/list.h"

// typedef struct	s_stack
// {
// 	int *stack_a;
// 	int *stack_b;
// 	int count;
// }				t_stack;


typedef struct		s_inst
{
	char			*content;
	size_t			content_size;
	struct s_inst	*next;
}					t_inst;

typedef struct		s_stack
{
	int				num;
	size_t			len;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct	s_format
{
	int			argc;
	size_t		*max;
	size_t		*min;
	t_list		*argv;
	t_list		*buffer;
	t_stack		*stack_a;
	t_stack		*stack_b;
}				t_format;

#endif
