/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:38:31 by eleotard          #+#    #+#             */
/*   Updated: 2022/04/11 16:15:32 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*t;
	size_t			i;

	t = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*t = '\0';
		i++;
		t++;
	}
}
/*#include <string.h>
#include <stdio.h>

int main(void)
{
    unsigned char	s[] = "abcdef";
	size_t			n;

	n = -2;

	printf("%s\n", s);
    ft_bzero(s, n);
    //bzero(s, n);
	printf("%s\n", s);
}*/
