/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:16:23 by crtorres          #+#    #+#             */
/*   Updated: 2022/09/30 19:22:51 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It takes a list, applies a function to each element of the list, and returns a
 * new list with the results of the function
 * 
 * @param lst A pointer to the first node of a linked list.
 * @param f a function that takes a void pointer and returns a void pointer
 * @param del a function that frees the memory of the content of a link.
 * 
 * @return A pointer to the first element of the new list.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newnode;
	t_list	*newlst;

	if (lst == 0 || f == 0)
		return (0);
	newlst = 0;
	while (lst)
	{
		newnode = (ft_lstnew((f)(lst -> content)));
		if (!newnode)
		{
			ft_lstclear(&newnode, del);
			return (0);
		}
		ft_lstadd_back(&newlst, newnode);
		lst = lst -> next;
	}
	return (newlst);
}
