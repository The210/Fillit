/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 03:51:22 by dhorvill          #+#    #+#             */
/*   Updated: 2017/11/27 04:08:18 by dhorvill         ###   ########.fr       */
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

static int	ft_count_l(char **pdt, int highest)
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

int			main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	**pdt;

	fd = open(argv[1], O_RDONLY);
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	if ((pdt = ft_create_table(buf, ret)) == NULL)
		return (0);
	return (ft_count_l(pdt, ft_find_highest(pdt)));
}
