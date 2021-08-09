#include "push_swap.h"

void	push_aa(t_Stack *new, t_Unit *tmp_b)
{
	t_Unit	*tmp_a;

	tmp_a = new->A;
	if (tmp_a)
	{
		while (tmp_a->next)
			tmp_a = tmp_a->next;
		tmp_a->next = tmp_b;
	}
	else
		new->A = tmp_b;
}

void	push_a(t_Stack *new, int i)
{
	t_Unit	*tmp_b;
	t_Unit	*prev_b;

	tmp_b = new->B;
	prev_b = new->B;
	if (tmp_b)
	{
		if (!tmp_b->next)
			new->B = NULL;
		while (tmp_b->next)
		{
			prev_b = tmp_b;
			tmp_b = tmp_b->next;
		}
		prev_b->next = NULL;
	}
	else
		return ;
	push_aa(new, tmp_b);
	if (i == 1)
		write(1, "pa\n", 3);
}

void	push_bb(t_Stack **new, t_Unit *stack_a)
{
	t_Unit	*stack_b;

	stack_b = (*new)->B;
	if (!(*new)->B)
		(*new)->B = stack_a;
	else
	{
		while (stack_b->next)
			stack_b = stack_b->next;
		stack_b->next = stack_a;
	}
}

void	push_b(t_Stack **new, int i)
{
	t_Unit	*stack_a;
	t_Unit	*prev;

	(*new)->num_B++;
	stack_a = (*new)->A;
	if (!(*new)->A)
		return ;
	else
	{
		if (!stack_a->next)
			(*new)->A = NULL;
		while (stack_a->next)
		{
			prev = stack_a;
			stack_a = stack_a->next;
		}
		prev->next = NULL;
	}
	push_bb(new, stack_a);
	if (i == 1)
		write(1, "pb\n", 3);
}

void	find_two_pairs(t_Stack **new)
{
	t_Unit	*stack_a;
	t_Unit	*stack_b;
	t_Unit	tmp_a;
	t_Unit	tmp_b;
	int		steps;

	steps = 2147483647;
	stack_b = (*new)->B;
	while (stack_b)
	{
		stack_a = find_pair_from_a((*new)->A, stack_b->num);
		if (steps > min_steps(stack_a, stack_b))
		{
			steps = min_steps(stack_a, stack_b);
			tmp_a = *stack_a;
			tmp_b = *stack_b;
		}
		stack_b = stack_b->next;
	}
	tmp_b.next = NULL;
	tmp_a.next = NULL;
	do_operations(&tmp_a, &tmp_b, new, *new);
}
