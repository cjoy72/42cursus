/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:23:17 by cbaroi            #+#    #+#             */
/*   Updated: 2023/10/21 11:27:08 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	nl;
	char	c;

	nl = n;
	if (n < 0)
	{
		n = n * (-1);
		write (fd, '-', 1);
	}
	if (nl >= 10)
		ft_putnbr_fd(nl / 10, fd);
	c = (nl % 10) + '0';
	write (fd, &c, 1);
}
