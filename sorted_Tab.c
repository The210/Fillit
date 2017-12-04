/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_Tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 00:25:15 by dhorvill          #+#    #+#             */
/*   Updated: 2017/12/04 05:15:20 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "Fillit.h"
#include <fcntl.h>


t_tetri	*sorted_tab(t_tetri *tetriminos, int nbr_highest_size, int highest_size, int nbr_tetri)
{
	int	i;
	int	count;
	int	stock[nbr_highest_size + 1];
	t_tetri	t;

	i = -1;
	count = 0;
	stock[nbr_highest_size + 1] = '\0';
	while (i++ < nbr_tetri && count < (nbr_highest_size))
	{
		if (tetriminos[i].height == highest_size)
		{
			stock[count] = i;
			count++;
		}
		i++;
	}
	count = -1;
	while (++count < nbr_highest_size - 1)
	{
		t = tetriminos[(stock[count];
		tetriminos[stock[count]] = tetriminos[count];	
		tetriminos[count] = t;
	}
	return (tetriminos);
}

int	main(int argc, char **argv)
{
	int fd;
	int ret;
	char buf[4096];
	t_tetri *sa;

	fd = open(argv[1], O_RDONLY);
	ret = read(fd, buf, 4096);
	buf[ret] = '\0';
	sa = sorted_tab(ft_ret_tet(buf, ret), ft_atoi(argv[2]), ft_atoi(argv[3]), 8);
	ft_putnbr(sa[0].height);
	ft_putnbr(sa[1].height);
	ft_putnbr(sa[2].height);
	ft_putnbr(sa[3].height);
	ft_putnbr(sa[4].height);
	ft_putnbr(sa[5].height);
	ft_putnbr(sa[6].height);
	ft_putnbr(sa[7].height);
	return (0);
}
