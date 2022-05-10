/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:33:45 by eleotard          #+#    #+#             */
/*   Updated: 2021/11/30 14:34:02 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}
/*#include <stdio.h>
#include <ctype.h>
int main(void)
{
    int c;

    c = 104;

    printf("%c\n", toupper(c));
    printf("%d\n", c);
    printf("%c", ft_toupper(c));
}*/