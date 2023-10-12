/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:38:19 by cbaroi            #+#    #+#             */
/*   Updated: 2023/10/13 00:02:04 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//If Size is greater than (src+dst), then it will return the size needed to concatenate. I didn't finish that part but I need to. REMEMBER: DEST->SRC
size_t	strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (src[i] != '\0' || i == size)
		i++;
	while (dst[i] != '\0' || i == size)
		i++;
	if (i != size)
	{
		i = 0;
		j = 0;
		while (dst[i] != '\0')
		{
			i++;
			j++;
		}
		i = 0;
		while (src[i] != '\0')
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		return (j);
	}
}
