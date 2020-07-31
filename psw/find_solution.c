/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_solution.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/11 17:14:33 by svan-der      #+#    #+#                 */
/*   Updated: 2020/07/31 13:43:41 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* checks the dist top <-> next, top <-> next->next, top <-> bottom number
** depending on smallest dist either stays put, swaps or rotates current number
*/

void	find_solution(t_pw_var *stvar, t_stack *current, char *oper)
{
	int top_next;
	int top_next_next;
	int bottom;
	int	ret;

	if (stvar->stack_b != NULL && stvar->stack_b->next != NULL)
	{
		int i;

		i = 0;
		bottom = stvar->stack_b->tail->num;
		top_next = stvar->stack_b->next->num;
		if (stvar->stack_b->next->next != NULL)
			top_next_next = stvar->stack_b->next->next->num;
		bottom = ft_abs(current->num - bottom);
		top_next = ft_abs(current->num - top_next);
		top_next_next = ft_abs(current->num - top_next_next);
		ret = top_next;
		if (stvar->stack_b->next->next != NULL && ret > top_next_next)
			ret = top_next_next;
		if (ret > bottom)
			ret = bottom;
		if (ret == bottom && ret != stvar->stack_b->num && ret != top_next)
			do_op(stvar, RB, 'b', 1);
		else if (stvar->stack_b->next->next != NULL \
		&& ret == top_next_next && ret != top_next)
			do_op(stvar, RB, 'b', 1);
	}
}

void	ft_find_double(t_inst **tail, char *oper_a, char *oper_b, int *i)
{
	t_inst	*temp;
	char	*operation;
	int		tot;
	int		j;

	temp = *tail;
	j = 0;
	tot = 0;
	while (temp)
	{
		if (ft_strequ(temp->operation, oper_a))
			*i += 1;
		if (ft_strequ(temp->operation, oper_b))
			j += 1;
		if (ft_strequ(temp->operation, PB))
		{
			tot += 1;
			break ;
		}
		temp = temp->prev;
	}
	temp = *tail;
	*i = ft_min(*i, j);
	temp->opt_dble_b = *i;
	temp->opt_dble_a = *i;
	temp->opt_double = *i;
	*tail = temp;
}

static char		*find_double_oper(char *oper_a)
{
	if (ft_strnequ(oper_a, RR, 2))
		return (RRR);
	else if (oper_a[0] == 'r')
		return (RR);
	else if (oper_a[0] == 's')
		return (SS);
}

t_inst	*insert_double_ins(t_inst **tail, char *oper_a, char *oper_b, int tot)
{
	t_inst *temp;
	int		i;
	int		j;
	char	*operation;

	temp = *tail;
	i = temp->opt_dble_a;
	j = temp->opt_dble_b;
	operation = find_double_oper(oper_a);
	while (tot && temp)
	{
		if (ft_strequ(temp->operation, oper_b))
		{
			if (j > 0)
				j--;
			else
				while (!ft_strequ(temp->operation, oper_a))
					temp = temp->prev;
		}
		else
		{
			if (i > 0)
				i--;
			if (!ft_strequ(temp->operation, oper_a))
			{
				while (!ft_strequ(temp->operation, oper_b))
					temp = temp->prev;
			}
		}
		ft_strcpy(temp->operation, operation);
		temp = temp->prev;
		tot -= 1;
	}
	// tail = &temp;
	return (*tail);
}

void	f_double_solution(t_pw_var *stvar, char *oper_a, char *oper_b, int ret)
{
	t_inst	**tail;

	if (stvar->inst_lst)
	{
		tail = &(stvar)->inst_lst->tail;
		ret = 0;
		ft_find_double(&(stvar)->inst_lst->tail, oper_a, oper_b, &ret);
		ret = (*tail)->opt_double;
		if (ret != 0)
		{
			// print_tail_inst((stvar)->inst_lst->tail);
			*tail = inst_tail_del(&(stvar)->inst_lst->tail, oper_b, oper_a, ret);
			*tail = insert_double_ins(&(stvar)->inst_lst->tail, oper_a, oper_b, ret);
			// print_tail_inst((stvar)->inst_lst->tail);
		}
	}
}

void	check_dble(t_pw_var *stvar, char *oper)
{
	int		ret;
	char	*oper_a;
	char	*oper_b;

	ret = -1;
	if ((ft_strequ(oper, RRA) || ft_strequ(oper, RRB)))
	{
		oper_a = RRA;
		oper_b = RRB;
	}
	if ((ft_strequ(oper, RA) || ft_strequ(oper, RB)))
	{
		oper_a = RA;
		oper_b = RB;
	}
	if ((ft_strequ(oper, SA) || ft_strequ(oper, SB)))
	{
		oper_a = SA;
		oper_b = SB;
	}
	ret = ft_strrchr(oper, 'a') ? 0 : 1;
	if (ret != -1 && oper_a && oper_b)
		f_double_solution(stvar, oper_a, oper_b, ret);
}
