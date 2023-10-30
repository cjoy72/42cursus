/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:22:47 by cbaroi            #+#    #+#             */
/*   Updated: 2023/10/30 16:55:53 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int a)
{
	int	i;

	if (a == 0)
		return (1);
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

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

void	ft_putintchar(char *str, int num, int length)
{
	if (num >= 0)
		num = num * (-1);
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

	if (length == 11 && is_negative)
	{
		if (!(str = (char *)malloc(sizeof(char) * 12)))
			return (NULL);
		ft_putintchar(str + 1, INT_MIN, 12);
		str[0] = '-';
		return (str);
	}
	if (!(str = (char *)malloc(sizeof(char) * (length + 1 + is_negative))))
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
