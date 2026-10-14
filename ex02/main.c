/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 10:52:29 by cycolonn          #+#    #+#             */
/*   Updated: 2026/10/14 18:47:02 by cycolonn         ###   ########.fr       */
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
    /* set data direction on output mode */
    DDRD |= (1U << DD5) | (1U << DD6) | (1U << DD3);

    /* set timer speed( prescaler 256 (62500hz))(cf p.116)*/
    SET(TCCR0B, CS02);                                 //timer 0
    TCCR2B |= (1U << CS22) | (1U << CS21);            //timer 2

    /* compare output mode (how the led react(non inverting))(cf p.113) */
    SET(TCCR0A, COM0B1);                              //red
    SET(TCCR0A, COM0A1);                              //green
    SET(TCCR2A, COM2B1);                              //blue 

    /* set fast PWM 8bits (counter count 0 to 255)(244 hz))*/
    TCCR0A |= (1U << WGM01) | (1U << WGM00);            //timer 0
    TCCR2A |= (1U << WGM21) | (1U << WGM20);            //timer 2
}

void set_rgb(uint8_t r, uint8_t g, uint8_t b)
{
    /* more the outcompare is hight more intense the color is*/
    OCR0B = r;
    OCR0A = g;
    OCR2B = b;
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
    uint8_t pos = 128;

    init_rgb();
    while (1)
    {
        wheel(pos++);
        _delay_ms(30);
    } 
}