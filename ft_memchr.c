/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:51:02 by cbaroi            #+#    #+#             */
/*   Updated: 2023/10/17 12:17:49 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*mem;
	size_t				i;

	mem = (const unsigned char *)s;
	i = 0;
	while (i < n && mem[i] != c)
		i++;
	if (i == n)
		return (NULL);
	else
		return ((void *)(mem + i));
}
