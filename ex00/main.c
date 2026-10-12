/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 10:52:29 by cycolonn          #+#    #+#             */
/*   Updated: 2026/10/12 19:31:53 by cycolonn         ###   ########.fr       */
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
        /* ignite red*/
        SET(PORTD, PD5);
        _delay_ms(1000);
        CLEAR(PORTD, PD5);

        /*ignite green*/
        SET(PORTD, PD6);
        _delay_ms(1000);
        CLEAR(PORTD, PD6);
        
        /*ignite blue*/
        SET(PORTD, PD3);
        _delay_ms(1000);
        CLEAR(PORTD, PD3);
    }

}