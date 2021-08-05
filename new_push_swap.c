#include "push_swap.h"

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

void error()
{
   // write(1, "Error", 5);
	exit (1);
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

int count_num_argv(char *argv)
{
	int count;

	count = 0;
	while (*argv)
	{
		if (*argv != '\t' && *argv != ' ' && *argv != '\0')
		{
			while (*argv != '\t' && *argv != ' ' && *argv != '\0')
				argv++;
			count++;
		}
		else
			argv++;
	}
	return (count);
}

void reverse_root(Unit **root)
{
	Unit *prev = NULL;
	Unit *curr = *root;

	while (curr != NULL)
	{
		Unit *next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*root = prev;
}


Unit	*split_argv(int argc, char **argv)
{
	int		i;
	char	**split;
	Unit 	*tmp;
	Unit	*tmp2;
	Unit	*new;

	i = 1;
	new = NULL;
	split = NULL;
	tmp2 = init_Unit();
	tmp = tmp2;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (check_split(split, &tmp))
			error();
		if (i < argc - 1)
		{
			tmp->next = init_Unit();
			tmp = tmp->next;
		}
		i++;
	}
	reverse_root(&tmp2);
	return (tmp2);
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

void move_from_a_to_b(Stack *new)
{
	int size_of_new;

	size_of_new = new_size(new->A);
	while (size_of_new--)
	{
		if (!new->A->mark)
		{
		     reverse(&new->A, 1);
			push_b(&new);
			//reverse(&new->A, 1);
			//changed rotate
		//rotate(&new->A, 1);
		}
		else
			reverse(&new->A, 1);
		//changed reverse
	}
}

void find_mark(Unit *new)
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
		//rotate
	}
	put_mark(new, num);
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

Unit	*find_pair_from_a(Unit *new, int num)
{

	Unit *prev;
	Unit *tmp;

	prev = new;
	tmp = new->next;
	while (tmp)
	{
		if (prev->num > num && tmp->num < num)
		{
			return (prev);
		}

		prev = tmp;
		tmp = tmp->next;
	}
	if (find_max_struct(new)->num < num)
	{
		return (find_min_struct(new));
	}
	if (new->num < num)
	{
		while (new->next)
			new = new->next;
		return (new);
	}
	return (find_min_struct(new));
}

int find_max_ab(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
int min_steps(Unit *stack_a, Unit *stack_b)
{
	int rr;
	int rrr;
	int	ra_a_rra_b;
	int ra_b_rrs_a;

	rr = find_max_ab(stack_a->rr, stack_b->rr);
	rrr = find_max_ab(stack_a->rra, stack_b->rra);
	ra_b_rrs_a = stack_b->rr + stack_a->rra;
	ra_a_rra_b = stack_a->rr + stack_b->rra;
	if (rr <= rrr && rr <= ra_a_rra_b && rr <= ra_b_rrs_a)
		return (rr);
	if (rrr <= rr && rrr <= ra_a_rra_b && rrr <= ra_b_rrs_a)
		return (rrr);
	if (ra_a_rra_b <= rr && ra_a_rra_b <= rrr && ra_a_rra_b <= ra_b_rrs_a)
		return (ra_a_rra_b);
	if (ra_b_rrs_a <= rr && ra_b_rrs_a <= rrr && ra_b_rrs_a <= ra_a_rra_b)
		return (ra_b_rrs_a);
	return (ra_a_rra_b);
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

void	sort_stack(int len, Stack *new)
{
	if (len <= 3)
		sort_3(len, new);
	else if (len <= 5)
		sort_5(len, new);
	else
	{
		find_mark(new->A);
		move_from_a_to_b(new);
		move_from_b_to_a(&new);
	}
}

int is_sorted(Unit *cur)
{
	Unit *prev;

	prev = cur;
	if (cur)
		cur = cur->next;
	else
		return 1;
	if (cur)
	{
		if (prev->num < cur->num)
			return (0);
		while (cur->next)
		{
			if (prev->num < cur->num)
				return (0);
			prev = cur;
			cur = cur->next;
		}
		if (prev->num < cur->num)
			return (0);
	}
	return (1);
}

int main(int argc, char **argv)
{
	if (argc < 2)
		exit (1);
	Stack *new;
	int len;
	int i;
	Unit *tmp;

	i = 0;
	int j = 0;
	len = 0;
	new = init_Stack();
	new->A = split_argv(argc, argv);
	if (check_dup(new->A))
		error();
	if (check_if_sorted(new->A))
		exit (1);
    tmp = new->A;
    while (tmp)
    {
        j++;
        tmp = tmp->next;
    }
	//sort_stack(j, new);
//	if (is_sorted(new->A))
//	    printf("Sorted\n");
	while (new->A )
	{
		printf("%d ", new->A->num);
		new->A = new->A->next;
	}
}
