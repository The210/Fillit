/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_and_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:53:28 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/12/14 20:32:47 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_misc	find_next_point(t_misc S, char **tab)
{
	if (tab[S.a][S.b] == 'e')
	{
		S.a++;
		S.b = 0;
	}
	while (tab[S.a][S.b] != 'e' && tab[S.a][S.b] != '.')
	{
		while (tab[S.a + 1][S.b + 1] != 'e' && tab[S.a][S.b] != '.')				
			S.b++;
		if (tab[S.a][S.b] != '.')
		{
			S.a++;
			S.b = 0;
		}
	}
	return (S);
}

int		test_position(t_tetri tetriminos, t_misc S,  char **tab)
{
	int		count;
	int		k;
	int		m;
	int		n;

	k = 0;
	m = S.a;
	n = S.b;
	count = 0;
	while (count <= 3 && tab[m][n])
	{
		if (tab[m][n] == '.')
			count++;
		else
			break ;
		if (k <= 2)
		{
			if (tetriminos.coord[k] == 'P' && tab[m][n])
			{
				n = n - 2;
				m++;
			}
			if (tetriminos.coord[k] == 'R' && tab[m][n])
				n++;
			if (tetriminos.coord[k] == 'D' && tab[m][n])
				m++;
			if (tetriminos.coord[k] == 'L' && tab[m][n])
				n--;
			if (tetriminos.coord[k] == 'Z' && tab[m][n])
			{
				m++;
				n--;
			}
			if (tetriminos.coord[k] == 'X' && tab[m][n])
			{
				m++;
				n++;
			}
			k++;
		}
	}
	if (count == 4)
		return (0);
	else
		return (1);
}

char	**draw_tetriminos(t_tetri tetriminos, t_misc S,  char **tab)
{
	int k;
	int m;
	int n;

	m = S.a;
	n = S.b;
	k = 0;
	while (k <= 3)
	{	
		tab[m][n] = tetriminos.coord[3];
		if (k <= 2)
		{
			if (tetriminos.coord[k] == 'P' && tab[m][n])
			{
				n = n - 2;
				m++;
			}
			if (tetriminos.coord[k] == 'R' && tab[m][n])
				n++;
			if (tetriminos.coord[k] == 'D' && tab[m][n])
				m++;
			if (tetriminos.coord[k] == 'L' && tab[m][n])
				n--;
			if (tetriminos.coord[k] == 'Z' && tab[m][n])
			{
				m++;
				n--;
			}
			if (tetriminos.coord[k] == 'X' && tab[m][n])
			{
				m++;
				n++;
			}
		}
		k++;
	}
	return (tab);
}
