/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelena <ddelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:22:17 by ddelena           #+#    #+#             */
/*   Updated: 2021/04/29 21:37:17 by ddelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*str1;
	char	*str2;
	size_t	i;

	str1 = (char *)dst;
	str2 = (char *)src;
	i = 0;
	if (str1 == NULL && str2 == NULL)
		return (NULL);
	if (src < dst)
	{
		while (len > 0)
		{
			str1[len - 1] = str2[len - 1];
			len--;
		}
	}
	else
	{
		while (i++ < len)
			*str1++ = *str2++;
	}
	return (dst);
}
