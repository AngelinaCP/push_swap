#include "push_swap.h"

void init_Stack(Stack *new)
{
	new->A = NULL;
	new->B = NULL;
	new->num_A = 0;
	new->num_B = 0;
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
		if (curr->next)
		{
			if (min > curr->next->num)
			{
				min = curr->next->num;
				tmp = curr;
			}
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

Unit *init_Unit(Unit *tmp)
{
	tmp = (Unit *)malloc(sizeof(Unit));
	tmp->index = 0;
	tmp->next = NULL;
	tmp->num = 0;
	return (tmp);
}

void check_split(char **split, Unit **tmp)
{
	int i;
	//Unit *new;

	i = 0;
	//new = NULL;
	while (split[i])
	{
		(*tmp)->num = ft_atoi(split[i]);
		if (split[i + 1] != NULL)
		{
			(*tmp)->next = init_Unit(*tmp);
			*tmp = (*tmp)->next;
		}
		i++;
	}
}

int check_dup(Unit *tmp2)
{
	Unit *tmp;

	while (tmp2)
	{
		if (tmp2->next)
			tmp = tmp2->next;
		else
			break ;
		while (tmp)
		{
			if (tmp->num == tmp2->num)
				return (1);
			tmp = tmp->next;
		}
		tmp2 = tmp2->next;
	}
	return (0);
}

int check_if_sorted(Unit *tmp)
{
	while (tmp->next)
	{
		if (tmp->next)
		{
			if (tmp->num < tmp->next->num)
				return (0);
		}
		tmp = tmp->next;
	}
	write(1, "Sorted!\n", 8);
	return (1);
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
	int i;
	char **split;
	Unit *tmp;
	Unit *tmp2;
	Unit *new;

	i = 1;
	new = NULL;
	tmp = NULL;
	split = NULL;
	tmp2 = init_Unit(tmp);
	tmp = tmp2;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		check_split(split, &tmp);
		if (i < argc - 1)
		{
			tmp->next = init_Unit(tmp);
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
			if (new->num < tmp->num)
			{
				count++;
				tmp = new;
			}
			new = new->next;
		}
		if (new->num < tmp->num)
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
	 int max;
	 Unit *curr;
	 Unit *tmp;

	 max = new->num;
	 curr = new;
	 tmp = new;
	 while (curr->next)
	 {
		if (tmp->num < curr->num)
			tmp = curr;
	 	curr = curr->next;
	 }
//	 printf("|%d|\n", tmp->num);
	 return (tmp);
//	Unit *maxx;
//
//	maxx = new;
//	Unit *tmp = new;
//	while (new)
//	{
//		if (maxx->num < new->num)
//			maxx->num = new->num;
//		new = new->next;
//	}
//	return (maxx);
}

Unit *find_min_struct(Unit *new)
{
	 int min;
	 Unit *curr;
	 Unit *tmp;

	 min = new->num;
	 curr = new;
	 tmp = new;
	 while (curr)
	 {
	 	if (curr->next)
	 	{
	 		if (min > curr->next->num)
	 		{
	 			min = curr->next->num;
	 			tmp = curr;
	 		}
	 	}
	 	curr = curr->next;
	 }
	 return (tmp);
//	Unit *min;
//
//	min = new;
//	while (new)
//	{
//		if (min->num > new->num)
//			min->num = new->num;
//		new = new->next;
//	}
//	return (min);

}

void move_from_a_to_b(Stack *new)
{
	int size_of_new;

	size_of_new = new_size(new->A);
	while (size_of_new--)
	{
		if (!new->A->mark)
		{
			push_b(new);
			rotate(&new->A, 1);
		}
		else
			rotate(&new->A, 1);
	}
//	while (new->B)
//	{
//		printf("%d ", new->B->num);
//		new->B = new->B->next;
//	}
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
	}
	put_mark(new, num);
}

void	find_rr_rra(Unit *new)
{
	int size;
	int i;
	Unit *tmp;

	i = 1;
	tmp = new;
	size = new_size(new);
	//printf("size: %d\n", size);
	while (new)
	{
		new->rr = size - 1;
		new->rra = i;
		i++;
		new = new->next;
	}
//	printf("|1: %d\n", new->rr);
//	printf("|1: %d\n", new->rra);
}

Unit	*find_pair_from_a(Unit *new, int num)
{
	//	(void)num;
	Unit *prev;
	Unit *curr;
	Unit *tmp;

	prev = new;
	curr = new;
	//if (tmp->next)
	tmp = new->next;
	while (tmp)
	{
		if (prev->num > num && tmp->num < num)
			return (prev);
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
	ra_a_rra_b = stack_a->rr + stack_b->rra;
	ra_b_rrs_a = stack_b->rr + stack_a->rra;
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

void do_rr(Stack *stack_a, Unit *stack_b, Unit *tmp_a, Unit *tmp_b)
{
//	printf("4: %d\n", tmp_a->rr);
//	printf("4: %d\n", tmp_b->rra);
//	printf("\n");
//	(void)tmp_a;
//	(void)tmp_b;
//	(void)stack_a;
	(void)stack_b;
	while (tmp_a->rr > 0 && tmp_b->rr > 0)
	{
		rrr(&stack_a->A, &stack_a->B);
		tmp_a->rr--;
		tmp_b->rr--;
	}
	while (tmp_a->rr-- > 0)
		reverse(&stack_a->A, 1);
	while (tmp_b->rr-- > 0)
		reverse(&stack_a->B, 2);

//	while (tmp_a->rr-- > 0 && tmp_b->rr-- > 0)
//		rr(&stack_a->A, &stack_a->B);
//	while (tmp_a->rr-- > 0)
//		rotate(&stack_a->A, 1);
//	while (tmp_b->rr-- > 0)
//		rotate(&stack_a->B, 2);
}

void do_rrr(Stack *stack_a, Unit *stack_b, Unit *tmp_a, Unit *tmp_b)
{
	(void)stack_b;
	while (tmp_a->rra > 0 && tmp_b->rra > 0)
	{
			rrr(&stack_a->A, &stack_a->B);
			tmp_a->rra--;
			tmp_b->rra--;
	}
	while (tmp_a->rra-- > 0)
		rotate(&stack_a->A, 1);
	while (tmp_b->rra-- > 0)
		rotate(&stack_a->B, 2);

//	(void)stack_b;
//	while (tmp_a->rra-- > 0 && tmp_b->rra-- > 0)
//		rrr(&stack_a->A, &stack_a->B);
//	while (tmp_a->rra-- > 0)
//		reverse(&stack_a->A, 1);
//	while (tmp_b->rra-- > 0)
//		reverse(&stack_b, 2);
}

void do_ra_a_rra_b(Stack *stack_a, Unit *stack_b, Unit *tmp_a, Unit *tmp_b)
{
	(void)stack_b;
	while (tmp_b->rr > 0)
	{
		rotate(&stack_a->B, 2);
		tmp_b->rr--;
	}
	while (tmp_a->rra > 0)
	{
		reverse(&stack_a->A, 1);
		tmp_a->rra--;
	}

//	(void)stack_b;
//	while (tmp_a->rr > 0)
//	{
//		rotate(&stack_a->A, 1);
//		tmp_a->rr--;
//	}
//	while (tmp_b->rra > 0)
//	{
//		reverse(&stack_a->B, 2);
//		tmp_b->rra--;
//	}
}

void do_ra_b_rra_a(Stack *stack_a, Unit *stack_b, Unit *tmp_a, Unit *tmp_b)
{
	(void)stack_b;
	while (tmp_a->rr > 0)
	{
		rotate(&stack_a->A, 1);
		tmp_a->rr--;
	}
	while (tmp_b->rra > 0)
	{
		reverse(&stack_a->B, 2);
		tmp_b->rra--;
	}

//	(void)stack_b;
//	while (tmp_b->rr > 0)
//	{
//		rotate(&stack_a->B, 2);
//		tmp_b->rr--;
//	}
//	while (tmp_a->rra > 0)
//	{
//		reverse(&stack_a->A, 1);
//		tmp_a->rra--;
//	}
}

void do_operations(Unit *tmp_a, Unit *tmp_b, Stack **stack_a, Stack *stack_b, Stack *new)
{
	int rr;
	int rrr;
	int	ra_a_rra_b;
	int ra_b_rrs_a;

	(void)tmp_a;
	(void)tmp_b;
	(void)stack_a;
	(void)stack_b;
	(void)new;
//	rr = find_max_ab((*tmp_a).rra, (*tmp_b).rra);
//	rrr = find_max_ab((*tmp_a).rr, (*tmp_b).rr);
	rrr = find_max_ab((*tmp_a).rra, (*tmp_b).rra);
	rr = find_max_ab((*tmp_a).rr, (*tmp_b).rr);
	ra_a_rra_b = (*tmp_b).rra + (*tmp_a).rr;
	ra_b_rrs_a = (*tmp_a).rra + (*tmp_b).rr;
	printf("rr %d rrr %d|\n", rr, rrr);
//	if (rr <= rrr && rr <= ra_a_rra_b && rr <= ra_b_rrs_a)
//		do_rr((*stack_a), (*stack_a)->B, tmp_a, tmp_b);
//	else if (rrr <= rr && rrr <= ra_a_rra_b && rrr <= ra_b_rrs_a)
//		do_rrr((*stack_a), (*stack_a)->B, tmp_a, tmp_b);
//	else if (ra_a_rra_b <= rr && ra_a_rra_b <= rrr && ra_a_rra_b <= ra_b_rrs_a)
		do_ra_a_rra_b((*stack_a), (*stack_a)->B, tmp_a, tmp_b);
//	else if (ra_b_rrs_a <= rr && ra_b_rrs_a <= rrr && ra_b_rrs_a <= ra_a_rra_b)
		do_ra_b_rra_a((*stack_a), (*stack_a)->B, tmp_a, tmp_b);
//	push_a(new);
}

void find_two_pairs(Stack **new)
{
	Unit	*stack_a;
	Unit	*stack_b;
	Unit	tmp_a;
	Unit 	tmp_b;
	int		steps;

	(void)tmp_a;
	(void)tmp_b;
	(void)stack_a;
	(void)stack_b;
	(void)steps;
	steps = 2147483647;
	stack_b = (*new)->B;
	while (stack_b)
	{
	//	printf("%d ", stack_b->num);
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
	(void)new;
//	Unit *stack_a;

	while ((*new)->B)
	{
//		printf("%d ", (*new)->B->num);
		 find_rr_rra((*new)->A);
		 find_rr_rra((*new)->B);
		 find_two_pairs(new);
		(*new)->B = (*new)->B->next;
	}
	// find_rr_rra((*new)->A);
	// stack_a = find_min_struct_2(*new);
//	printf("%d\n", stack_a->next->rr);
//	printf("%d\n", stack_a->next->rra);
//	printf("%d\n", new->B->num);
//	while (new->B)
//	{
//		printf("%d\n", new->B->num);
//		new->B = new->B->next;
//	}
//	if (stack_a->rr > stack_a->rra)
//		while (stack_a->rra-- > 0)
//			rr(&(*new)->A, &(*new)->B);
//	else
//		while (stack_a->rr-- > 0)
//			rrr(&(*new)->A, &(*new)->B);
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
//		while (new->A)
//		{
//			printf("%d ", new->A->num);
//			new->A = new->A->next;
//		}
	}

}

int main(int argc, char **argv)
{
	if (argc < 2)
		exit (1);
	Stack *new;
	int len;
	int i;

	i = 0;
	len = 0;
	if (!(new = (Stack *)malloc(sizeof(Stack))))
		exit (1);
	init_Stack(new);
	new->A = split_argv(argc, argv);
	if (check_dup(new->A))
		exit (1);
	if (check_if_sorted(new->A))
		exit (1);
	while (i++ < argc - 1)
		len += count_num_argv(*argv);
	sort_stack(len, new);
	while (new->A)
	{
		printf("%d ", new->A->num);
		new->A = new->A->next;
	}
	printf("\n------------\n");
//	while (new->B)
//	{
//		printf("%d ", new->B->num);
//		new->B = new->B->next;
//	}
}
