/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:53:25 by eleotard          #+#    #+#             */
/*   Updated: 2021/12/13 12:40:19 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/*void	fct(unsigned int a, char *s)
{
	*s = *s + a;
}

#include <stdio.h>
int	main()
{
	char	s[] = "0000000000";
	void (*ptr)(unsigned int, char *);
	ptr = &fct;
	ft_striteri(s, ptr);
	printf("%s", s);
}*/
