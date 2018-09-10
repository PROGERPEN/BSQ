/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 13:24:16 by fkhrazz           #+#    #+#             */
/*   Updated: 2018/09/10 21:15:02 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsqhead.h"

int	main(int ac, char **av)
{
	ac = 1;
	check_first_line(av[1]);
	if (check_input(av[1]))
	{
		return (0);
	}
	input_to_arr(av[1]);
	return (0);
}