/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 03:51:22 by dhorvill          #+#    #+#             */
/*   Updated: 2017/12/04 19:54:48 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

#define BUF_SIZE 545

static int	ft_is_there_h(char *line)
{
	int i;
	int	flag;

	i = 0;
	flag = 0;
	while (line[i])
	{
		if (line[i] == '#')
		{
			flag = 1;
			break ;
		}
		i++;
	}
	return (flag);
}

int	ft_find_highest(char **pdt)
{
	char	**line;
	int		i;
	int		j;
	int		k;
	int		highest;

	i = -1;
	highest = 0;
	while (pdt[++i])
	{
		k = 0;
		j = 0;
		line = ft_strsplit(pdt[i], '\n');
		while (line[j] && ft_is_there_h(line[j]) == 0)
			j++;
		while (line[j] && ft_is_there_h(line[j]) == 1)
		{
			k++;
			j++;
		}
		if (k >= highest)
			highest = k;
	}
	return (highest);
}

int ft_find_longest(char **pdt)
{
	int i;
	int j;
	int counter;
	int longest;
	
	longest = 1;
	while (pdt[i])
	{
		j = 0;
		counter = 1;
		while (pdt[i][j])
		{
			if (pdt[i][j] == '#' && (pdt[i][j + 1] == '#' || pdt[i][j + 6] == '#'))
				counter++;
			j++;
		}
		if (counter > longest)
			longest = counter;
		i++;
	}
}

int			ft_count_l(char **pdt, int highest)
{
	char	**line;
	int		i;
	int		j;
	int		k;
	int		counter;

	i = -1;
	counter = 0;
	while (pdt[++i])
	{
		k = 0;
		j = 0;
		line = ft_strsplit(pdt[i], '\n');
		while (line[j] && ft_is_there_h(line[j]) == 0)
			j++;
		while (line[j] && ft_is_there_h(line[j]) == 1)
		{
			k++;
			j++;
		}
		if (k == highest)
			counter++;
	}
	ft_putnbr(counter);
	return (counter);
}
