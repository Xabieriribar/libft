/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiribar <xabieriribarrevuelta@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:39:23 by xiribar           #+#    #+#             */
/*   Updated: 2025/08/20 16:40:13 by xiribar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*temp1;

	if (!lst || !del)
		return ;
	temp = *lst;
	while (temp != NULL)
	{
		temp1 = temp->next;
		ft_lstdelone(temp, del);
		temp = temp1;
	}
	*lst = NULL;
}
