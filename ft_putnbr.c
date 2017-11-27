/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:41:00 by dhorvill          #+#    #+#             */
/*   Updated: 2017/11/11 15:53:45 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		puis(int no, int i)
{
	int x;
	int y;

	x = 1;
	y = 1;
	while (y <= i)
	{
		x *= no;
		y++;
	}
	return (x);
}

void			ft_putnbr(int nb)
{
	int	count;
	int n;

	count = 1;
	if (nb == 0)
		ft_putchar('0');
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = (nb * -1) - 2000000000;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	n = nb;
	while (n >= 1)
	{
		n = n / 10;
		count++;
	}
	while (--count > 0)
		ft_putchar((nb / puis(10, (count - 1))) % 10 + '0');
}
