/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:16:21 by eleotard          #+#    #+#             */
/*   Updated: 2022/07/29 01:01:36 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			count++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	return (count);
}

void	free_all(char **tab)
{
	int	k;

	k = 0;
	while (tab[k])
		k++;
	while (k >= 0)
	{
		free(tab[k]);
		k--;
	}
	free(tab);
}

char	**ft_do_tab(char const *s, char c, char **tab, int k)
{
	int	j;
	int	i;

	i = 0;
	while (s[i])
	{	
		if (s[i] == c)
			i++;
		else
		{
			j = 0;
			while ((s[i + j] != c) && (s[i + j] != '\0'))
				j++;
			tab[k] = ft_substr(s, i, j);
			if (!tab[k])
			{
				free_all(tab);
				return (0);
			}
			k++;
			i = i + j;
		}	
	}
	tab[k] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		k;
	char	**tab;
	int		nombredemots;

	k = 0;
	if (!s)
		return (0);
	nombredemots = ft_countwords(s, c);
	tab = malloc(sizeof(char *) * (nombredemots + 1));
	if (!tab)
		return (0);
	tab = ft_do_tab(s, c, tab, k);
	return (tab);
}

/*#include <stdio.h>
int main (void)
{
	char s[] = "    Je suis   elsie ";
	char c = ' ';
	int	i;
	char **result;

	result = ft_split(s, c);
	i = 0;
	while (i < 4)
	{
		printf("tab[%d]: [%s]\n",i ,  result[i]);
		i++;
	}
	return (0);
}*/
