#include "push_swap.h"

typedef struct	S_Unit
{
	int num;
	int	index;
	int len;
	int mark;
	struct S_Unit *next;
}				Unit;

typedef struct	S_Stack
{
	Unit *A;
	Unit *B;
	int	num_A;
	int num_B;
}				Stack;

void init_Stack(Stack *new)
{
	new->A = NULL;
	new->B = NULL;
	new->num_A = 0;
	new->num_B = 0;
}

//int check_argv(char **argv)
//{
//
//}

int count_num_argv(char *argv)
{
	int count;

	count = 0;
	while (*argv)
	{
		if (*argv != '\t' && *argv != ' ' && *argv != '\0')
		{
			while (*argv != '\t' && *argv != ' ' && *argv != '\0')
			{
				argv++;
			}
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

	i = 0;
	while (split[i])
	{
		(*tmp)->num = ft_atoi(split[i]);
	//	printf("%d ", (*curr)->num);
		if (split[i + 1] != NULL)
		{
			(*tmp)->next = init_Unit(*tmp);
			*tmp = (*tmp)->next;
		}
		i++;
	}
	//printf("%d ", (*curr)->num);
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
			if (tmp->num > tmp->next->num)
				return (0);
		}
		tmp = tmp->next;
	}
	write(1, "Sorted!\n", 8);
	return (1);
}

Unit	*split_argv(int argc, char **argv)
{
	int i;
	char **split;
	Unit *tmp;
	Unit *tmp2;

	i = 1;
	tmp = NULL;
	split = NULL;
	tmp2 = init_Unit(tmp);
	tmp = tmp2;
	tmp2->len = 0;
	while (i < argc)
	{
		tmp2->len += count_num_argv(argv[i]);
		split = ft_split(argv[i], ' ');
		check_split(split, &tmp);
		if (i < argc - 1)
		{
			tmp->next = init_Unit(tmp);
			tmp = tmp->next;
		}
			//free (split);
		i++;
	}
	return (tmp2);
}

void ft_swap(Unit **new, int num)
{
	int tmp;

	tmp = (*new)->num;
	(*new)->num = (*new)->next->num;
	(*new)->next->num = tmp;
	if (num == 1)
		write(1, "sa\n", 3);
}

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

void rotate(Unit **new, int num)
{
	//shift up
	Unit *tmp;
	Unit *prev;

	//ft_putstr_fd(str, 1);
	prev = *new;
	tmp = *new;
	if (!tmp->next)
		return ;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	tmp->next = *new;
	*new = tmp;
	//printf("%d ", (*new)->num);
//	Unit *first;
//	Unit *curr;
//	Unit *tmp;
//
//	tmp = *new;
//	first = (*new)->next;
//	curr = *new;
//	while (curr->next)
//		curr = curr->next;
//	tmp->next = NULL;
//	curr->next = tmp;
//	*new = first;
	if (num == 1)
		write(1, "ra\n", 3);
	if (num == 2)
		write(1, "rb\n", 3);
}

void rr(Unit **new)
{
	rotate(new, 1);
	rotate(new, 2);
}

void	reverse(Unit **new, int num)
{
	Unit *first;
	Unit *last;

	first = *new;
	if (first->next)
	{
		*new = (*new)->next;
		first->next = NULL;
	}
	else
		return ;
	last = *new;
	while (last->next)
		last = last->next;
	last->next = first;
	
//	Unit	*last;
//	Unit	*tmp;
//	Unit 	*curr;
//
//	tmp = *new;
//	curr = *new;
//	while (curr->next->next)
//		curr = curr->next;
//	last = curr->next;
//	curr->next = NULL;
//	last->next = tmp;
//	*new = last;
	if (num == 1)
		write(1, "rra\n", 4);
	if (num == 2)
		write(1, "rrb\n", 4);
}

void rrr(Unit **new)
{
	reverse(new, 1);
	reverse(new, 2);
}

void push_b(Stack *new)
{
	Unit *buf;

	if (new == NULL)
		return ;
	new->num_A--;
	new->num_B++;
	buf = new->A;
	new->A = new->A->next;
	buf->next = new->B;
	new->B = buf;
}

void push_a(Stack *new)
{
	Unit *buf;

	if (new == NULL)
		return ;
	new->num_A++;
	new->num_B--;
	buf = new->B;
	new->B = new->B->next;
	buf->next = new->A;
	new->A = buf;
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

void put_mark(Unit **new, int num)
{
	Unit	*curr;
	int 	count;
	int		count_dup;
	Unit 	*prev;

	count = 0;
	curr = *new;
//	while ((*new)->next)
//	{
//		printf("%d ", (*new)->num);
//		*new = (*new)->next;
//	}
	while (curr)
	{
		if (curr->num == num)
			break;
		count++;
		curr = curr->next;
	}
	count_dup = count;
	while (count--)
		reverse(new, 1);
	prev = *new;
	prev->mark = 1;
	curr = (*new)->next;
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
			prev = curr;
	}
//	while ((*new)->next)
//	{
//		printf("%d ", (*new)->num);
//		*new = (*new)->next;
//	}
	while (count_dup--)
		rotate(new, 1);
//	 while ((*new)->next)
//	 {
//	 	printf("%d ", (*new)->num);
//	 	*new = (*new)->next;
//	 }
}

void move_from_a_to_b(Stack *new)
{
	int size_of_new;

	size_of_new = new_size(new->A);
	while (size_of_new--)
	{
		if (new->A->mark)
			rotate(&new->A, 1);
		else
		{
			rotate(&new->A, 1);
			push_b(new);
		}
	}
}

void find_mark(Unit **new)
{
	int		count;
	int 	max;
	int 	i;
	int		num;

	i = 0;
	count = new_size(*new);
	while (count--)
	{
		max = count_mark(*new);
		if (i < max)
		{
			i = max;
			num = (*new)->num;
		}
		rotate(new, 0);
	}
	while ((*new)->next)
	{
		printf("%d ", (*new)->num);
		*new = (*new)->next;
	}
	put_mark(new, num);
}

void	sort_stack(int len, Stack *new)
{
	if (len <= 3)
		sort_3(len, new);
	else if (len <= 5)
		sort_5(len, new);
	else
	{
		find_mark(&new->A);
//		while ((*new).A->next)
//		{
//			printf("%d ", (*new).A->num);
//			(*new).A = (*new).A->next;
//		}
	//	move_from_a_to_b(new);
	}

}

int main(int argc, char **argv)
{
	if (argc < 2)
		exit (1);
	Stack *new;

	if (!(new = (Stack *)malloc(sizeof(Stack))))
		exit (1);
	init_Stack(new);
//	if (check_argv(argv))
	new->A = split_argv(argc, argv);
	if (check_dup(new->A))
		exit (1);
	if (check_if_sorted(new->A))
		exit (1);
	sort_stack(new->A->len, new);
	while (new->A)
	{
		printf("%d ", new->A->num);
		new->A = new->A->next;
	}
	//printf("%d", new->A->len);
//	printf("|%d|", new->A->len);
	//printf("cou");
}

