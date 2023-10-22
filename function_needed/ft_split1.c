/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:42:24 by cbaroi            #+#    #+#             */
/*   Updated: 2023/10/22 17:31:23 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	count_words(const char *s, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			words++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (words);
}

int	strlensplit(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*putwordinstring(char *str, char *s, char c, int wordnum)
{
	int	j;
	int	length;

	j = 0;
	while (s)
	{
		if (s != c)
		{
			j++;
			if (j == wordnum)
			{
				length = strlensplit(s, c);
				str = (char *)malloc(sizeof(char) * (length + 1));
				if (str == NULL)
					return (NULL);
				else
					str[length] = '\0';
			}
		}
		else
			s++;
	}
}

char	**ft_split(char const *s, char c, int wordnum)
{
	char	**str;
	int		words;
	int		i;

	words = count_words(s, c);
	str = (char **)malloc(sizeof(char *) * (words + 1));
	if (str == NULL)
		return (NULL);
	str[words] = NULL;
	i = 0;
	while (i < words)
		str[i] = putwordinstring(str[i], s, c, i);
}
