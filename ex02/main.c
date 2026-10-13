/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 10:52:29 by cycolonn          #+#    #+#             */
/*   Updated: 2026/10/13 19:37:15 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
    red ->timer output = OC0B
    green ->timer output = OC0A
    blue ->timer output = OC1B
*/

void init_rgb()
{
    /* set data direction on output mode*/
    DDRB = (1U << DD3) | (1U << DD5) | (1U << DD6);

    /* set the prescaler to 256 (224HZ) (cf p.116)*/
    SET(TCCR0B, CS02);              //timer 0
    SET(TCCR1B, CS12);              //timer 1

    /* compare output mode (how the led react(non inverting))(cf p.113) */
    SET(TCCR0B, COM0B1);            //red
    SET(TCCR0A, COM0A1);            //green
    SET(TCCR1B, COM1B1);            //blue 

    /* set fast PWM 8bits (counter count 0 to 255)*/
    TCCR0A |= (1U << WGM01) | (1U << WGM00);            //timer 0
    TCCR1A |= (1U << WGM12) | (1U << WGM10);            //timer 1
}

void set_rgb(uint8_t r, uint8_t g, uint8_t b)
{

}

void wheel(uint8_t pos)
{
    pos = 255 - pos;
    if (pos < 85)
    {
        set_rgb(255 - pos * 3, 0, pos * 3);
    }
    else if (pos < 170)
    {
        pos = pos - 85;
        set_rgb(0, pos * 3, 255 - pos * 3);
    }
    else
    {
        pos = pos - 170;
        set_rgb(pos * 3, 255 - pos * 3, 0);
    }
}

int main()
{
       
}