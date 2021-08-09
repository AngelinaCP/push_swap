/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelena <ddelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 05:04:40 by ddelena           #+#    #+#             */
/*   Updated: 2021/04/28 19:09:53 by ddelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*find_chr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && find_chr(set, *s1))
		s1++;
	j = ft_strlen(s1);
	while (j && find_chr(set, s1[j]))
		j--;
	str = ft_substr((char *)s1, 0, j + 1);
	return (str);
}
