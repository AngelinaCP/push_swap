#include "push_swap.h"

t_Unit	*find_pair_from_a(t_Unit *new, int num)
{
	t_Unit	*prev;
	t_Unit	*tmp;

	prev = new;
	tmp = new->next;
	while (tmp)
	{
		if (prev->num > num && tmp->num < num)
			return (prev);
		prev = tmp;
		tmp = tmp->next;
	}
	if (find_max_struct(new)->num < num)
		return (find_min_struct(new));
	if (new->num < num)
	{
		while (new->next)
			new = new->next;
		return (new);
	}
	return (find_min_struct(new));
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

int	main(int argc, char **argv)
{
	int		j;
	t_Stack	*new;
	t_Unit	*tmp;

	if (argc < 2)
		exit (1);
	new = init_Stack();
	new->A = split_argv(argc, argv);
	if (check_dup(new->A))
		error();
	if (check_if_sorted(new->A))
		exit (1);
	tmp = new->A;
	j = new_size(tmp);
	sort_stack(j, new);
	// free_stack(&(new)->A);
	while (new->A)
	{
		printf("%d ", new->A->num);
		new->A = new->A->next;
	}
}
