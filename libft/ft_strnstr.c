/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:18:23 by eleotard          #+#    #+#             */
/*   Updated: 2022/04/11 16:18:23 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] == big[i + j] && (i + j) < len)
		{
			if (little[j + 1] == '\0')
			{
				return ((char *)&big[i]);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/*#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	chaine[30] = "aaabcabcd";
	char	needle[] = "a";
	//size_t	n = 16;

	printf("Valeur pointee:[%s]\n\n", ft_strnstr(chaine, needle, 8));
	printf("Valeur pointee:[%s]\n\n",strnstr(chaine, needle, 8));
//    printf("Valeur pointee:%s\n\n",ft_strnstr(src4, non4, n));
//	printf("Valeur pointee:%s\n\n", strnstr(src4, non4, n));
//    printf("Valeur pointee:%s\n\n",ft_strnstr(src4, null4, n));
//	printf("Valeur pointee:%s\n\n", strnstr(src4, null4, n));
}*/
