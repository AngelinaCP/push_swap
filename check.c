#include "push_swap.h"

Unit	*init_Unit(void)
{
    Unit *tmp;

	tmp = (Unit *)malloc(sizeof(Unit));
	tmp->index = 0;
	tmp->next = NULL;
	tmp->num = 0;
	return (tmp);
}

int check_digit(char *split, int flag)
{
    int i;

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

int check_if_max(char *str)
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

int check_content(char *split)
{
    int i;
    int flag;
    int split_len;

    i = 0;
    flag = 0;
    split_len = ft_strlen(split);
    while (split[i])
    {
        if (split[i] == '+' || split[i] == '-')
        {
            flag = 1;
            if (check_digit(split, flag))
                return (1);
        }
        else
        {
            if (check_digit(split, flag))
                return (1);
        }
        i++;
    }
    if (split_len - flag > 10)
        return (1);
    else if (split_len - flag == 10)
    {
        if (check_if_max(split))
            return (1);
    }
    return (0);
}

int	check_split(char **split, Unit **tmp)
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

int	check_dup(Unit *tmp2)
{
	Unit	*tmp;

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

int	check_if_sorted(Unit *tmp)
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
	//write(1, "Sorted!\n", 8);
	return (1);
}

//int	check_max_min(char *str, int minus)
//{
//	char	*int_max;
//	char	*int_min;
//	char	*max_num;
//
//	int_max = "2147483647";
//	int_min = "2147483648";
//	if (ft_strlen(str) > 10)
//		return (0);
//	if (ft_strlen(str) < 10)
//		return (1);
//	if (minus)
//		max_num = int_min;
//	else
//		max_num = int_max;
//	if (ft_strncmp(str, max_num, 10) > 0)
//		return (0);
//	return (1);
//}

//int	check(char *str)
//{
//	int	i;
//	int	minus;
//
//	minus = 0;
//	i = 0;
//	if (str[i] == '-' || str[i] == '+')
//	{
//		if (str[i] == '-')
//			minus = 1;
//		i++;
//	}
//	while (ft_isdigit(str[i]))
//		i++;
//	if (i != (int) ft_strlen(str))
//		return (0);
//	return (check_max_min(str + minus, minus));
//}