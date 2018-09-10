/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsqhead.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhrazz <fkhrazz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:35:35 by nkertzma          #+#    #+#             */
/*   Updated: 2018/09/10 21:02:00 by fkhrazz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQHEAD_H
# define BSQHEAD_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

int     g_map_width;
int     g_map_height;
char    g_map_symbols[3];

// Prototypes for check input
void	check_first_line(char *str);
int		check_input(char *str);
void    get_width(char *str);
int		check_width(char *str);
int		check_height(char *str);
int		check_content(char *str);

// Prototypes for input_to_arr
char    **input_to_arr(char *str);
char    **render_arr(char **arr, char *str);
char    **arr_to_num(char **arr);
char    **allocate_memory(char **arr);

#endif