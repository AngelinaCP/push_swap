#include "push_swap.h"

int find_max_ab(int a, int b)
{
    if (a > b)
        return (a);
    return (b);
}

Unit *find_max_struct(Unit *new)
{
    Unit *curr;
    Unit *tmp;

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

Unit *find_min_struct(Unit *new)
{
    int min;
    Unit *curr;
    Unit *tmp;

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

Unit *find_min_struct_2(Stack *new)
{
    int min;
    Unit *curr;
    Unit *tmp;

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

int new_size(Unit *new)
{
    int i;

    i = 0;
    while (new)
    {
        i++;
        new = new->next;
    }
    return (i);
}

