/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiribar <xabieriribarrevuelta@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:59:50 by xiribar           #+#    #+#             */
/*   Updated: 2025/08/20 17:14:24 by xiribar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t				len;
	size_t				index;
	const unsigned char	*string;
	unsigned char		character;

	character = (unsigned char)c;
	string = (const unsigned char *)s;
	index = 0;
	len = ft_strlen(s);
	while (index < len)
	{
		if (character == string[index])
			return (s + index);
		index++;
	}
	return (NULL);
}
