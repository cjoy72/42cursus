/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:28:47 by cbaroi            #+#    #+#             */
/*   Updated: 2023/10/31 20:44:55 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			total_size;
	unsigned char	*dynamic;
	size_t			i;
	
	if (count != 0 && size > ULONG_MAX / count)
		return (NULL);
	total_size = count * size;
	dynamic = (unsigned char *)malloc(total_size);
	if (dynamic == NULL)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		dynamic[i] = 0;
		i++;
	}
	return (dynamic);
}
