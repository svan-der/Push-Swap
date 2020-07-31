t_stack	*return_bottom_position(t_pw_var *stvar, t_stack *temp, char *instr, int i)
{
	t_stack *bottom;
	int		j;

	j = 1;
	(void)instr;
	bottom = stvar->stack_b->tail;
	if (temp->num && stvar->stack_b->next)
	{
		while (bottom && j < i)
		{
			bottom = bottom->prev;
			if (bottom == NULL)
				bottom = stvar->stack_b->tail;
			j++;
		}
	}
	return (bottom);
}

t_stack *return_top_position(t_pw_var *stvar, t_stack *temp, char *instr, int i)
{
	t_stack *top;
	int		j;

	j = 1;
	top = stvar->stack_b;
	(void)instr;
	while (j < i && temp)
	{
		temp = temp->next;
		j++;
		if (temp == NULL)
			temp = stvar->stack_b;
	}
	if (temp->num && stvar->stack_b->next)
	{
		if (temp->next)
			top = temp->next;
		else
			top = stvar->stack_b;
	}
	return (top);
}

char	*check_double(t_pw_var *stvar, char *instr, int i, t_stack *current)
{
	t_stack *temp;
	t_stack *bottom;
	t_stack	*top;

	temp = stvar->stack_b;
	(void)current;
	if (instr == RA)
	{
		if (temp && temp->next)
		{
			// ft_printf(YEL"IN CHECK DOUBLE %s %i\n", instr, i);
			top = return_top_position(stvar, temp, instr, i);
			// ft_printf("top:%i top next:%i\n", temp->num, top->num);
			if (temp->num < top->num)
				instr = RR;
		}
	}
	else if (instr == RRA)
	{
		if (temp && temp->tail)
		{
			bottom = return_bottom_position(stvar, temp, instr, i);
			// ft_printf("top:%i top next:%i\n", temp->num, bottom->num);
			if (bottom->num > temp->num)
				instr = RRR;
		}
	}
	// ft_printf("INSTR:%s\n"RESET, instr);
	return (instr);
}