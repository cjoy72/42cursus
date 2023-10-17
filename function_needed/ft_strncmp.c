/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:32:08 by cbaroi            #+#    #+#             */
/*   Updated: 2023/10/17 11:45:09 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i]
		&& i < n && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (i == n)
		return (0);
	else
		return ((unsigned int)s1[i] - (unsigned int)s2[i]);
}
