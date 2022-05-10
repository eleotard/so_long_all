/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:10:22 by eleotard          #+#    #+#             */
/*   Updated: 2022/04/11 16:18:35 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned int	i;

	if ((!dst) && (!src))
		return (0);
	i = 0;
	if (dst > src)
	{
		while (n > 0)
		{
			n--;
			*(char *)(dst + n) = *(const char *)(src + n);
		}
	}
	else
	{
		while (i < n)
		{
			*(char *)(dst + i) = *(const char *)(src + i);
			i++;
		}
	}
	return (dst);
}
/*#include <string.h>
#include <stdio.h>
int	main(void)
{
	//char s[] = "Start stop";
	//char sResult[] = {67, 68, 67, 68, 69, 0, 45};
	//char sResult2[] = {67, 67, 68, 68, 69, 0, 45};
	char s1[] = "hello";
	char *s2 = s1 + 3;
	printf("%s\n", ft_memmove(s2, s1, 7));
	printf("%s", memmove(s2, s1, 7));
}*/
