/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:36:54 by eleotard          #+#    #+#             */
/*   Updated: 2021/11/25 13:58:56 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (!((c >= 'A' && c <= 'Z')
			|| (c >= 'a' && c <= 'z')))
	{
		return (0);
	}
	return (1);
}
/*#include <stdio.h>
int	main(int argc, char **argv)
{
	(void)argc;
	if (ft_is_alpha(argv[1][0]))
	       printf("est alpha");
	else
		printf("pas alpha");	
}*/
