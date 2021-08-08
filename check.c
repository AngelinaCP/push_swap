#include "push_swap.h"

t_Unit	*init_Unit(void)
{
	t_Unit	*tmp;

	tmp = (t_Unit *)malloc(sizeof(t_Unit));
	tmp->index = 0;
	tmp->next = NULL;
	tmp->num = 0;
	return (tmp);
}

int	check_digit(char *split, int flag)
{
	int	i;

	i = 0;
	if (flag == 1)
	{
		i = 1;
		while (split[i])
		{
			if (!ft_isdigit(split[i]))
				return (1);
			i++;
		}
	}
	else
	{
		while (split[i])
		{
			if (!ft_isdigit(split[i]))
				return (1);
			i++;
		}
	}
	return (0);
}

int	check_if_max(char *str)
{
	if (str[0] == '-')
	{
		if (ft_atoi(str) > 0)
			return (1);
	}
	else if (ft_atoi(str) < 0)
		return (1);
	return (0);
}

int	check_pos_neg(char *split)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (split[i])
	{
		if (split[i] == '+' || split[i] == '-')
		{
			flag = 1;
			if (check_digit(split, flag))
				exit(1);
		}
		else
		{
			if (check_digit(split, flag))
				exit(1);
		}
		i++;
	}
	return (flag);
}

int	check_content(char *split)
{
	int	flag;
	int	split_len;

	split_len = ft_strlen(split);
	flag = check_pos_neg(split);
	if (split_len - flag > 10)
		return (1);
	else if (split_len - flag == 10)
	{
		if (check_if_max(split))
			return (1);
	}
	return (0);
}
