/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_sudoku.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/11 20:32:28 by omulder        #+#    #+#                */
/*   Updated: 2020/01/05 16:08:33 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

/*
** This function does some counting! Specifically, it counts the amount of
** filled in numbers in the first and last line of the sudoku. If the last line
** has more numbers, it will return TRUE so the sudoku can be solved in reverse.
** In most cases this should be the faster way to solve it.
** A better way would be to calculate a score for forward and reverse solving,
** based on where the numbers are filled in, but let's not overdo it.
*/

static int	check_for_rev_solve(int (*sudoku)[82])
{
	int		first_line_count;
	int		last_line_count;
	int		i;

	first_line_count = 0;
	last_line_count = 0;
	i = 0;
	while (i < 9)
	{
		if ((*sudoku)[i] != 0)
			first_line_count++;
		i++;
	}
	i = 72;
	while (i < 81)
	{
		if ((*sudoku)[i] != 0)
			last_line_count++;
		i++;
	}
	if (last_line_count > first_line_count)
		return (TRUE);
	return (FALSE);
}

/*
** This function solves the sudoku twice. Once to solve it. And
** another time to make sure there is only one solution.
** It can do this either forwards (starting at index 0) or backwards (starting
** at index 80) depending on how many numbers are already filled on the first
** and last line.
*/

int			solve_sudoku(int (*sudoku)[82])
{
	int	sudoku2[82];
	int	first;
	int	second;
	int	reverse;

	copy_sudoku(sudoku, &sudoku2);
	reverse = check_for_rev_solve(sudoku);
	if (reverse)
		first = backwards_solve_count_up(sudoku, 80);
	else
		first = forward_solve_count_up(sudoku, 0);
	if (first == FALSE)
		return (FALSE);
	if (reverse)
		second = backwards_solve_count_down(&sudoku2, 80);
	else
		second = forward_solve_count_down(&sudoku2, 0);
	if (second == FALSE)
		return (FALSE);
	return (sudokus_match(sudoku, &sudoku2));
}
