/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiribar <xabieriribarrevuelta@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:59:50 by xiribar           #+#    #+#             */
/*   Updated: 2025/08/20 17:12:27 by xiribar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	i;

	dlen = 0;
	while (dlen < dstsize && dst[dlen] != '\0')
		dlen++;
	if (dlen == dstsize)
		return (dstsize + ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && dlen + i + 1 < dstsize)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + ft_strlen(src));
}
