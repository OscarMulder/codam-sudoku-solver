/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_solvers.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 15:01:41 by omulder        #+#    #+#                */
/*   Updated: 2020/01/05 15:25:12 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

/*
** You see these functions all look the same, so why do I have so much duplicate
** code? Well, they work differently, and they already do to much. If I split
** them up and make them more modular, I would have less duplicate code, but it
** would make things more complicated and to be honest I am to lazy.
*/

int		forward_solve_count_up(int (*sudoku)[82], int index)
{
	int number;
	int solved;

	if (index == 81)
		return (TRUE);
	if ((*sudoku)[index] != 0)
	{
		if (check_number(*sudoku, index))
			return (forward_solve_count_up(sudoku, index + 1));
		return (FALSE);
	}
	number = 0;
	solved = FALSE;
	while (number < 10 && solved == FALSE)
	{
		if (!place_valid_number_up(sudoku, index, &number))
			return (FALSE);
		solved = forward_solve_count_up(sudoku, index + 1);
	}
	if (solved)
		return (TRUE);
	return (FALSE);
}

int		forward_solve_count_down(int (*sudoku)[82], int index)
{
	int number;
	int solved;

	if (index == 81)
		return (TRUE);
	if ((*sudoku)[index] != 0)
	{
		if (check_number(*sudoku, index))
			return (forward_solve_count_down(sudoku, index + 1));
		return (FALSE);
	}
	number = 10;
	solved = FALSE;
	while (number > 0 && solved == FALSE)
	{
		if (!place_valid_number_down(sudoku, index, &number))
			return (FALSE);
		solved = forward_solve_count_down(sudoku, index + 1);
	}
	if (solved)
		return (TRUE);
	return (FALSE);
}

int		backwards_solve_count_up(int (*sudoku)[82], int index)
{
	int number;
	int solved;

	if (index == -1)
		return (TRUE);
	if ((*sudoku)[index] != 0)
		return (backwards_solve_count_up(sudoku, index - 1));
	number = 0;
	solved = FALSE;
	while (number < 10 && solved == FALSE)
	{
		if (!place_valid_number_up(sudoku, index, &number))
			return (FALSE);
		solved = backwards_solve_count_up(sudoku, index - 1);
	}
	if (solved)
		return (TRUE);
	return (FALSE);
}

int		backwards_solve_count_down(int (*sudoku)[82], int index)
{
	int number;
	int solved;

	if (index == -1)
		return (TRUE);
	if ((*sudoku)[index] != 0)
		return (backwards_solve_count_down(sudoku, index - 1));
	number = 10;
	solved = FALSE;
	while (number > 0 && solved == FALSE)
	{
		if (!place_valid_number_down(sudoku, index, &number))
			return (FALSE);
		solved = backwards_solve_count_down(sudoku, index - 1);
	}
	if (solved)
		return (TRUE);
	return (FALSE);
}
