/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul_fonctions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:20:50 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/12/15 16:12:39 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt_improved(int nb)
{
	int a;

	a = 0;
	while ((a * a) <= nb)
	{
		if (a * a <= nb && ((a + 1) * (a + 1)) > nb)
			break ;
		a++;
	}
	return (a);
}

int		size_square(int nbr_tetriminos, int highest_size, int longest_size)
{
	int n;

	n = ft_sqrt_improved(nbr_tetriminos * 4);
	if (ft_sqrt(nbr_tetriminos * 4) == 0)
		n++;
	if (n < highest_size)
		n = highest_size;
	if (n < longest_size)
		n = longest_size;
	return (n);
}

char	*ft_tab_improved(int n)
{
	int i;
	int j;
	char *buf;

	i = 1;
	j = 0;
	buf = ft_strnew(30 * 30 + 1);
	while (i < 30 * 30 - 1)
	{
		if (i != 0 && i % (30 + j) == 0)
			buf[i - 1] = '\n';
		else if (i % (30 + j) <= n && i < 30 * n)
			buf[i - 1] = '.';
		else
			buf[i - 1] = 'e';
		j = 1;
		i++;
	}
	return(buf);
}

char **ft_tab(int n)
{ 	
	char *buf;
	char **tab;

	buf = ft_tab_improved(n);
	tab = ft_strsplit(buf, '\n');
	return (tab);
}

char	**malloc_copy_tab(int n, char **str)
{
	int		i;
	int		j;
	char	**tab;

	if ((tab = malloc(sizeof(tab) * (n + 1))) == NULL)
		return (NULL);
	i = -1;
	while (++i < n)
	{
		if ((tab[i] = malloc(sizeof(tab) * (n + 1))) == NULL)
			return (NULL);
	}
	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
			tab[i][j] = str[i][j];
	}
	return (tab);
}
