/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavienhenrion <flavienhenrion@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 18:02:36 by fhenrion          #+#    #+#             */
/*   Updated: 2019/07/19 21:59:52 by flavienhenr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*ft_save_piece(char *piece, char c)
{
	static t_list	*list;
	t_list			*tmp;
	int				*tab;

	tab = ft_parse_piece(piece, c);
	if (!list && tab)
	{
		list = ft_lstnew(tab, sizeof(int) * 9);
		free(tab);
	}
	else if (tab)
	{
		tmp = ft_lstnew(tab, sizeof(int) * 9);
		free(tab);
		ft_lstadd_end(&list, tmp);
	}
	else
		return (NULL);
	return (list);
}

int		ft_check_piece(char *piece, int end)
{
	int	i;
	int	hash;

	i = 0;
	hash = 0;
	while (piece[i] != '\0')
	{
		if (!(piece[i] == '#' || piece[i] == '.' || piece[i] == '\n'))
			return (1);
		if (piece[i] == '#')
			hash++;
		else if (!end && piece[i] == '\n' \
				&& !(i == 4 || i == 9 || i == 14 || i == 19 || i == 20))
			return (1);
		else if (end && piece[i] == '\n' \
				&& !(i == 4 || i == 9 || i == 14 || i == 19))
			return (1);
		i++;
	}
	if (end && ft_strlen(piece) != 20)
		return (1);
	if (hash != 4)
		return (1);
	return (0);
}

t_list	*ft_read_file(int fd)
{
	int		count;
	int		nb_pieces;
	char	buf[22];
	char	c;

	c = 'A';
	nb_pieces = 0;
	while ((count = read(fd, buf, 21)) == 21)
	{
		buf[count] = '\0';
		if (ft_check_piece(buf, 0))
			return (NULL);
		else if (!ft_save_piece(buf, c++))
			return (NULL);
		nb_pieces++;
	}
	buf[count] = '\0';
	if (ft_check_piece(buf, 1) || nb_pieces > 25)
		return (NULL);
	else
		return (ft_save_piece(buf, c));
}
