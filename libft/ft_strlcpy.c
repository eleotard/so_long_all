/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:20:02 by eleotard          #+#    #+#             */
/*   Updated: 2022/04/11 16:17:13 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size > 0)
	{
		i = 0;
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	i = 0;
	while (src[i])
		i++;
	return (i);
}
/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	    char    dst[] = "salutcmtcav";
		char	src[] = "salut";
		size_t	n = 11;

		printf("%zu\n", ft_strlcpy(dst, src, n));
		printf("%lu", strlcpy(dst, src, n));
}*/
