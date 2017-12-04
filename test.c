/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:10:39 by dhorvill          #+#    #+#             */
/*   Updated: 2017/11/30 22:14:49 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "Fillit.h"
#include <fcntl.h>
#define BUF_SIZE 4096

static char **ft_creat_table(char *buf, int ret)
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


//faut gerer segfault.
/*int		test_position(t_tetri tetriminos, int i, int j, char **tab)
  {
  int		count;
  int		k;
  int		m;
  int		n;

  k = 0;
  m = i;
  n = j;
  count = 0;
  while (tab[m][n] && count <= 3)
  {
  if (tab[m][n] == '.')
  count++;
  else
  break ;
  if (k <= 2)
  {
  if (tab[m][n] && tetriminos.coord[k] == 'R')
  n++;
  if (tab[m][n] && tetriminos.coord[k] == 'D')
  m++;
  if (tab[m][m] && tetriminos.coord[k] == 'L')
  n--;
  if (tab[m][n] && tetriminos.coord[k] == 'Z')
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
  {
  ft_putnbr(2);
  return (0);
  }
  else
  {
  ft_putnbr(1);
  return (1);
  }
  }*/


//marche si le test marche.
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


int	main(int argc, char **argv)
{
	int fd;
	int fd2;
	int ret;
	int ret2;
	char buf[BUF_SIZE + 1];
	char buf2[BUF_SIZE + 1];
	char **pdt;
	t_tetri *tetri_tab;

	fd2 = open(argv[2], O_RDONLY);
	ret2 = read(fd2, buf2, BUF_SIZE);
	buf2[ret2] = '\0';
	fd = open(argv[1], O_RDONLY);
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	tetri_tab = ft_ret_tet(buf2, ret2);
	if ((pdt = ft_strsplit(buf, '\n')) == NULL)
		return (0);
	int i;
	char **sd;
	i = 0;
	sd = draw_tetriminos(tetri_tab[0], 0, 2, pdt);
	while (i < 4)
	{
		ft_putstr(sd[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
