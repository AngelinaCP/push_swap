#include "push_swap.h"

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
    push_b(&new, 1);
    sort_4_num(new);
    push_a(new, 1);
}

void	sort_5(int len, Stack *new)
{
    if (len == 4)
        sort_4_num(new);
    else if (len == 5)
        sort_5_num(new);
}