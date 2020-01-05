/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_sudoku.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/11 20:25:43 by omulder        #+#    #+#                */
/*   Updated: 2019/07/11 23:02:19 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

void	print_sudoku(int sudoku[82])
{
	int i;

	i = 1;
	while (i < 82)
	{
		ft_putchar((sudoku[i - 1] + '0'));
		if (i != 0 && i % 9 == 0)
			ft_putchar('\n');
		else
			ft_putchar(' ');
		i++;
	}
}
