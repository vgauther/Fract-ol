/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:02:15 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/09 16:53:43 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_fill(char const *s, char **tab, int *tab1, char c)
{
	int j;
	int x;

	j = 0;
	x = tab1[0];
	while (s[tab1[0]] != c && s[tab1[0]] != '\0')
		tab1[0] += 1;
	if (!(tab[tab1[1]] = (char *)malloc(sizeof(char) * tab1[0] - x + 1)))
		return (0);
	while (x < tab1[0])
	{
		tab[tab1[1]][j] = s[x];
		j++;
		x++;
	}
	tab[tab1[1]][j] = '\0';
	return (tab1[0]);
}

int			ft_detectword(char const *s, int i, char c)
{
	while (s[i] == c)
		i++;
	return (i);
}

static int	ft_countwords(char const *s, char c)
{
	int word;
	int i;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			word++;
		while (s[i] != c && s[i])
			i++;
	}
	return (word);
}

char		**ft_strsplit(char const *s, char c)
{
	char				**tab;
	int					word;
	int					tab1[2];

	if (s)
	{
		tab1[0] = 0;
		tab1[1] = 0;
		word = ft_countwords(s, c);
		if (!(tab = (char **)malloc(sizeof(char *) * word + 1)))
			return (NULL);
		while (s[tab1[0]] && tab1[1] < word)
		{
			tab1[0] = ft_detectword(s, tab1[0], c);
			if (!(tab1[0] = ft_fill(s, tab, tab1, c)))
				return (NULL);
			tab1[1] += 1;
		}
		tab[tab1[1]] = NULL;
		return (tab);
	}
	return (NULL);
}
