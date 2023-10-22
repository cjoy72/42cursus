/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:42:24 by cbaroi            #+#    #+#             */
/*   Updated: 2023/10/22 20:33:25 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	**ft_split(const char *s, char c)
{
	int		n_words;
	int		i;
	char	**str_array;

	if (s == NULL || *s == '\0')
		return (s);
	i = 0;
	n_words = 0;
	if (s[0] != c && s[0] != '\0')
		n_words++;
	while (s[i + 1] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
		{
			n_words++;
			i++;
		}
	}
	str_array = malloc(sizeof(char *) * (n_words + 1));
	if (str_array == NULL)
		return (NULL);
	str_array[n_words] = NULL;
	return (fill_matrix(n_words, s, c, str_array));
}

static char	**fill_matrix(int n_words, const char *s, char c, char **str_array)
{
	int	j;
	int	i;
	int	len;

	j = -1;
	i = 0;
	len = 0;
	while (++j < n_words)
	{
		while (*s == c)
			s++;
		while (s[len] != c && s[len] != '\0')
			len++;
		str_array[j] = malloc(sizeof(char) * (len + 1));
		if (str_array[j] == NULL)
			return (free_everything(str_array, j));
		str_array[j][len++] = '\0';
		i = len - 1;
		while (--len > 0)
			str_array[j][len -1] = s[len - 1];
		s = s + i;
	}
	return (str_array);
}

static char	**free_everything(char **str_array, int j)
{
	while (--j >= 0)
		free(str_array[j]);
	free(str_array);
	return (NULL);
}
