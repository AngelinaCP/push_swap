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

Unit    *find_min(Unit *new)
{
	Unit	*min;

	min = new;
	while (new)
	{
		if (min->num > new->num)
			min = new;
		new = new->next;
	}
	return (min);
}

void	sort_3_num(Stack *new)
{
    int max;

    max = find_max(new->A);
    if (new->A->next->num == max)
        reverse(&new->A, 1);
    else if (new->A->next->next->num == max)
        rotate(&new->A, 1);
	if (new->A->next->num < new->A->next->next->num)
	    ft_swap(&new->A, 1);
}

int	sort_3(int len, Stack *new)
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
    Unit *content;

    find_rr_rra(new->A);
    content = find_min(new->A);
    if (content->rr >= content->rra)
    {
        while (content->rra > 0)
        {
            reverse(&new->A,1);
            content->rra--;
        }
    }
    else
    {
        while (content->rr > 0)
        {
            content->rr--;
            rotate(&new->A,1);
        }
    }
    push_b(&new);
    sort_3_num(new);
    push_a(new);
}

void	sort_5_num(Stack *new)
{
    Unit *content;

    find_rr_rra(new->A);
    content = find_min(new->A);
    if (content->rr >= content->rra)
    {
        while (content->rra > 0)
        {
            reverse(&new->A,1);
            content->rra--;
        }
    }
    else
    {
        while (content->rr > 0)
        {
            content->rr--;
            rotate(&new->A,1);
        }
    }

    push_b(&new);
    sort_4_num(new);
    push_a(new);
}

void	sort_5(int len, Stack *new)
{
	if (len == 4)
		sort_4_num(new);
	else if (len == 5)
		sort_5_num(new);
}
