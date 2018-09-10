/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 19:41:02 by fkhrazz           #+#    #+#             */
/*   Updated: 2018/09/10 20:16:23 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
int minimal(int a, int b, int c);


int	check_square(int left_up_x, int left_up_y, char **array)
{
	char	a[4];
	int		min;

	a[0] = array[left_up_x][left_up_y]; 
	a[1] = array[left_up_x][left_up_y+1]; 
	a[2] = array[left_up_x + 1][left_up_y]; 
	a[3] = array[left_up_x + 1][left_up_y + 1];
	if (a[3] == '0')
		return (0);
	min = minimal(a[0], a[1], a[2]);
	array[left_up_x + 1][left_up_y + 1] += min;
	return (1);
}

int minimal(int a, int b, int c)
{
	int mass[3];
	int n;
	int m;
	int temp;

	mass[0] = a;
	mass[1] = b;
	mass[2] = c;
	n = 0;
	while (n < 3)
	{
		m = 0;
		while (m < 2)
		{
			if (mass[m] < mass[m + 1])
			{
				temp = mass[m];
				mass[m] = mass[m + 1];
				mass[m + 1] = temp;
			}
			m++;
		}
		n++;
	}
	printf("min: %d\n", mass[0]);
	return (mass[0]);
}