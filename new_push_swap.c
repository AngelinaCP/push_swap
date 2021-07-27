#include "push_swap.h"

void init_Stack(Stack *new)
{
	new->A = NULL;
	new->B = NULL;
	new->num_A = 0;
	new->num_B = 0;
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

void put_mark(Unit **new, int num)
{
	Unit	*curr;
	int 	count;
	int		count_dup;
	Unit 	*prev;

	count = 0;
	curr = *new;
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
			curr->mark = 1;
	}
	while (count_dup--)
		rotate(new, 1);
}

void move_from_a_to_b(Stack *new)
{
	int size_of_new;


	size_of_new = new_size(new->A);
	while (size_of_new--)
	{
		if (!new->A->mark)
		{
		//	reverse(&new->A, 1);
			push_b(new);
		}
		else
			reverse(&new->A, 1);
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
	put_mark(new, num);
}

void	move_from_b_to_a(Stack *new)
{
	(void)new;
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
		move_from_a_to_b(new);
		move_from_b_to_a(new);
//		while (new->A)
//		{
//			if (new->A->mark)
//				printf("%d", new->A->num);
//		//	printf("%d ", new->A->num);
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
}

