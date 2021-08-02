#include "push_swap.h"

static void	run_comands(char *com, t_all *res)
{
	if (ft_strncmp(com, "sa", 3) == 0)
		swap_ab(res->deck_a, 0);
	else if (ft_strncmp(com, "sb", 3) == 0)
		swap_ab(res->deck_b, 0);
	else if (ft_strncmp(com, "pa", 3) == 0)
		push_a(res, 0);
	else if (ft_strncmp(com, "pb", 3) == 0)
		push_b(res, 0);
	else if (ft_strncmp(com, "ra", 3) == 0)
		rotate_ab(&res->deck_a, 0);
	else if (ft_strncmp(com, "rb", 3) == 0)
		rotate_ab(&res->deck_b, 0);
	else if (ft_strncmp(com, "rra", 4) == 0)
		reverse_rra_rrb(&res->deck_a, 0);
	else if (ft_strncmp(com, "rrb", 4) == 0)
		reverse_rra_rrb(&res->deck_b, 0);
	else
		exit_error_msg();
}

static void	read_comands(t_all *res)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		run_comands(line, res);
		free(line);
	}
	free(line);
}

void	ft_lstadd_front_checker(t_stack **lst, t_stack *new)
{
	if (lst)
	{
		if (*lst)
		{
			new->next = *lst;
		}
		*lst = new;
	}
}

int	main(int argc, char **argv)
{
	t_all	*res;
	int		len;

	if (argc < 2)
		exit(1);
	res = init_new_all();
	res->deck_a = copy_argv_stack(argc, argv);
	res->deck_b = init_new_unit();
	if (!res->deck_a || !res->deck_b)
		exit_error_msg();
	len = struct_len(res->deck_a);
	while (--len > 0)
		ft_lstadd_front_checker(&res->deck_b, init_new_unit());
	fast_sort(&res, len, 0);
	read_comands(res);
	if (!ft_sorted_list(res, len))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	struct_free(res);
	free(res);
	return (0);
}
