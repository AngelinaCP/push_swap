#include "push_swap.h"

void	ft_swap(Unit **new, int num)
{
    Unit    *curr;
    Unit    *last;
    int     tmp;
    int     mark;

    last = *new;
    if ((*new)->next  == NULL)
        return ;
    while (last->next)
    {
        curr = last;
        last = last->next;
    }
    tmp = curr->num;
    curr->num = last->num;
    last->num = tmp;
    mark = curr->mark;
    curr->mark = last->mark;
    last->mark = mark;
	if (num == 1)
		write(1, "sa\n", 3);
	else if (num == 2)
	    write(1, "sb\n", 3);
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

void	rr(Unit **new, Unit **new_2, int i)
{
	rotate(new, 0);
	rotate(new_2, 0);
	if (i == 1)
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

void	rrr(Unit **new, Unit **new_2, int i)
{
	reverse(new, 0);
	reverse(new_2, 0);
	if (i == 1)
	    write(1, "rrr\n", 4);
}
