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

size_t	ft_in_word(char const *s, char c)
{
	size_t	counter;
	int		in_word;

	in_word = 0;
	counter = 0;
	while (*s != '\0')
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			counter++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (counter);
}

void	ft_free_split(char **arr, size_t index)
{
	while (index > 0)
	{
		index--;
		free(arr[index]);
	}
	free(arr);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	size_t	index;
	size_t	len;

	if (!s)
		return (NULL);
	arr = malloc((ft_in_word(s, c)) + 1) * (sizeof(char *)));
	if (!arr)
		return (NULL);
	index = 0;
	while (*s != '\0' && index < ft_in_word(s, c))
	{
		while (*s == c)
			s++;
		len = 0;
		while (s[len] != '\0' && s[len] != c)
			len++;
		arr[index] = ft_substr(s, 0, len);
		if (!arr[index])
			return (ft_free_split(arr, index), (char **) NULL);
		s += len;
		index++;
	}
	arr[index] = NULL;
	return (arr);
}
