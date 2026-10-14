/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 10:52:29 by cycolonn          #+#    #+#             */
/*   Updated: 2026/10/14 18:44:08 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"   

int main()
{
    SET(DDRD,DD5);
    SET(DDRD,DD6);
    SET(DDRD,DD3);

    while (1)
    {
        /*RED*/
        PORTD = (1U << PD5);
        _delay_ms(1000);

        /*GREEN*/
        PORTD = (1U << PD6);
        _delay_ms(1000);

        /*BLUE*/
        PORTD = (1U << PD3);
        _delay_ms(1000);
    }
}