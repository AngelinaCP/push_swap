#include "push_swap.h"

int find_max(Unit *new)
{
	int max;

	max = new->num;
	while (new)
	{
		if (new->next)
		{
			if (max < new->next->num)
				max = new->next->num;
		}
		new = new->next;
	}
	return (max);
}

int find_min(Unit *new)
{
	int min;

	min = new->num;
	while (new)
	{
		if (new->next)
		{
			if (min > new->next->num)
				min = new->next->num;
		}
		new = new->next;
	}
	return (min);
}

void sort_3_num(Stack *new)
{
	int max;

	max = find_max(new->A);
	if (new->A->num == max)
		rotate(&new->A, 1);
	if (new->A->next->num == max)
		reverse(&new->A, 1);
	if (new->A->num > new->A->next->num)
		ft_swap(&new->A, 1);
}

int sort_3(int len, Stack *new)
{
	if (len == 1)
		return (1);
	else if (len == 2)
		ft_swap(&new->A, 1);
	else if (len == 3)
		sort_3_num(new);
	return (0);
}

void	sort_4_num(Stack *new)
{
	while (new->num_B < 1)
	{
		if (new->A->num == find_min(new->A))
			push_b(new);
		else
			rotate(&new->A, 1);
	}
	sort_3(3 , new);
	push_a(new);
}

void	sort_5_num(Stack *new)
{
	while (new->num_B < 2)
	{
		if (new->A->num == find_min(new->A))
			push_b(new);
		else
			rotate(&new->A, 1);
	}
	sort_3(3, new);
	push_a(new);
	push_a(new);
}

void	sort_5(int len, Stack *new)
{
	if (len == 4)
		sort_4_num(new);
	else if (len == 5)
		sort_5_num(new);
}