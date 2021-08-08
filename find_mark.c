#include "push_swap.h"

int count_mark(Unit *new)
{
    Unit	*tmp;
    int		count;

    count = 1;
    tmp  = new;
    new = new->next;
    if (new)
    {
        while (new->next)
        {
            if (new->num > tmp->num)
            {
                count++;
                tmp = new;
            }
            new = new->next;
        }
        if (new->num > tmp->num)
            count++;
    }
    return (count);
}

void	find_rr_rra(Unit *new)
{
    int size;
    int i;

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

void put_mark_2(Unit *curr, int count_dup, Unit *prev, Unit *new)
{
    if (curr)
    {
        while (curr->next)
        {
            if (prev->num > curr->num)
            {
                prev = curr;
                curr->mark = 1;
            }
            curr = curr->next;
        }
        if (prev->num > curr->num)
            curr->mark = 1;
    }
    while (count_dup--)
        rotate(&new, 0);
}

void put_mark(Unit *new, int num)
{
    Unit	*curr;
    int 	count;
    int		count_dup;
    Unit 	*prev;

    count = 0;
    curr = new;
    while (curr)
    {
        if (curr->num == num)
            break;
        count++;
        curr = curr->next;
    }
    count_dup = count;
    while (count--)
        reverse(&new, 0);
    prev = new;
    prev->mark = 1;
    curr = new->next;
    put_mark_2(curr, count_dup, prev, new);
//    if (curr)
//    {
//        while (curr->next)
//        {
//            if (prev->num > curr->num)
//            {
//                prev = curr;
//                curr->mark = 1;
//            }
//            curr = curr->next;
//        }
//        if (prev->num > curr->num)
//            curr->mark = 1;
//    }
//    while (count_dup--)
//        rotate(&new, 0);
}

void find_mark_1(Unit *new)
{
    int		count;
    int 	max;
    int 	i;
    int		num;

    i = 0;
    count = new_size(new);
    while (count--)
    {
        max = count_mark(new);
        if (i < max)
        {
            i = max;
            num = new->num;
        }
        rotate(&new, 0);
    }
    put_mark(new, num);
}

