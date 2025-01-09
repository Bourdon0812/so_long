/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:49:42 by ilbonnev          #+#    #+#             */
/*   Updated: 2024/11/09 16:43:04 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*res;

	first = NULL;
	while (lst != NULL)
	{
		res = ft_lstnew(f(lst->content));
		if (res == NULL)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&first, res);
		lst = lst->next;
	}
	return (first);
}
