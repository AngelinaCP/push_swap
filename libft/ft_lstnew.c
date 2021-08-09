/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelena <ddelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:23:36 by ddelena           #+#    #+#             */
/*   Updated: 2021/04/27 01:24:05 by ddelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lt;

	lt = (t_list *)malloc(sizeof(t_list *));
	if (lt == NULL)
		return (NULL);
	lt -> content = content;
	lt -> next = NULL;
	return (lt);
}
