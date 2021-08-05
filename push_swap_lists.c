#include "push_swap.h"

typedef struct S_Unit
{
	int num;
	struct Unit *next;
	int index;
} Unit ;

typedef struct S_Stack
{
	struct Unit *A;
	struct Unit *B;
}				Stack ;

Stack *init_struct(void)
{
	Stack *new;

	new = (Stack *)malloc(sizeof(Stack *));
	if (!new)
		exit (1);
	new->A->num = 0;
	new->A->next = NULL;
	new->A->index = 0;
	new->A =
	new->B = NULL;
	return (new);
}

int find_max(Stack *stack)
{
	int	max;

	max = 0;
	while (stack->next != NULL)
	{
		if (stack->num > max)
			max = stack->num;
		stack = stack->next;
	}
	return (max);
}

void ft_swap(Stack *elem)
{
	int num;

	if (!elem)
		exit (1);
	num = elem->num;
	elem->num = elem->next->num;
	elem->next->num = num;
}

void sort_3(Stack *stack)
{
	int max;

	max = find_max(stack);
}

void check_num(int argc, Stack *stack)
{
	if (argc == 3 && (stack->num > stack->next->num))
		printf("cou");
		//ft_swap(*stack);
//	else if (argc == 4)
//		sort_3(stack);
}

Stack *init(int argc, char **argv)
{
	int i;
	Unit *stack;
	Unit *curr;

	stack = init_struct;();
	curr = stack;
	i = 1;
	curr = (Stack *)malloc(sizeof(Stack *));
	if (!curr)
		exit (1);
	while (i < argc)
	{
		curr->num = atoi(argv[i]);
		printf("%d\n", curr->num);
		if (argv[i + 1] != NULL)
		{
			curr->next = init_Stack();
			curr = curr->next;
		}
		i++;
	}
	return (stack);
}

int main(int argc, char **argv)
{
	Stack *deck;

	deck = init_struct();
	deck->A = init(argc, argv);
	printf("%d", deck->A->num);
//	check_num(argc, deck->A);
//	Stack	*curr = stackA;
//
//	while (curr != NULL)
//	{
//		printf("%d\n", curr->x);
//		curr = curr->next;
//	}
//	while(stackA->next != NULL)
//	{
//		printf("%d\n", stackA->x);
//		stackA = stackA->next;
//	}
//	if (check_if_sorted(argc, stackA))
//		return (0);
//	if (check_argv(argv))
//		return (0);
//	check_num(argc, stackA, stackB);
}