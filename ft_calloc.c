/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiribar <xabieriribarrevuelta@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:55:48 by xiribar           #+#    #+#             */
/*   Updated: 2025/08/20 16:29:44 by xiribar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	len;
	void	*bytes;

	len = nmemb + size;
	bytes = malloc(len);
	if (!bytes)
		return (NULL);
	ft_bzero(bytes, len);
	return (bytes);
}
