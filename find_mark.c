#include "push_swap.h"

int	count_mark(t_Unit *new)
{
	t_Unit	*tmp;
	int		count;

	count = 1;
	tmp = new;
	new = new->next;
	if (new)
	{
		while (new->next)
		{
			if (new->num > tmp->num)
			{
				count++;
				tmp = new;
			}
			new = new->next;
		}
		if (new->num > tmp->num)
			count++;
	}
	return (count);
}

int	min_steps(t_Unit *stack_a, t_Unit *stack_b)
{
	int	rr;
	int	rrr;
	int	ra_a_rra_b;
	int	ra_b_rrs_a;

	rr = find_max_ab(stack_a->rr, stack_b->rr);
	rrr = find_max_ab(stack_a->rra, stack_b->rra);
	ra_b_rrs_a = stack_b->rr + stack_a->rra;
	ra_a_rra_b = stack_a->rr + stack_b->rra;
	if (rr <= rrr && rr <= ra_a_rra_b && rr <= ra_b_rrs_a)
		return (rr);
	if (rrr <= rr && rrr <= ra_a_rra_b && rrr <= ra_b_rrs_a)
		return (rrr);
	if (ra_a_rra_b <= rr && ra_a_rra_b <= rrr && ra_a_rra_b <= ra_b_rrs_a)
		return (ra_a_rra_b);
	if (ra_b_rrs_a <= rr && ra_b_rrs_a <= rrr && ra_b_rrs_a <= ra_a_rra_b)
		return (ra_b_rrs_a);
	return (ra_a_rra_b);
}

void	put_mark_2(t_Unit *curr, int count_dup, t_Unit *prev, t_Unit *new)
{
	if (curr)
	{
		while (curr->next)
		{
			if (prev->num > curr->num)
			{
				prev = curr;
				curr->mark = 1;
			}
			curr = curr->next;
		}
		if (prev->num > curr->num)
			curr->mark = 1;
	}
	while (count_dup--)
		rotate(&new, 0);
}

void	put_mark(t_Unit *new, int num)
{
	t_Unit	*curr;
	int		count;
	int		count_dup;
	t_Unit	*prev;

	count = 0;
	curr = new;
	while (curr)
	{
		if (curr->num == num)
			break ;
		count++;
		curr = curr->next;
	}
	count_dup = count;
	while (count--)
		reverse(&new, 0);
	prev = new;
	prev->mark = 1;
	curr = new->next;
	put_mark_2(curr, count_dup, prev, new);
}

void	find_mark_1(t_Unit *new)
{
	int	count;
	int	max;
	int	i;
	int	num;

	i = 0;
	count = new_size(new);
	while (count--)
	{
		max = count_mark(new);
		if (i < max)
		{
			i = max;
			num = new->num;
		}
		rotate(&new, 0);
	}
	put_mark(new, num);
}
