/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findcoord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 22:08:24 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/12/14 17:13:43 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_misc	ft_findcoord(char **tab, t_misc S, t_tetri tetrimino)
{
	int i;
	int j;
	int f;

	i = 0;
	f = 0;
	while (i < S.n)
	{
		j = 0;
		while (j < S.n)
		{
			if (tab[i][j] == tetrimino.coord[3])
			{
				f = 1;
				break ;
			}
			j++;
		}
		if (f == 1)
			break ;
		i++;
	}
	j++;
	if (f == 0)
	{
		i = 0;
		j = 1;
	}
	if (j >= S.n)
	{
		j = 0;
		i++;
	}
	S.a = i;
	S.b = j;
	return (S);
}
