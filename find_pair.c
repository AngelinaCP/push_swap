#include"push_swap.h"

void	find_rr_rra(t_Unit *new)
{
	int	size;
	int	i;

	i = 1;
	size = new_size(new);
	while (new)
	{
		new->rr = size - i;
		new->rra = i;
		i++;
		new = new->next;
	}
}

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
