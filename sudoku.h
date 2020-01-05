/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sudoku.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/11 19:49:41 by omulder        #+#    #+#                */
/*   Updated: 2020/01/05 15:38:22 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H
# define TRUE 1
# define FALSE 0

void	ft_putchar(char c);
void	ft_putstr(char *str);

/*
**  parse_sudoku.c
*/

int		parse_sudoku(int (*sudoku)[82], char **argv);

/*
**  solve_sudoku.c
*/

int		solve_sudoku(int (*sudoku)[82]);

/*
**  solve_recursive_solvers.c
*/

int		forward_solve_count_up(int (*sudoku)[82], int index);
int		forward_solve_count_down(int (*sudoku)[82], int index);
int		backwards_solve_count_up(int (*sudoku)[82], int index);
int		backwards_solve_count_down(int (*sudoku)[82], int index);

/*
**  solve_helpers.c
*/

int		place_valid_number_up(int (*sudoku)[82], int index, int *number);
int		place_valid_number_down(int (*sudoku)[82], int index, int *number);
int		sudokus_match(int (*sudoku)[82], int (*sudoku2)[82]);
void	copy_sudoku(int (*sudoku)[82], int (*sudoku2)[82]);

/*
**  solve_check_number.c
*/

int		check_number(int sudoku[82], int index);

/*
**  print_sudoku.c
*/

void	print_sudoku(int sudoku[82]);

#endif
