/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:16:35 by eleotard          #+#    #+#             */
/*   Updated: 2021/12/01 16:13:43 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*t;

	t = (char *)s;
	while (*t != '\0')
	{
		if ((char)c == *t)
			return (t);
		t++;
	}
	if (c == '\0')
		return (t);
	return (0);
}
/*#include <stdio.h>
#include <string.h>
int main(void)
{
    const char    s[] = "bonjour";
    //char    c = 'n'; 

    printf("%s\n", strchr(s, 0));
    printf("%s", ft_strchr(s, 0));
}*/
