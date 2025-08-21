/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiribar <xabieriribarrevuelta@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:59:50 by xiribar           #+#    #+#             */
/*   Updated: 2025/08/20 17:00:30 by xiribar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_p;
	const unsigned char	*s2_p;
	size_t				index;

	s1_p = (unsigned char *)s1;
	s2_p = (unsigned char *)s2;
	index = 0;
	while (index < n)
	{
		if (s1_p[index] != s2_p[index])
			return (s1_p[index] - s2_p[index]);
		index++;
	}
	return (0);
}
