/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelena <ddelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:58:59 by ddelena           #+#    #+#             */
/*   Updated: 2021/04/29 21:34:33 by ddelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{	
	size_t	i;
	char	*str1;
	char	*str2;

	str1 = (char *) src;
	str2 = (char *) dst;
	i = 0;
	if (!dst && !src)
		return (dst);
	while (i < n)
	{
		str2[i] = str1[i];
		i++;
	}
	return (dst);
}
