/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:22:47 by cbaroi            #+#    #+#             */
/*   Updated: 2023/10/30 16:19:21 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int a)
{
	if (a == 0)
		return (1);
	int	i;

	i = 0;
	while (a != 0)
	{
		a = a / 10;
		i++;
	}
	return (i);
}

char	*ft_zero(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (str == NULL)
		return (NULL);
	else
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
}

void	ft_putintchar(char *str, int num, int length)
{
	str[length] = '\0';
	length--;
	while (num != 0)
	{
		str[length] = (num % 10) + '0';
		num = num / 10;
		length--;
	}
}

char	*ft_allocmem_or_min(int length, int is_negative)
{
	char	*str;

	// Check if the requested string is for the smallest 32-bit integer
	if (length == 11 && is_negative)
	{
		str = (char *)malloc(sizeof(char) * 12);
		if (str == NULL)
			return (NULL);
		str[0] = '-';
		str[1] = '2';
		str[2] = '1';
		str[3] = '4';
		str[4] = '7';
		str[5] = '4';
		str[6] = '8';
		str[7] = '3';
		str[8] = '6';
		str[9] = '4';
		str[10] = '8';
		str[11] = '\0';
		return (str);
	}

	// Regular dynamic allocation for other lengths
	str = (char *)malloc(sizeof(char) * (length + 1 + is_negative));
	if (str == NULL)
		return (NULL);
	if (is_negative)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int a)
{
	int		is_negative;
	int		length;
	char	*str;

	is_negative = 0;
	if (a == 0)
		return (ft_zero());
	if (a == INT_MIN)
		return (ft_allocmem_or_min(11, 1));
	if (a < 0)
	{
		is_negative = 1;
		a = -a;
	}
	length = ft_intlen(a);
	str = ft_allocmem_or_min(length, is_negative);
	if (str == NULL)
		return (NULL);
	ft_putintchar(str + is_negative, a, length);
	return (str);
}
