/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiribar <xabieriribarrevuelta@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:59:50 by xiribar           #+#    #+#             */
/*   Updated: 2025/08/20 17:03:35 by xiribar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				index;
	unsigned char		*to;
	const unsigned char	*from;

	if (dst == src)
		return (dst);
	to = (unsigned char *)dst;
	from = (const unsigned char *)src;
	index = 0;
	while (index < n)
	{
		to[index] = from[index];
		index++;
	}
	return (dst);
}
