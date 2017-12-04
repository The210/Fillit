/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 21:02:29 by dhorvill          #+#    #+#             */
/*   Updated: 2017/12/03 20:47:16 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

typedef struct	s_tetri
{
	char	coord[3];
	int		length;
	int		height;
}				t_tetri;

t_tetri *ft_ret_tet(char *buf, int ret);
#endif
