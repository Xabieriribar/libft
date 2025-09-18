/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiribar <xabieriribarrevuelta@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:55:48 by xiribar           #+#    #+#             */
/*   Updated: 2025/09/18 16:55:12 by xiribar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*bytes;

	bytes = (void *)malloc(nmemb * size);
	if (!bytes)
		return (NULL);
	ft_bzero(bytes, nmemb * size);
	return (bytes);
}
