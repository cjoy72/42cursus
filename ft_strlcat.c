/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:38:19 by cbaroi            #+#    #+#             */
/*   Updated: 2023/10/31 22:21:24 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	n;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = 0;
	n = dst_len;
	if (size == 0)
		return (src_len);
	while (src[i] && n + i < size - 1)
	{
		dst[i + n] = src[i];
		i++;
	}
	dst[i + n] = '\0';
	if (size < dst_len)
		return (size + src_len);
	return (dst_len + src_len);
}
