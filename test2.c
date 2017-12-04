/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 22:16:11 by dhorvill          #+#    #+#             */
/*   Updated: 2017/12/01 00:20:39 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lbift.h"
#include "Fillit.h"

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

int		used_points(int highest_size, int nbr_highest_size, int n, int nbr_tetriminos)
{
	int used_points;

	used_points = n * (highest_size - 1) + nbr_highest_size;
	if ((nbr_tetriminos * 4) > used_points)
		used_points = nbr_tetriminos * 4;
	return (used_points);
}


int		size_square(int nbr_tetriminos, int highest_size, int longuest_size)
{
	int n;

	n = ft_sqrt_improved(nbr_tetriminos * 4);
	if (ft_sqrt(nbr_tetriminos * 4) == 0)
		n++;
	if (n < highest_size)
		n = highest size;
	if (n < longuest_size)
		n = longuest_size;
	return (n);
}

char	**ft_tab(int n, int used_points)
{

	int		i;
	int		j;
	int		k;
	char	**tab;

	i = -1;
	if (tab = (char**)malloc(sizeof(tab) * (n + 1)) == 0)
		return (NULL);
	while (++i < n)
	{
		if (tab[i] = (char**)malloc(sizeof(tab) * (n + 1)) == 0)
			return (NULL);
	}
	i = -1;
	j = -1;
	k = -1;
	while (tab[++i])
	{
		while (++k < used_points && tab[i][++j])
			tab[i][j] = '.';
		if (k >= used_points)
		{
			k--;
			while (++k < (n * n - usedpoints) && tab[i][++j])
				tab[i][j] = 'P';
		}
		j = 0;
	}
	return (tab);
}

int		test_position(t_tetri tetriminos, int i, int j, char **tab)
{
	int		count;
	int		k;
	int		m;
	int		n;

	k = 0;
	m = i;
	n = j;
	count = -1;.
		while (++count <= 3 && tab[m][n])
		{
			if (tab[m][n] == '.')
				count++;
			else
				break ;
			if (k <= 2)
			{
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

char	**draw_tetriminos(t_tetri tetriminos, int i, int j, char **tab)
{
	int k;
	int m;
	int n;

	m = i;
	n = j;
	k = 0;
	while (k <= 3)
	{
		tab[m][n] = '#';
		if (k <= 2)
		{
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

void	find_next_point(int i, int j, char **tab)
{
	while (tab[i][j] != '.' && tab[i][j])
	{
		while (tab[i][j] != '.' && tab[i + 1][j + 1])
			j++;
		if (tab[i][j] != '.')
		{
			i++;
			j = 0;
		}
	} 
	i--;
	j--; // decrementation pour economisez de la place pour la norme.
}

void	combination_help(t_tetri *tetriminos, char **str, t_list S)
{
	int k;
	int z;
	int i;
	int j;

	z = 0;
	k = -1;
	i = S.a;
	j = S.b;
	find_next_point(i, j, str);
	while (++k <= S.d) // boucle allant de 0 a la valeur stocker de x.
	{
		while (test_position(tetriminos[k], ++i, ++j, str) == 1 && str[i][j] != 'P')
		{
			while (++j < n && str[i][j])
			{
				if (test_position(tetriminos[k], i, j, str) == 0)
				{
					z = 1;
					break ;
				}
			}
			j = -1;
			if (z == 1)
				break ;
		}
		if (test_position(tetriminos[k], i, j, str) == 0 && S.c++)
			str = draw_tetriminos(tetriminos[k], i, j, str);
		else
			break ;
	}
}

char	**combination_recursive(t_tetri *tetriminos, int k, int x, char **str)
{
	int 	i;
	int 	j;
	int 	z;
	t_list	S; // structure contenant 4 int pour la norme
	char	**save; //  un **tab qui va sauvegarde le contenu de str a chaque recursivite

	i = 0;
	j = 0;
	z = 0;
	ft_strcpy_improved(save, str); // cette fonction copie le contenu d'un **tab dans un autre XD
	S.c = 0; // variable qui compte le nombre de tetriminos "place".
	S.d = x; // stock la valeur de x avant le debut de la boucle
	k = tetriminos.nbr - x;
	find_next_point(i, j, str); // avance jusqua rencontrer un espace non utiliser
	while (++x < tetriminos.nbr)
	{
		while (test_position(tetriminos[x], ++i, ++j, str) == 1 && str[i][j] != 'P')
		{
			while (++j < n && str[i][j])
			{
				if (test_position(tetriminos[x], i, j, str) == 0)
				{
					z = 1;
					break ;
				}
			}
			j = -1;
			if (z == 1)
				break ;
		}		
		if (test_position(tetriminos[x], i, j, str) == 0 && S.c++)
			str = draw_tetriminos(tetriminos[x], i, j, str);
		else
			break ;
	}
	if (k != tetriminos.nbr && x == tetriminos.nbr) // vrai si on a placer tout les tetriminos entre x et tetri.nbr
	{
		S.a = i;
		S.b = j;
		combination_help(tetriminos, x, str, S);
	}
	if (S.c == tetriminos.nbr) // vrai si toutes les pieces sont placer
		return (str);
	else if (x == tetriminos.nbr) // vrai apres avoir essayer toutes les possibilites sans resultats
		return (NULL);
	else
		return (combination_recursive(tetriminos, x + 1, save)); // recursivite 
}

char	**resolve_recursive(char **tab, int n, int used_points, t_tetri *tetriminos)
{
	int		x;
	char	**str;
	int		k;

	x = -1;
	k = 0;
	tab = NULL;
	str = ft_tab(n, used_points);
	if (used_points <= n * n)
		tab = combination_recursive(tetrminos, k, x, str); // tab prend NULL ou la solution optimal.
	else
		n++; // incrementation du carre si trop petit.
	if (tab != NULL)
		return (tab);
	else
		return (resolve_recursive(ft_tab(n, used_points + 1), n, used_point + 1, tetriminos)); // recursive
}
