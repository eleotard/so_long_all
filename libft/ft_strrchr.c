/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:31:18 by eleotard          #+#    #+#             */
/*   Updated: 2021/12/01 13:05:36 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*t;
	int		i;

	t = (char *)s;
	i = 0;
	while (t[i] != '\0')
		i++;
	while (*t != '\0')
		t++;
	while (i >= 0)
	{
		if ((unsigned char)c == *t)
			return (t);
		i--;
		t--;
	}
	return (0);
}
/*#include <stdio.h>
#include <string.h>
int main(void)
{
    const char    s[] = "bonjonr";
    char    c = 'n'; 

    printf("%s", strrchr(s, c));
    //printf("%s", ft_strrchr(s, c));
}*/
