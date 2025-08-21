/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiribar <xabieriribarrevuelta@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:41:52 by xiribar           #+#    #+#             */
/*   Updated: 2025/08/20 16:57:20 by xiribar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*haystack;
	unsigned char	needle;
	size_t			index;

	haystack = (const unsigned char *)s;
	needle = (unsigned char)c;
	index = 0;
	while (index < n)
	{
		if (haystack[index] == needle)
			return ((void *)haystack + index);
		index++;
	}
	return (NULL);
}
