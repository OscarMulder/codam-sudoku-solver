/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_sudoku.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/11 19:56:49 by omulder        #+#    #+#                */
/*   Updated: 2019/09/26 15:03:57 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

static int	isvalidchar(char c)
{
	return ((c >= '1' && c <= '9') || c == '.');
}

static int	check_str(char *str, int *count)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!isvalidchar(str[i]))
			return (FALSE);
		if (str[i] != '.')
			(*count)++;
		i++;
	}
	if (i == 9)
		return (TRUE);
	return (FALSE);
}

static int	check_is_valid(char **argv)
{
	int i;
	int count;

	i = 1;
	count = 0;
	while (i < 10)
	{
		if (!check_str(argv[i], &count))
			return (FALSE);
		i++;
	}
	if (count >= 17)
		return (TRUE);
	return (FALSE);
}

int			parse_sudoku(int (*sudoku)[82], char **argv)
{
	int i;

	if (!check_is_valid(argv))
		return (FALSE);
	i = 0;
	while (i < 81)
	{
		if (argv[(1 + (i / 9))][(i % 9)] != '.')
			(*sudoku)[i] = (argv[(1 + (i / 9))][(i % 9)] - '0');
		else
			(*sudoku)[i] = 0;
		i++;
	}
	return (TRUE);
}
