/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:49:58 by cbaroi            #+#    #+#             */
/*   Updated: 2023/10/31 20:55:42 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		s1_len;
	size_t		i;

	s1_len = ft_strlen((char *)s1);
	s2 = (char *)malloc(s1_len + 1);
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
