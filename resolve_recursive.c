/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_recursive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:19:50 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/12/15 16:17:11 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char	**ft_strcpy_improved(char **dest, char **tab, t_misc S)
{	
	int i;
	int j;

	i = 0;
	while (tab[i])
		i++;
	if ((dest = malloc(sizeof(char*) * (i + 1))) == NULL)
		return (NULL);
	i = -1;
	while (++i < S.n)
	{
		j = 0;
		while (j < S.n)
			j++;
		if ((dest[i] = malloc(sizeof(char*) * (j + 1))) == NULL)
			return (NULL);
	}
	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
			dest[i][j] = tab[i][j];
	}
	return (dest);
}

t_misc	ft_find_spot_start(t_tetri tetriminos, char **tab, t_misc S)
{
	S.a = 0;
	S.b = 0;
	while (test_position(tetriminos, S, tab) == 1 && tab[S.a][S.b] != 'e')
	{
		S.b++;
		S = find_next_point(S, tab);
	}
	if (S.b == S.c && S.a == S.d && (S.d != 0 && S.c != 0))
	{
		S.b++;
		S = find_next_point(S, tab);
		while (test_position(tetriminos, S, tab) == 1 && tab[S.a][S.b] != 'e')
		{
			S.b++;
			S = find_next_point(S, tab);
		}
	}
	return (S);
}

t_misc	ft_find_spot(t_tetri tetriminos, char **tab, t_misc S)
{
	while (test_position(tetriminos, S, tab) == 1 && tab[S.a][S.b] != 'e')
	{
		S.b++;
		S = find_next_point(S, tab);
	}
	return (S);
}

int		ft_double_test(char **tab, t_misc S, t_tetri *tetriminos)
{
	S.c = S.a;
	S.d = S.b;
	if (test_position(tetriminos[S.e], S, tab) == 0)
	{
		tab = draw_tetriminos(tetriminos[S.e], S, tab);
		S = ft_find_spot_start(tetriminos[S.e + 1], tab, S);
		if (test_position(tetriminos[S.e + 1], S, tab) == 0 && (S.e + 1) < tetriminos[0].nbr - 1)
		{
			S.a = S.c;
			S.b = S.d;
			return (0);
		}
		else if (test_position(tetriminos[S.e + 1], S, tab) == 0)
		{
			tab = draw_tetriminos(tetriminos[S.e + 1], S, tab);
			S.a = S.c;
			S.b = S.d;
			return (0);
		}
	}
	S.a = S.c;
	S.b = S.d;
	return (1);
}

char	**combination_recursive(t_tetri *tetriminos, t_misc S, char **str)
{
	if (tetriminos[0].nbr == 1)
	{
		draw_tetriminos(tetriminos[0], S,  str);
		return (str);
	}
	if (S.e >= tetriminos[0].nbr - 1)
		return (str);
	if (ft_double_test(str, S, tetriminos) == 0)
	{
		S.e++;;
		if (S.e >= tetriminos[0].nbr - 1)
			return (str);
		return (combination_recursive(tetriminos, S, str));
	}
	else
	{
		S = ft_findcoord(str, S, tetriminos[S.e]);
		ft_erase(str, tetriminos[S.e]);
		S = ft_find_spot(tetriminos[S.e], str, S);
		while (S.e > 0 && S.a >= S.n)
		{
			S.e--;
			S = ft_findcoord(str, S, tetriminos[S.e]);
			ft_erase(str, tetriminos[S.e]);
			S = ft_find_spot(tetriminos[S.e], str, S);
		}
		if (S.e == 0 && S.a >= S.n)
			return (NULL);
	/*	while (S.a >= S.n)
		{
			S.e--;
			S = ft_findcoord(str, S, tetriminos[S.e]);
			ft_erase(str, tetriminos[S.e]);
			S = ft_find_spot(tetriminos[S.e], str, S);
		}*/
		return (combination_recursive(tetriminos, S, str));
	}
	return (NULL);
}

char	**resolve_recursive(t_misc S, t_tetri *tetriminos)
{
	char	**str;

	S.a = 0;
	S.b = 0;
	S.e = 0;
	str = ft_tab(S.n);
	str = combination_recursive(tetriminos, S, str); 
	if (str != NULL)
		return (str);
	else
	{
		S.n++;
		return (resolve_recursive(S, tetriminos));
	}
}
