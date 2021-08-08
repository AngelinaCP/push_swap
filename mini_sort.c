#include "push_swap.h"

int	find_max(t_Unit *new)
{
	int	max;

	max = new->num;
	while (new)
	{
		if (max < new->num)
			max = new->num;
		new = new->next;
	}
	return (max);
}

t_Unit	*find_min(t_Unit *new)
{
	t_Unit	*min;

	min = new;
	while (new)
	{
		if (min->num > new->num)
			min = new;
		new = new->next;
	}
	return (min);
}

void	sort_3_num(t_Stack *new)
{
	int	max;

	max = find_max(new->A);
	if (new->A->next->num == max)
		reverse(&new->A, 1);
	else if (new->A->next->next->num == max)
		rotate(&new->A, 1);
	if (new->A->next->num < new->A->next->next->num)
		ft_swap(&new->A, 1);
}

int	sort_3(int len, t_Stack *new)
{
	if (len == 1)
		return (1);
	else if (len == 2)
		ft_swap(&new->A, 1);
	else if (len == 3)
		sort_3_num(new);
	return (0);
}

void	sort_4_num(t_Stack *new)
{
	t_Unit	*content;

	find_rr_rra(new->A);
	content = find_min(new->A);
	if (content->rr >= content->rra)
	{
		while (content->rra > 0)
		{
			reverse(&new->A, 1);
			content->rra--;
		}
	}
	else
	{
		while (content->rr > 0)
		{
			content->rr--;
			rotate(&new->A, 1);
		}
	}
	push_b(&new, 1);
	sort_3_num(new);
	push_a(new, 1);
}
