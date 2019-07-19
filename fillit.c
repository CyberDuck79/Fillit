/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavienhenrion <flavienhenrion@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 12:18:13 by fhenrion          #+#    #+#             */
/*   Updated: 2019/07/19 22:52:35 by flavienhenr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_backtrack(char **grid, t_list *lst, int size, int position)
{
	if (!lst)
		return (1);
	while (position < size * size)
	{
		if (ft_check_position(grid, position, size, lst->content))
		{
			ft_put_piece(grid, position, size, lst->content);
			if (ft_backtrack(grid, lst->next, size, 0))
				return (1);
			ft_rm_piece(grid, position, size, lst->content);
		}
		position++;
	}
	return (0);
}

static int	ft_solve(t_list *lst)
{
	char	**grid;
	int		size;

	size = ft_start_size(lst);
	grid = ft_gen_grid(size);
	while (!ft_backtrack(grid, lst, size, 0))
	{
		ft_free_grid(grid, size++);
		grid = ft_gen_grid(size);
	}
	ft_print_grid(grid, size);
	ft_free_coord(lst);
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_list	*lst;

	if (argc != 2)
	{
		ft_putstr(USAGE);
		return (0);
	}
	else
		fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("error\n");
		return (0);
	}
	lst = ft_read_file(fd);
	if (lst)
		ft_solve(lst);
	else
		ft_putstr("error\n");
	close(fd);
	return (0);
}
