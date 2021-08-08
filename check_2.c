#include "push_swap.h"

int	check_if_sorted(t_Unit *tmp)
{
	while (tmp)
	{
		if (tmp->next)
		{
			if (tmp->num < tmp->next->num)
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

int	check_split(char **split, t_Unit **tmp)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (check_content(split[i]))
			return (1);
		(*tmp)->num = ft_atoi(split[i]);
		if (split[i + 1] != NULL)
		{
			(*tmp)->next = init_Unit();
			*tmp = (*tmp)->next;
		}
		i++;
	}
	return (0);
}

int	check_dup(t_Unit *tmp2)
{
	t_Unit	*tmp;

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
