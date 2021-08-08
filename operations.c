#include "push_swap.h"

void do_rr(Stack *stack_a, Unit *stack_b, Unit *tmp_a, Unit *tmp_b)
{
	(void)stack_b;
	while (tmp_a->rr > 0 && tmp_b->rr > 0)
	{
		rr(&stack_a->A, &stack_a->B, 1);
		tmp_a->rr--;
		tmp_b->rr--;
	}
	while (tmp_a->rr--)
		rotate(&stack_a->A, 1);
	while (tmp_b->rr--)
		rotate(&stack_a->B, 2);
}

void do_rrr(Stack *stack_a, Unit *stack_b, Unit *tmp_a, Unit *tmp_b)
{
	(void)stack_b;
	while (tmp_a->rra > 0 && tmp_b->rra > 0)
	{
			rrr(&stack_a->A, &stack_a->B, 1);
			tmp_a->rra--;
			tmp_b->rra--;
	}
	while (tmp_a->rra-- > 0)
		reverse(&stack_a->A, 1);
	while (tmp_b->rra-- > 0)
		reverse(&stack_a->B, 2);
}

void do_ra_a_rra_b(Stack *stack_a, Unit *stack_b, Unit *tmp_a, Unit *tmp_b)
{
	(void)stack_b;
	while (tmp_b->rra > 0)
	{
		reverse(&stack_a->B, 2);
		tmp_b->rra--;
	}
	while (tmp_a->rr > 0)
	{
		rotate(&stack_a->A, 1);
		tmp_a->rr--;
	}
}

void do_ra_b_rra_a(Stack *stack_a, Unit *stack_b, Unit *tmp_a, Unit *tmp_b)
{
	(void)stack_b;
	while (tmp_a->rra > 0)
	{
		reverse(&stack_a->A, 1);
		tmp_a->rra--;
	}
	while (tmp_b->rr > 0)
	{
		rotate(&stack_a->B, 2);
		tmp_b->rr--;
	}
}

void do_operations(Unit *tmp_a, Unit *tmp_b, Stack **stack_a, Stack *stack_b, Stack *new)
{
	(void)stack_b;
	int rr;
	int rrr;
	int	ra_a_rra_b;
	int ra_b_rrs_a;
	rr = find_max_ab((*tmp_a).rr, (*tmp_b).rr);
	rrr = find_max_ab((*tmp_a).rra, (*tmp_b).rra);
	ra_a_rra_b = (*tmp_b).rra + (*tmp_a).rr;
	ra_b_rrs_a = (*tmp_a).rra + (*tmp_b).rr;
	if (rr <= rrr && rr <= ra_a_rra_b && rr <= ra_b_rrs_a)
	 	do_rr((*stack_a), (*stack_a)->B, tmp_a, tmp_b);
	else if (rrr <= rr && rrr <= ra_a_rra_b && rrr <= ra_b_rrs_a)
		do_rrr((*stack_a), (*stack_a)->B, tmp_a, tmp_b);
	else if (ra_a_rra_b <= rr && ra_a_rra_b <= rrr && ra_a_rra_b <= ra_b_rrs_a)
		do_ra_a_rra_b((*stack_a), (*stack_a)->B, tmp_a, tmp_b);
	else if (ra_b_rrs_a <= rr && ra_b_rrs_a <= rrr && ra_b_rrs_a <= ra_a_rra_b)
		do_ra_b_rra_a((*stack_a), (*stack_a)->B, tmp_a, tmp_b);
	push_a(new, 1);
}
