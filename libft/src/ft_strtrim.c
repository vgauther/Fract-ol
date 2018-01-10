/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 08:45:19 by vgauther          #+#    #+#             */
/*   Updated: 2017/11/12 17:22:24 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fini(char const *s, char *tab, int i)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (s[j])
		j++;
	j--;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	if (!(tab = (char *)malloc(sizeof(char) * (j - i) + 2)))
		return (NULL);
	while (i <= j)
	{
		tab[k] = s[i];
		i++;
		k++;
	}
	tab[k] = '\0';
	return (tab);
}

char		*ft_strtrim(char const *s)
{
	char	*tab;
	int		i;

	if (s)
	{
		tab = (char *)s;
		i = 0;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		if (s[i])
			return (fini(s, tab, i));
		if (!(tab = (char *)malloc(sizeof(char) * 1)))
			return (NULL);
		tab[0] = '\0';
		return (tab);
	}
	return (NULL);
}
