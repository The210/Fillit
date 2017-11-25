/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readstuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 22:35:52 by dhorvill          #+#    #+#             */
/*   Updated: 2017/11/24 18:29:49 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

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

static int det_valid_T(char* buf, int ret)
{
	int 	j;
	int 	i;
	char	new_str[ret];
	char	**new_table;

	i = 0;
	j = 0;
	ft_strcpy(new_str, buf);
	while (new_str[i])
	{
		if (new_str[i] == '\n' && new_str[i + 1] == '\n')
		{
			new_str[i] = ' ';
			new_str[i + 1] = ' ';
		}
		i++;
	}
	i = 0;
	new_table = ft_strsplit(new_str, ' ');
	while (new_table[i])
	{
		while (new_table[i][j])
		{
			if (new_table[i][j] == '#')
			{
				if (new_table[i][j + 1] != '#' && new_table[i][j - 1] != '#' &&
						   	new_table[i][j + 5] != '#' && new_table[i][j - 5] != '#')
				{
						ft_putstr("not a valid tetrimino shape \n");
						return (1);
						break ;
				}
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int 	fd;
	char	buf[BUF_SIZE + 1];
	int		ret;
	char	**pdt;
	int i;
	int j;
	int counterhash;

	i = 0;
	j = 0;
	counterhash = 0;
	if (argc != 2)
		ft_putstr("place-holder, usager message error");
	fd = open(argv[1], O_RDONLY);
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	pdt = ft_strsplit(buf, '\n');
	while (pdt[i])
	{
		while (pdt[i][j])
			j++;
		if (j != 4)
		{
			ft_putstr("not 4 characters per line\n");
			return (0);
			break;
		}
		i++;
		j = 0;
	}
	i = 0;
	if (nbw(buf, '\n') % 4 != 0)
	{
		ft_putstr("not 4 words per paragraph\n");
		return (0);
	}
	if (det_valid_T(buf, ret) == 1)
		return (0);
	while(buf[i])
	{
		if (buf[i] != '#' && buf[i] != '.' && buf[i] != '\n' && buf[i] != '\0')
		{
			ft_putstr("Wrong character found\n");
			return (0);
			break;
		}
		if (buf[i] == '\n')
		{
			j++;
			if (j % 4 != 0 && buf[i + 1] == '\n')
			{
				ft_putstr("wrong /n separator\n");
				return (0);
				break;
			}

		}
		/*if (buf[i] == '#')
		{
			if (buf[i - 1] != '#' && buf[i + 1] != '#' &&
					buf[i + 5] != '#' && buf[i - 5] != '#')
			{
				ft_putstr("Not a valid tetrimino shape\n");
				return (0);
				break;
			}
		}*/
		if (j % 4 == 0 && j != 0 && buf[i + 1] != '\n' && buf[i + 1])
		{
			ft_putstr("Error, no /n in between 4 lines\n");
			return (0);
			break; 
		}
		if (buf[i] == '#')
			counterhash++;
		if (j % 4 == 0 && j != 0)
		{
			if (counterhash % 4 != 0)
			{
				ft_putstr("not 4 #\n");
				return (0);
				break;
			}
			counterhash = 0;
			i++;
			j = 0;
		}
		i++;
	}
	ft_putstr("Succes!\n");
	return (0);
}
