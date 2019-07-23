/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 11:36:59 by fhenrion          #+#    #+#             */
/*   Updated: 2019/06/12 11:49:53 by linfan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_rm_piece(char **grid, int position, int size, int *tab)
{
	int	x;
	int	y;
	int	i;

	x = position % size;
	y = position / size;
	i = 0;
	while (i < 8)
	{
		grid[y + tab[i + 1]][x + tab[i]] = '.';
		i += 2;
	}
}

void	ft_put_piece(char **grid, int position, int size, int *tab)
{
	int	x;
	int	y;
	int	i;

	x = position % size;
	y = position / size;
	i = 0;
	while (i < 8)
	{
		grid[y + tab[i + 1]][x + tab[i]] = tab[8];
		i += 2;
	}
}

int		ft_check_position(char **grid, int position, int size, int *tab)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = position % size;
	y = position / size;
	while (i < 8)
	{
		if ((x + tab[i]) >= size || (y + tab[i + 1]) >= size)
			return (0);
		if (grid[y + tab[i + 1]][x + tab[i]] != '.')
			return (0);
		i += 2;
	}
	return (1);
}
