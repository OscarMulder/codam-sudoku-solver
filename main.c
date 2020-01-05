/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/11 19:41:58 by omulder        #+#    #+#                */
/*   Updated: 2020/01/05 15:39:10 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		main(int argc, char **argv)
{
	int	sudoku[82];

	sudoku[81] = 0;
	if (argc != 10 || !parse_sudoku(&sudoku, argv))
	{
		ft_putstr("Error\n");
		return (1);
	}
	else if (solve_sudoku(&sudoku))
		print_sudoku(sudoku);
	else
	{
		ft_putstr("Error\n");
		return (1);
	}
	return (0);
}
