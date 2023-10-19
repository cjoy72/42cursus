/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:22:47 by cbaroi            #+#    #+#             */
/*   Updated: 2023/10/19 23:28:48 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_intlen(int a)
{
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

char	*ft_allocmem(int length, int is_negative)
{
	char	*str;

	if (is_negative)
	{
		length = length + 2;
		str = (char *)malloc(sizeof(char) * length);
		if (str == NULL)
			return (NULL);
		str[0] = '-';
	}
	else
	{
		length = length + 1;
		str = (char *)malloc(sizeof(char) * length);
		if (str == NULL)
			return (NULL);
	}
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
	if (a < 0)
	{
		is_negative = 1;
		a = -a;
	}
	length = ft_intlen(a);
	str = ft_allocmem(length, is_negative);
	if (str == NULL)
		return (NULL);
	ft_putintchar(str + is_negative, a, length);
	return (str);
}
