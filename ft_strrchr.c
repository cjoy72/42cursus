/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:15:16 by cbaroi            #+#    #+#             */
/*   Updated: 2023/10/17 10:31:01 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while ((unsigned char)s[i] != '\0')
		i++;
	i--;
	while ((unsigned char)s[i] != (unsigned char)c && i >= 0)
		i--;
	if (i == -1)
		return (NULL);
	else
		return ((char *)(s + i));
}
