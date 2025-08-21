/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiribar <xabieriribarrevuelta@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:41:52 by xiribar           #+#    #+#             */
/*   Updated: 2025/08/20 16:45:44 by xiribar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*app_de(t_list **head, t_list *node, void (*del)(void *), void *content)
{
	if (!node)
	{
		del(content);
		ft_lstclear(head, del);
		return (NULL);
	}
	if (!*head)
		*head = node;
	else
		ft_lstlast(*head)->next = node;
	return (*head);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*node;
	void	*content;

	if (!del || !f)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		content = f(lst->content);
		node = ft_lstnew(content);
		if (!app_de(&new_lst, node, del, content))
			return (NULL);
		lst = lst -> next;
	}
	return (new_lst);
}
