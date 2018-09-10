/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhrazz <fkhrazz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 19:42:09 by nkertzma          #+#    #+#             */
/*   Updated: 2018/09/10 21:21:57 by fkhrazz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsqhead.h"

char    **input_to_arr(char *str)
{
    char **arr;
    int i;
    int height;
    
    i = 0;
    height = g_map_height;
    arr = malloc(sizeof(char *) * g_map_height);
    while (height > 0)
    {
        arr[i] = (char *)malloc(sizeof(char) * g_map_width);
        height--;
        i++;
    }
    printf("%s", "OK");
    arr = render_arr(arr, str);
    return (arr);
}

char    **render_arr(char **arr, char *str)
{
    int i;
    int k;
    int fd;
    char buf;

    printf("%s", "OK");
    i = 0;
    k = 0;
    fd = open(str, O_RDONLY);
    while (read(fd, &buf, 1) && buf != '\n')
    {
        i++;
    }
    i = 0;
    read(fd, &buf, 1);
    while (read(fd, &buf, 1))
    {
        if (buf == '\n')
        {
            k = 0;
            i++;
        }
        else
        {
            arr[i][k] = buf;
            k++;
        }
    }
    close (fd);
    arr = arr_to_num(arr);
    return (arr);
}

char    **arr_to_num(char **arr)
{
    int i;
    int k;
    int height;
    int width;

    i = 0;
    k = 0;
    height = g_map_height;
    width = g_map_width;
    while (height >= 0)
    {
        while (width >= 0)
        {
            if (arr[i][k] == g_map_symbols[0])
            {
                arr[i][k] = '1';
            }
            if (arr[i][k] == g_map_symbols[1])
            {
                arr[i][k] = '0';
            }
            k++;
        }
        k = 0;
        i++;
    }
    return (arr);
}

char    **allocate_memory(char **arr)
{
    int height;

    height = g_map_height;
    arr = (char **)malloc(sizeof(char *) * g_map_height * 10000);
    while (height >= 0)
    {
        *arr = (char *)malloc(sizeof(char) * g_map_width * 10000);
        height--;
    }
    return (arr);
}
