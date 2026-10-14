/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 10:52:29 by cycolonn          #+#    #+#             */
/*   Updated: 2026/10/14 18:25:27 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int checkline(char *rgb , int i)
{
    if(rgb[0] != '#') 
        return 0;
    for (int j = 1 ; j < i ; j ++)
    {
        if (!((rgb[j] >= 'A' && rgb[j] <= 'F') || (rgb[j] >= '0' && rgb[j] <= '9')))
            return 0;
    }
    return 1;
}

int getline(char *rgb)
{
    for (int i = 0; i < 7; i++)
    {
        rgb[i] = uart_rx();
        uart_tx(rgb[i]);
        if (!checkline(rgb, i))
            return 0;
    }
    rgb[7] = 0;
    return 1;
}

uint32_t ft_atoi_hex(const char *str)
{
    uint32_t res = 0;

    while (*str)
    {
        res *= 16;
        if (*str >= '0' && *str <= '9')
            res += *str - '0';
        else if (*str >= 'A' && *str <= 'F')
            res += *str - 'A' + 10;
        str++;
    }
    return (res);
}

void display_color(char *rgb)
{
    uint32_t hex = ft_atoi_hex(rgb);
    uint8_t r = (hex >> 16);
    uint8_t g = (hex >> 8);
    uint8_t b = hex;

    set_rgb(r,g,b);
    uart_printstr(" Display : ");
    uart_printstr(rgb);
    uart_printstr("\r\n");
}

int main()
{
    char rgb[8];

    init_rgb();
    uart_init();
    while (1)
    {
        if (!getline(rgb))
            uart_printstr(" Error: INVALID ARGUMENT\r\n");
        else 
            display_color(rgb);
    } 
}

/*
** test colors (#RRGGBB format):
**
** #FF0000 - Red
** #00FF00 - Green
** #0000FF - Blue
** #FFFF00 - Yellow (Red + Green)
** #00FFFF - Cyan (Green + Blue)
** #FF00FF - Magenta (Red + Blue)
** #FFFFFF - White (Red + Green + Blue)
*/