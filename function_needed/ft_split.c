/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:02:33 by cbaroi            #+#    #+#             */
/*   Updated: 2023/10/22 14:31:55 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	count_largestword(char const *s, char c)
{
	int	i;
	int	j;
	int	largest_word;

	i = 0;
	j = 0;
	largest_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] != c && s[i] != '\0')
			{
				i++;
				j++;
				if (s[i] != c && s[i] != '\0')
					continue ;
				else if (largest_word < j)
					largest_word = j;
			}
		}
	}
	return (largest_word);
}

void	putstrptrptr(char **str, char *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while ((s[i] == c) || (s[i] != '\0'))
	{
		k = 0;
		i++;
		while ((s[i] != c) || (s[i] != '\0'))
		{
			str[j][k] = s[i];
			if (s[i + 1] == c && s[i] != '\0')
				j++;
			i++;
			k++;
		}
	}
	if (i != 0)
		str[j][k] = '\0';
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		largest_word;
	int		words;
	int		i;
	int		j;

	words = count_words(s, c);
	largest_word = count_largestword(s, c);
	str = (char **)malloc(sizeof(char *) * (words + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < words)
	{
		str[i] = (char *)malloc(sizeof(char) * (largest_word + 1));
		if (str[i] == NULL)
			return (NULL);
		i++;
	}
	putstrptrptr(str, s, c);
	return (str);
}
/*
void putstrptrptr(char **str, char *s, char c) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (s[i] != '\0') {
        if (s[i] != c) {
            str[j][k] = s[i];
            k++;
        } else if (k > 0) {
            str[j][k] = '\0';
            j++;
            k = 0;
        }
        i++;
    }
    if (k > 0) {
        str[j][k] = '\0';
    }
}
*/
/*
int count_largestword(const char *s, char c) {
    int largest_word = 0;
    int current_word_length = 0;

    while (*s) {
        while (*s == c)
            s++;
        if (*s) {
            current_word_length = 0;
            while (*s && *s != c) {
                current_word_length++;
                s++;
            }
            if (current_word_length > largest_word)
                largest_word = current_word_length;
        }
    }

    return largest_word;
}
*/
/*
int count_words(const char *s, char c) {
    int words = 0;

    while (*s) {
        while (*s == c)
            s++;
        if (*s) {
            words++;
            while (*s && *s != c)
                s++;
        }
    }

    return words;
}
*/
/*
char **ft_split(char const *s, char c) {
    int words = count_words(s, c);
    int largest_word = count_largestword(s, c);
    char **str = (char **)malloc(sizeof(char *) * (words + 1)); // Allocate an array of char pointers

    if (str == NULL)
        return (NULL);

    for (int i = 0; i < words; i++) {
        str[i] = (char *)malloc(sizeof(char) * (largest_word + 1)); // Allocate memory for each word
        if (str[i] == NULL) {
            // Handle memory allocation failure here
            // You may need to free previously allocated memory
            return (NULL);
        }
    }

    putstrptrptr(str, s, c);

    return str;
}
*/
