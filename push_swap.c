#include "push_swap.h"

void	free_stack2(t_Stack *new)
{
	t_Unit	*tmp;

	while (new->A)
	{
		tmp = new->A->next;
		new->A = new->A->next;
		free(tmp);
	}
	while (new->B)
	{
		tmp = new->B->next;
		new->B = new->B->next;
		free(tmp);
	}
	free (new);
}

int	main(int argc, char **argv)
{
	int		j;
	t_Stack	*new;
	t_Unit	*tmp;

	if (argc < 2)
		exit (1);
	new = init_Stack();
	new->A = split_argv(argc, argv);
	if (check_dup(new->A))
		error();
	if (check_if_sorted(new->A))
		exit (1);
	tmp = new->A;
	j = new_size(tmp);
	sort_stack(j, new);
	free_stack(&(new)->A);
}
