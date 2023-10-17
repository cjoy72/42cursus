/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:34:32 by cbaroi            #+#    #+#             */
/*   Updated: 2023/10/17 09:40:55 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

int	toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

int main()
{
    char    c;
    c = 'g';
    printf("given %c\n", c);
    printf("return %c\n", toupper(c));
    c = 'A';
    printf("given %c\n", c);
    printf("return %c\n", toupper(c));
    c = ']';
    printf("given %c\n", c);
    printf("return %c\n", toupper(c));
}
