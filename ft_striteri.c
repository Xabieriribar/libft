/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiribar <xabieriribarrevuelta@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:59:50 by xiribar           #+#    #+#             */
/*   Updated: 2025/08/20 17:19:59 by xiribar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int     index;

	if (!s || !f)
		return ;
	index = 0;
	while(s[index] != '\0')
	{
		f(index, &s[index]);
		index++;
	}
}
