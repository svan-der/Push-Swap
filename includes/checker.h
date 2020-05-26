/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 16:24:14 by svan-der      #+#    #+#                 */
/*   Updated: 2020/05/26 15:43:47 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "psw_env.h"

int		main(int argc, char **argv);
int		get_instruction(t_pw_var *stvar);
int		check_instruction(t_sort *opt, char *line, int *valid);
int		put_instruction(t_inst **inst_lst, t_sort opt, char *line);
#endif
