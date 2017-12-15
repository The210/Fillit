/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:53:35 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/12/14 18:33:37 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	**pdt;
	t_tetri *listtetri;
	t_misc	S;

	S.a = 0;
	S.b = 0;
	S.c = 0;
	S.d = 0;
	S.e = -1;
	fd = open(argv[1], O_RDONLY);
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	if ((pdt = ft_create_table(buf, ret)) == 0)
		return (0);
	if (check_valid(argc, argv) == 1)
		return (1);
	listtetri = ft_ret_tet(buf, ret);
	ret = ft_find_longest(pdt);
	fd = ft_find_highest(pdt);
	S.n = size_square(listtetri[0].nbr, fd, ret);
	pdt = resolve_recursive(S, listtetri);
	ft_putstr_improved(pdt, S.n + 1);
	return (0);
}
