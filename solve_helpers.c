/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_helpers.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 15:25:35 by omulder        #+#    #+#                */
/*   Updated: 2020/01/05 15:34:56 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		place_valid_number_up(int (*sudoku)[82], int index, int *number)
{
	(*number)++;
	while (*number < 10)
	{
		(*sudoku)[index] = *number;
		if (check_number(*sudoku, index))
			return (TRUE);
		(*number)++;
	}
	(*sudoku)[index] = 0;
	return (FALSE);
}

int		place_valid_number_down(int (*sudoku)[82], int index, int *number)
{
	(*number)--;
	while (*number > 0)
	{
		(*sudoku)[index] = *number;
		if (check_number(*sudoku, index))
			return (TRUE);
		(*number)--;
	}
	(*sudoku)[index] = 0;
	return (FALSE);
}

int		sudokus_match(int (*sudoku)[82], int (*sudoku2)[82])
{
	int i;

	i = 0;
	while (i < 81)
	{
		if ((*sudoku)[i] != (*sudoku2)[i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	copy_sudoku(int (*sudoku)[82], int (*sudoku2)[82])
{
	int i;

	i = 0;
	while (i < 82)
	{
		(*sudoku2)[i] = (*sudoku)[i];
		i++;
	}
}
