/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:02:33 by cbaroi            #+#    #+#             */
/*   Updated: 2023/10/19 16:11:24 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_countwords(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (i == 0 || )
}

char	**ft_split(char const *s, char c)
{
	char	**strptr;
	int		words;

	words = ft_countwords(s, c);
}
