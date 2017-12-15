/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkvalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 21:13:41 by dhorvill          #+#    #+#             */
/*   Updated: 2017/12/04 17:07:12 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

#define BUF_SIZE 545

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
	return (count);
}

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

static int	det_valid_t(char *buf, int ret)
{
	int		t[4];
	char	**nt;

	t[0] = -1;
	t[1] = -1;
	t[3] = 0;
	nt = ft_create_table(buf, ret);
	while (nt[++t[0]])
	{
		t[2] = 0;
		while (nt[t[0]][++t[1]])
		{
			if (nt[t[0]][t[1]] == '#')
			{
				t[2]++;
				if (nt[t[0]][t[1] + 1] != '#' && nt[t[0]][t[1] - 1] != '#' &&
					nt[t[0]][t[1] + 5] != '#' && nt[t[0]][t[1] - 5] != '#')
					return (1);
			}
		}
		if (t[2] != 4)
			return (1);
	//	if (t[0] > 25) To check
	//=		return (1);
		t[1] = -1;
	}
	return (0);
}

static int	ft_more_checks(char *b, int t1)
{
	char	**pdt;
	int		i;
	int		j;
	int		flag;

	i = -1;
	j = 0;
	flag = 0;
	pdt = ft_strsplit(b, '\n');
	while (pdt[++i])
	{
		while (pdt[i][j])
			j++;
		if (j != 4)
			flag = 1;
		j = 0;
	}
	if (nbw(b, '\n') % 4 != 0)
		flag = 1;
	if (det_valid_t(b, t1) != 0)
		flag = 1;
	return (flag);
}

int			check_valid(int a, char **c)
{
	int		t[6];
	char	b[BUF_SIZE + 1];
	int		flag;

	flag = 0;
	t[2] = -1;
	t[3] = 0;
	if (a != 2)
	{
		ft_putstr("place-holder, usager message error\n");
		return (0);
	}
	t[0] = open(c[1], O_RDONLY);
	t[1] = read(t[0], b, BUF_SIZE);
	b[t[1]] = '\0';
	if (!*b)
		flag = 1;
	if (ft_more_checks(b, t[1]) != 0)
		flag = 1;
	if ((t[5] = ft_checks(t[2], t[3], b)) != 0)
		flag = 1;
	if (flag == 0)
		return (0);
	else
		ft_putstr("error\n");
	return (1);
}
