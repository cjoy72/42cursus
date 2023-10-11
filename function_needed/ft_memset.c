/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoy720 <cjoy720@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 21:16:55 by cjoy720           #+#    #+#             */
/*   Updated: 2023/10/11 21:17:13 by cjoy720          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*byte_ptr;
	unsigned char	byte_value;

	byte_value = (unsigned char) c;
	byte_ptr = (unsigned char *) b;
	i = 0;
	while (i < len)
	{
		byte_ptr[i] = byte_value;
		i++;
	}
	return (b);
}
