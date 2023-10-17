/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:00:45 by cbaroi            #+#    #+#             */
/*   Updated: 2023/10/17 22:52:24 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			i;
	size_t			j;

	c1 = (unsigned char *)big;
	c2 = (unsigned char *)little;
	if (c2[0] == '\0')
		return ((char *)(big));
	i = 0;
	while (i < len)
	{
		j = 0;
		while (c1[i] != c2[i] && c1[i] != '\0')
			i++;
		while (c1[i + j] == c2[j] && c2[j] != '\0')
		{
			if (c2[j] == '\0')
				return ((char *)(c1 + i));
		}
	}
	return (NULL);
}
/*
"ciao come stai"
"men"

"me stai"
*/
