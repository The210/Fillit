/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:49:00 by dhorvill          #+#    #+#             */
/*   Updated: 2017/11/09 17:00:32 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int i;
	int j;
	int negative;

	j = 0;
	negative = 0;
	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ' ||
			str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		negative = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		j = (j * 10) + str[i] - '0';
		i++;
	}
	if (negative == 1)
		return (-j);
	else
		return (j);
}
