#include "push_swap.h"

void	error(void)
{
	write(1, "Error", 5);
	exit (1);
}

void	free_array(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[++i]);
	free(split);
}

t_Unit	*split_argv(int argc, char **argv)
{
	int		i;
	char	**split;
	t_Unit	*tmp;
	t_Unit	*tmp2;

	i = 1;
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
		free_array(split);
	}
	reverse_root(&tmp2);
	return (tmp2);
}

void	reverse_root(t_Unit **root)
{
	t_Unit	*prev;
	t_Unit	*curr;
	t_Unit	*next;

	prev = NULL;
	curr = *root;
	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*root = prev;
}

int	count_num_argv(char *argv)
{
	int	count;

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
