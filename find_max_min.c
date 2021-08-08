#include "push_swap.h"

int	find_max_ab(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

t_Unit	*find_max_struct(t_Unit *new)
{
	t_Unit	*curr;
	t_Unit	*tmp;

	curr = new->next;
	tmp = new;
	while (curr)
	{
		if (tmp->num < curr->num)
			tmp = curr;
		curr = curr->next;
	}
	return (tmp);
}

t_Unit	*find_min_struct(t_Unit *new)
{
	int		min;
	t_Unit	*curr;
	t_Unit	*tmp;

	min = new->num;
	curr = new->next;
	tmp = new;
	while (curr)
	{
		if (min > curr->num)
		{
			min = curr->num;
			tmp = curr;
		}
		curr = curr->next;
	}
	return (tmp);
}

t_Unit	*find_min_struct_2(t_Stack *new)
{
	int		min;
	t_Unit	*curr;
	t_Unit	*tmp;

	min = new->A->num;
	curr = new->A;
	tmp = new->A;
	while (curr)
	{
		if (min > curr->num)
		{
			min = curr->num;
			tmp = curr;
		}
		curr = curr->next;
	}
	return (tmp);
}

int	new_size(t_Unit *new)
{
	int	i;

	i = 0;
	while (new)
	{
		i++;
		new = new->next;
	}
	return (i);
}
