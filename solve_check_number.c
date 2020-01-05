/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_number.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/11 20:40:38 by omulder        #+#    #+#                */
/*   Updated: 2020/01/05 15:00:34 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

static int	check_block(int sudoku[82], int index)
{
	int row;
	int col;
	int i;
	int j;

	row = index / 9;
	col = index % 9;
	i = ((row / 3) * 27) + ((col / 3) * 3);
	j = 1;
	while (j <= 9)
	{
		if (sudoku[i] == sudoku[index] && i != index)
			return (FALSE);
		if (j % 3 == 0)
			i += 7;
		else
			i++;
		j++;
	}
	return (TRUE);
}

static int	check_column(int sudoku[82], int index)
{
	int i;

	i = (index % 9);
	while (i < 81)
	{
		if (i == index)
			i += 9;
		else if (sudoku[i] != sudoku[index])
			i += 9;
		else
			return (FALSE);
	}
	return (TRUE);
}

static int	check_row(int sudoku[82], int index)
{
	int i;
	int j;

	i = (index / 9) * 9;
	j = 0;
	while (j < 9)
	{
		if (i == index)
			i++;
		else if (sudoku[i] != sudoku[index])
			i++;
		else
			return (FALSE);
		j++;
	}
	return (TRUE);
}

/*
** This beautifull commented out code was an attempt to optimize my solver.
** Unfortunately this turned out to be slower then using the 3 functions above.
** I'm going to keep it here as a reminder that less looping doesn't have to
** be faster.
*/

/*
**  int			check_number(int sudoku[82], int index, int num)
**  {
** 		int i;
** 		int j;
** 		int xtra;
** 		int col;
** 		int row;
** 		int box;
**
** 		i = (((index / 9) / 3) * 27) + (((index % 9) / 3) * 3);
** 		j = 0;
** 		xtra = 0;
** 		while (j < 9)
** 		{
** 			row = ((index / 9) * 9) + j;
** 			col = (index % 9) + (j * 9);
** 			box = i + j + xtra;
** 			if (row != index && sudoku[row] == num)
** 				return (FALSE);
** 			if (col != index && sudoku[col] == num)
** 				return (FALSE);
** 			if (box != index && sudoku[box] == num)
** 				return (FALSE);
** 			if ((j + 1) % 3 == 0)
** 				xtra += 6;
** 			j++;
** 		}
** 		return (TRUE);
**	}
*/

int			check_number(int sudoku[82], int index)
{
	if (!check_row(sudoku, index))
		return (FALSE);
	if (!check_column(sudoku, index))
		return (FALSE);
	if (!check_block(sudoku, index))
		return (FALSE);
	return (TRUE);
}
