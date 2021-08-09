/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelena <ddelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 06:43:44 by ddelena           #+#    #+#             */
/*   Updated: 2021/04/27 19:27:22 by ddelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ls;
	t_list	*lsp;

	if (!lst || !f)
		return (NULL);
	ls = ft_lstnew(f(lst -> content));
	if (!ls)
		return (NULL);
	lsp = ls;
	lst = lst -> next;
	while (lst)
	{
		lsp -> next = ft_lstnew((f(lst -> content)));
		if (!(lsp -> next))
		{
			del(lsp);
			free(lsp);
			return (NULL);
		}
		lsp = lsp -> next;
		lst = lst -> next;
	}
	return (ls);
}
