/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:12:48 by fkhrazz           #+#    #+#             */
/*   Updated: 2018/09/10 20:37:27 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsqhead.h"

/*
Function for check and verificate input map
*/

void	check_first_line(char *str)
{
    int fd;
	char buf;

	g_map_height = 0;
	fd = open(str, O_RDONLY);
	while (read(fd, &buf, 1))
	{
		if (buf >= '0' && buf <= '9')
			g_map_height = g_map_height * 10 + (buf - '0');
        else
		{
			g_map_symbols[0]=buf;
			read(fd, &buf, 1);
			g_map_symbols[1]=buf;
			read(fd, &buf, 1);
			g_map_symbols[2]=buf;
			break ;
		}
	}
	close(fd);
}

int		check_input(char *str)
{
	get_width(str);
	if (check_width(str) || check_height(str))
	{
		printf("%s\n", "ERROR");
		return (1);
	}
	return (0);
}

void	get_width(char *str)
{
	int fd;
	int i;
	char buf;

	i = 0;
	g_map_width = 0;
	fd = open(str, O_RDONLY);
	while (read(fd, &buf, 1) && buf != '\n')
	{
		i++;
	}
	buf = '0';
	while (read(fd, &buf, 1) && buf != '\n')
	{
		g_map_width++;
	}
	close(fd);
}

int		check_width(char *str)
{
	int fd;
	int i;
	char buf;

	i = 1;
	fd = open(str, O_RDONLY);
	while (read(fd, &buf, 1) && buf != '\n')
	{
		i++;
	}
	i = 1;
	buf = '0';
	while (read(fd, &buf, 1))
	{
		while (read(fd, &buf, 1) && buf != '\n')
		{
			i++;
		}
		if (i < g_map_width || i > g_map_width)
		{
			close(fd);
			return (1);
		}
		i = 1;
	}
	close (fd);
	return (0);
}

int		check_height(char *str)
{
	int fd;
	int real_height;
	char buf;

	real_height = 0;
	fd = open(str, O_RDONLY);
	while (read(fd, &buf, 1) && buf != '\n')
	{
		real_height++;
	}
	real_height = 0;
	buf = '0';
	while (read(fd, &buf , 1))
	{
		if (buf == '\n')
		{
			real_height++;
		}
	}
	if (real_height != g_map_height)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

int		check_content(char *str)
{
	int fd;
	int i;
	char buf;

	i = 0;
	fd = open(str, O_RDONLY);
	while (read(fd, &buf, 1) && buf != '\n')
	{
		i++;
	}
	while (read(fd, &buf, 1))
	{
		if (buf >= 'a' && buf <= 'z')
		{
			return (1);
		}
	}
	close(fd);
	return (0);
}

/*void		check_input(char *av)
{
	int		fd;
	int		height;
	int		width;
	char	c;
	int		width_check;

	
	height = 0;
	width = check_width(av, width);
	width_check = 0;
	//check_height(av, height);
	//check_on_right_width(av, width, height);
}

int     check_width(char *av, int width)
{
	int		fd;
	char	c;

	fd = open(av, O_RDONLY);
	while (read(fd, &c, 1))
	{	
		printf("%c\n", c);
		if (c != '\n')
			break ;
	}
	read(fd, &c, 1);
	printf("%c\n", c);
	while (read(fd, &c, 1))
	{
		printf("%c\n", c);
		while(c != '\n')
			width++;
	}
	close(fd);
	printf("%d\n", width);
    return (width);
}

int     check_height(char *av, int height)
{
	int		fd;
	char	c;

	fd = open(av, O_RDONLY);
	read(fd, &c, 1);
	while (read(fd, &c, 1))
	{
		if(c == '\n')
			height++;
	}
	height -= 1;
	close(fd);
    return (height);
}

int		check_on_right_width(char *av, int width, int height)
{
	int		fd;
	char	c;
	int		width_check;

	fd = open(av, O_RDONLY);
	read(fd, &c, 1);
	while (read(fd, &c, 1))
	{
		while(c != '\n')
		{
			width_check++;
			if (c != g_map_symbols[0] || c != g_map_symbols[1] || c != g_map_symbols[2])
				return (0);
		}
		if (width_check != width)
			return (0);
		width_check = 0;
	}
	height -= 1;
	close(fd);
    return (height);
}*/