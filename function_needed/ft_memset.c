/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 21:16:55 by cjoy720           #+#    #+#             */
/*   Updated: 2023/10/13 23:32:18 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*byte_ptr;
	unsigned char	byte_value;

	byte_value = (unsigned char) c;
	byte_ptr = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		byte_ptr[i] = byte_value;
		i++;
	}
	return (s);
}
