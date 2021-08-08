#include "push_swap.h"

void    push_a(Stack *new, int i)
{
    Unit	*tmp_a;
    Unit	*tmp_b;
    Unit	*prev_b;

    tmp_a = new->A;
    tmp_b = new->B;
    prev_b = new->B;
    if (tmp_b)
    {
        if (!tmp_b->next)
            new->B = NULL;
        while (tmp_b->next)
        {
            prev_b = tmp_b;
            tmp_b = tmp_b->next;
        }
        prev_b->next = NULL;
    }
    else
        return ;
    if (tmp_a)
    {
        while (tmp_a->next)
            tmp_a = tmp_a->next;
        tmp_a->next = tmp_b;
    }
    else
        new->A = tmp_b;
    if (i == 1)
        write(1, "pa\n", 3);
}

void    push_b(Stack **new, int i)
{
    Unit	*stack_a;
    Unit	*stack_b;
    Unit	*prev;

    (*new)->num_B++;
    stack_a = (*new)->A;
    stack_b = (*new)->B;
    if (!(*new)->A)
        return ;
    else
    {
        if (!stack_a->next)
            (*new)->A = NULL;
        while (stack_a->next)
        {
            prev = stack_a;
            stack_a = stack_a->next;
        }
        prev->next = NULL;
    }
    if (!(*new)->B)
        (*new)->B = stack_a;
    else
    {
        while (stack_b->next)
            stack_b = stack_b->next;
        stack_b->next = stack_a;
    }
    if (i == 1)
        write(1, "pb\n", 3);
}


void find_two_pairs(Stack **new)
{
    Unit	*stack_a;
    Unit	*stack_b;
    Unit	tmp_a;
    Unit 	tmp_b;
    int		steps;

    steps = 2147483647;
    stack_b = (*new)->B;
    while (stack_b)
    {
        stack_a = find_pair_from_a((*new)->A, stack_b->num);
        if (steps > min_steps(stack_a, stack_b))
        {
            steps = min_steps(stack_a, stack_b);
            tmp_a = *stack_a;
            tmp_b = *stack_b;
        }
        stack_b = stack_b->next;
    }
    tmp_b.next = NULL;
    tmp_a.next = NULL;
    do_operations(&tmp_a, &tmp_b, new, *new, *new);
}

