/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:37:13 by cbaroi            #+#    #+#             */
/*   Updated: 2023/10/18 13:28:13 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	if (c == 32 || (c >= '\t' && c <= '\r'))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int	n;
	int	sign;

	sign = 1;
	while (ft_isspace(*nptr) == 1 || *nptr == '+')
		nptr++;
	if (*nptr >= 'a' && *nptr <= 'z'
		|| *nptr >= 'A' && *nptr <= 'Z')
		return (0);
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	n = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		n *= 10;
		n += (*nptr - '0');
		nptr++;
	}
	return (n * sign);
}
