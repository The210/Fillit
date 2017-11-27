/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 03:41:30 by dhorvill          #+#    #+#             */
/*   Updated: 2017/11/27 03:41:31 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

#define BUF_SIZE 545

static char	**ft_create_table(char *buf, int ret)
{
	int		i;
	char	new_str[ret];
	char	**new_table;

	i = -1;
	ft_strcpy(new_str, buf);
	while (new_str[++i])
	{
		if (new_str[i] == '\n' && new_str[i + 1] == '\n')
		{
			new_str[i] = ' ';
			new_str[i + 1] = ' ';
		}
	}
	new_table = ft_strsplit(new_str, ' ');
	return (new_table);
}

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

static int	ft_find_highest(char **pdt)
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

static int	ft_find_longest(char **p, int longest)
{
	int	i;
	int j;
	int	k;

	i = -1;
	while (p[++i])
	{
		j = 0;
		while (p[i][j])
		{
			k = 0;
			if (p[i][j] != '#')
				j++;
			while (p[i][j] == '#' || (p[i][j - 1] == '#' &&
			p[i][j - 8] == '#') || (p[i][j - 1] == '#' && p[i][j - 5] == '#'))
			{
				k++;
				j++;
			}
			if (longest < k)
				longest = k;
		}
	}
	return (longest);
}

int			main(int argc, char **argv)
{
	int		fd;
	int		ret;
	int		longest;
	char	buf[BUF_SIZE + 1];
	char	**pdt;

	longest = 0;
	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	if ((pdt = ft_create_table(buf, ret)) == NULL)
		return (0);
	if (ft_find_highest(pdt) > ft_find_longest(pdt, longest))
		return (ft_find_highest(pdt));
	else
		return (ft_find_longest(pdt, longest));
}
