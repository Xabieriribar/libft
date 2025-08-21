/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiribar <xabieriribarrevuelta@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:21:44 by xiribar           #+#    #+#             */
/*   Updated: 2025/08/20 16:32:08 by xiribar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_n_len(long n)
{
	size_t	counter;

	if (n == 0)
		return (1);
	counter = 0;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	long	nbrl;
	char	*nbr;
	int		digits;
	int		sign;

	nbrl = n;
	sign = 0;
	if (nbrl < 0)
	{
		nbrl = -nbrl;
		sign = 1;
	}
	digits = ft_n_len(nbrl);
	nbr = malloc(digits + sign + 1);
	if (!nbr)
		return (NULL);
	nbr[digits + sign] = '\0';
	while (digits > 0)
	{
		nbr[digits + sign - 1] = (nbrl % 10) + '0';
		nbrl /= 10;
		digits--;
	}
	if (sign)
		nbr[0] = '-';
	return (nbr);
}
