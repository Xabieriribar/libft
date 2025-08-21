/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiribar <xabieriribarrevuelta@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:59:50 by xiribar           #+#    #+#             */
/*   Updated: 2025/08/20 17:05:11 by xiribar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*bytes;

	bytes = (unsigned char *)s;
	index = 0;
	while (index < n)
	{
		bytes[index] = (unsigned char)c;
		index++;
	}
	return (s);
}
