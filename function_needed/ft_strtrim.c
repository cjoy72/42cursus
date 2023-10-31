/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:37:18 by cbaroi            #+#    #+#             */
/*   Updated: 2023/10/31 14:15:13 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcharcmp(char const *set, char c)
{
	int	i;
	int	len;

	len = ft_strlen(set);
	i = 0;
	while (i < len)
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_strcpyy(char *str, char *ls, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		str[i] = ls[i];
		i++;
	}
	str[i] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int			i;
	char		*ls;
	size_t		size;
	char		*str;

	i = 0;
	while (ft_strcharcmp(set, s1[i]))
		i++;
	ls = ((char *)&s1[i]);
	size = ft_strlen(ls);
	i = size - 1;
	while (ft_strcharcmp(set, ls[i]) && i >= 0)
		i--;
	i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	size = i;
	ft_strcpyy(str, ls, size);
	return (str);
}
