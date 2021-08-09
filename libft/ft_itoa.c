/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelena <ddelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 04:16:26 by ddelena           #+#    #+#             */
/*   Updated: 2021/04/29 15:21:30 by ddelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	str_length(long n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

long	ft_check(long s, char *str)
{
	if (s < 0)
	{
		str[0] = '-';
		s = s * -1;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		count;
	long	s;

	s = n;
	count = str_length(s);
	str = ((char *)malloc(sizeof(char) * (count + 1)));
	if (!str)
		return (NULL);
	str[count--] = '\0';
	if (s == 0)
	{
		str[0] = '0';
		return (str);
	}
	s = ft_check(s, str);
	while (s > 0)
	{
		str[count--] = s % 10 + '0';
		s = s / 10;
	}
	return (str);
}
