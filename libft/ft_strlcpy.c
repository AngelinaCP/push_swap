/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelena <ddelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:14:39 by ddelena           #+#    #+#             */
/*   Updated: 2021/04/28 16:54:48 by ddelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			i;
	size_t			j;

	j = 0;
	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i])
		{		
			dst[i] = src[i];
			i++;
		}
		if (dstsize)
			dst[i] = '\0';
	}
	return (ft_strlen(src));
}
