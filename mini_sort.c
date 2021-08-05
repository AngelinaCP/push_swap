#include "push_swap.h"

int	find_max(Unit *new)
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

int	find_min(Unit *new)
{
	int	min;

	min = new->num;
	while (new)
	{
		if (min > new->num)
			min = new->num;
		new = new->next;
	}
	return (min);
}

//void	sort_3_num(Stack *new)
//{
//	int	min;
//
//	min = find_min(new->A);
//	if (new->A->num == min)
//		reverse(&new->A, 1);
//	if (new->A->next->num == min)
//		rotate(&new->A, 1);
//	if (new->A->num < new->A->next->num)
//		ft_swap(&new->A, 1);
//}

void stack_sort_three_helper(Unit **stack)
{
	Unit *tmp;

	tmp = *stack;
	if (tmp->num < tmp->next->num
	&& tmp->next->num > tmp->next->next->num
	&& tmp->num < tmp->next->next->num)
	{
		reverse(stack, 1);
		tmp = *stack;
	}
	if (tmp->num > tmp->next->num
	&& tmp->num < tmp->next->next->num
	&& tmp->next->num < tmp->next->next->num)
	{
		rotate(stack, 1);
	}
}

void sort_3_num(Unit **stack)
{
	Unit *tmp;

	tmp = *stack;
	if (tmp->num > tmp->next->num
	&& tmp->next->num < tmp->next->next->num
	&& tmp->num > tmp->next->next->num)
	{
		ft_swap(stack, 1);
		tmp = *stack;
	}
	if (tmp->num < tmp->next->num
	&& tmp->next->num < tmp->next->next->num)
	{
		ft_swap(stack, 1);
		tmp = *stack;
	}
	if (tmp->num < tmp->next->num
	&& tmp->next->num > tmp->next->next->num
	&& tmp->num > tmp->next->next->num)
		ft_swap(stack, 1);
	stack_sort_three_helper(stack);
}

int	sort_3(int len, Stack *new)
{
	if (len == 1)
		return (1);
	else if (len == 2)
		ft_swap(&new->A, 1);
	else if (len == 3)
		sort_3_num(&new->A);
	return (0);
}

void	sort_4_num(Stack *new)
{
	while (new->num_B < 1)
	{
		if (new->A->num == find_min(new->A))
		{
			reverse(&new->A, 1);
			push_b(&new);

		}
		else
			reverse(&new->A, 1);
	}
	sort_3(3, new);
	push_a(new);
}

void	sort_5_num(Stack *new)
{
	while (new->num_B < 2)
	{
		if (new->A->num == find_min(new->A))
		{
			reverse(&new->A, 1);
			push_b(&new);
		}
		else
			reverse(&new->A, 1);
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
