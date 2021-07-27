
#include "push_swap.h"

void ft_swap(Unit **new, int num)
{
	int tmp;

	tmp = (*new)->num;
	(*new)->num = (*new)->next->num;
	(*new)->next->num = tmp;
	if (num == 1)
		write(1, "sa\n", 3);
}

void rotate(Unit **new, int num)
{
	Unit *tmp;
	Unit *prev;

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

//	Unit *first;
//	Unit *curr;
//	Unit *tmp;
//
//	tmp = *new;
//	first = (*new)->next;
//	curr = *new;
//	while (curr->next)
//		curr = curr->next;
//	tmp->next = NULL;
//	curr->next = tmp;
//	*new = first;
	if (num == 1)
		write(1, "ra\n", 3);
	if (num == 2)
		write(1, "rb\n", 3);
}

void rr(Unit **new)
{
	rotate(new, 1);
	rotate(new, 2);
}

void	reverse(Unit **new, int num)
{
	Unit *first;
	Unit *last;

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

//	Unit	*last;
//	Unit	*tmp;
//	Unit 	*curr;
//
//	tmp = *new;
//	curr = *new;
//	while (curr->next->next)
//		curr = curr->next;
//	last = curr->next;
//	curr->next = NULL;
//	last->next = tmp;
//	*new = last;
	if (num == 1)
		write(1, "rra\n", 4);
	if (num == 2)
		write(1, "rrb\n", 4);
}

void rrr(Unit **new)
{
	reverse(new, 1);
	reverse(new, 2);
}

void push_b(Stack *new)
{
	Unit *buf;

	if (new == NULL)
		return ;
	new->num_A--;
	new->num_B++;
	buf = new->A;
	new->A = new->A->next;
	buf->next = new->B;
	new->B = buf;
	write(1, "pb\n", 3);

}

void push_a(Stack *new)
{
	Unit *buf;

	if (new == NULL)
		return ;
	new->num_A++;
	new->num_B--;
	buf = new->B;
	new->B = new->B->next;
	buf->next = new->A;
	new->A = buf;
	write(1, "pa\n", 3);
}