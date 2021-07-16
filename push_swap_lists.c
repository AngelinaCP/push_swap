#include "push_swap.h"


typedef struct Stack
{
	int x;
	struct Stack *next;
} Stack;

int main(int argc, char **argv)
{
	int i;
	Stack *stackA;
	//Stack *stackB;

	i = 1;
	stackA = malloc(sizeof(Stack));
	while (i < argc)
	{
		stackA->x = atoi(argv[i]);
		stackA = stackA->next;
		i++;
	}
	Stack	*curr = stackA;

	while (curr != NULL)
	{
		printf("%d\n", curr->x);
		curr = curr->next;
	}
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