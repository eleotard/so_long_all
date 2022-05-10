/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:25:02 by eleotard          #+#    #+#             */
/*   Updated: 2022/04/11 16:17:35 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while ((s1[i] || s2[i]) && (i < n - 1))
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*#include <string.h>
#include <stdio.h>
//penser a si n=1, i passe a 1 et on compare les 2e char en fait

int	main (void)
{
	char	s1[12] = "vraiestfaux";
	char 	s2[] = "vraie12345";
	char	s3[13] = "vraiestfaux";
	char 	s4[] = "vraiest-2345";


	size_t	n = 15;

	printf("%d, %d\n", ft_strncmp(s1, s2, n), strncmp(s3, s4, n));
	return (0);
}*/