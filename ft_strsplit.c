/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 22:36:51 by dhorvill          #+#    #+#             */
/*   Updated: 2017/11/25 01:25:47 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbw(char *s, char c)
{
	int i;
	int sym;
	int count;

	i = 0;
	sym = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] != c && s[i])
		{
			sym = 1;
			i++;
		}
		while (s[i] == c && s[i])
		{
			count += sym;
			sym = 0;
			i++;
		}
	}
	return (count + 2);
}

static int	nbc(char *s, int i, char c)
{
	int count;

	count = 0;
	while (s[i] != c && s[i])
	{
		count++;
		i++;
	}
	return (count + 1);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	s = ft_strtrimc(s, c);
	if (!s || !(res = malloc(sizeof(char*) * nbw((char*)s, c))))
		return (NULL);
	while (s[i])
	{
		k = 0;
		if (!(res[j] = malloc(sizeof(c) * nbc((char*)s, i, c))))
			return (NULL);
		while (s[i] != c && s[i])
			res[j][k++] = s[i++];
		while (s[i] == c && s[i])
			i++;
		res[j++][k] = '\0';
	}
	res[j] = NULL;
	return (res);
}
