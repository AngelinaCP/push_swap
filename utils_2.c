#include "push_swap.h"

void free_stack(Unit **new)
{
    Unit	*curr = *new;
    Unit    *aux;
    while (curr)
    {
        aux = curr;
        curr = curr->next;
        free (aux);
    }
    *new = NULL;
}

Stack *init_Stack(void)
{
    Stack *new;

    new = (Stack *)malloc(sizeof(Stack));
    if (!new)
        exit (1);
    new->A = NULL;
    new->B = NULL;
    new->num_A = 0;
    new->num_B = 0;
    return (new);
}

void	move_from_b_to_a(Stack **new)
{
    Unit *stack_a;

    while ((*new)->B)
    {
        find_rr_rra((*new)->A);
        find_rr_rra((*new)->B);
        find_two_pairs(new);
    }
    find_rr_rra((*new)->A);
    stack_a = find_min_struct_2(*new);
    if (stack_a->rr < stack_a->rra)
        while (stack_a->rr--)
            rotate(&(*new)->A, 1);
        else
            while (stack_a->rra--)
                reverse(&(*new)->A, 1);
}

void move_from_a_to_b(Stack *new)
{
    int size_of_new;

    size_of_new = new_size(new->A);
    while (size_of_new--)
    {
        if (!new->A->mark)
        {
            reverse(&new->A, 1);
            push_b(&new, 1);
        }
        else
            reverse(&new->A, 1);
    }
}

void	sort_stack(int len, Stack *new)
{
    if (len <= 3)
        sort_3(len, new);
    else if (len <= 5)
        sort_5(len, new);
    else
    {
        find_mark_1(new->A);
        move_from_a_to_b(new);
        move_from_b_to_a(&new);
    }
}