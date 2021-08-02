#include "push_swap.h"

void	ft_swap(Unit *new, int num)
{
	int	tmp;

	tmp = new->num;
	new->num = new->next->num;
	new->next->num = tmp;
	if (num == 1)
		write(1, "sa\n", 3);
}

void	rotate(Unit **new, int num)
{
	Unit	*tmp;
	Unit	*prev;

	prev = *new;
	tmp = *new;
	if (!tmp->next)
		return ;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	tmp->next = *new;
	*new = tmp;
	if (num == 1)
		write(1, "ra\n", 3);
	if (num == 2)
		write(1, "rb\n", 3);
}

void	rr(Unit **new, Unit **new_2)
{
	rotate(new, 0);
	rotate(new_2, 0);
	write(1, "rr\n", 3);
}

void	reverse(Unit **new, int num)
{
	Unit	*first;
	Unit	*last;

	first = *new;
	if (first->next)
	{
		*new = (*new)->next;
		first->next = NULL;
	}
	else
		return ;
	last = *new;
	while (last->next)
		last = last->next;
	last->next = first;
	if (num == 1)
		write(1, "rra\n", 4);
	if (num == 2)
		write(1, "rrb\n", 4);
}

void	rrr(Unit **new, Unit **new_2)
{
	reverse(new, 0);
	reverse(new_2, 0);
	write(1, "rrr\n", 4);
}

void	push_b(Stack **new)
{
	Unit	*stack_a;
	Unit	*stack_b;
	Unit	*prev;

	(*new)->num_B++;
	(*new)->num_A--;
	stack_a = (*new)->A;
	stack_b = (*new)->B;
	prev = (*new)->B;
	if ((*new)->A)
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
	else
		return ;
	if ((*new)->B)
	{
		while (stack_b->next)
			stack_b = stack_b->next;
		stack_b->next = stack_a;
	}
	else
		(*new)->B = stack_a;
	write(1, "pb\n", 3);
}

void	push_a(Stack *new)
{
	Unit	*tmp_a;
	Unit	*tmp_b;
	Unit	*prev_b;

	tmp_a = new->A;
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
	if (tmp_a)
	{
		while (tmp_a->next)
			tmp_a = tmp_a->next;
		tmp_a->next = tmp_b;
	}
	else
		new->A = tmp_b;
	write(1, "pa\n", 3);
}