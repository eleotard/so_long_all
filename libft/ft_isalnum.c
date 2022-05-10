/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:30:13 by eleotard          #+#    #+#             */
/*   Updated: 2021/11/25 13:54:13 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
			|| (c >= 'a' && c <= 'z')))
		return (0);
	return (1);
}

/*#include <stdio.h>
int main(int argc, char **argv)
{
	(void)argc;
	
	if (ft_isalnum(argv[1][0]))
		printf("est alphanum");
	else
		printf("pas alphanum");
}*/
