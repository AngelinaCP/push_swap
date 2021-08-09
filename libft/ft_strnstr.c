/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelena <ddelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:34:37 by ddelena           #+#    #+#             */
/*   Updated: 2021/04/28 16:01:34 by ddelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!haystack && !needle)
		return (NULL);
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[count] && count < len)
	{
		i = 0;
		while (count + i < len && needle[i] && haystack[i + count] == needle[i])
		{
			i++;
			if (needle[i] == '\0')
				return ((char *)haystack + count);
		}
		count++;
	}
	return (0);
}
