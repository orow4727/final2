/*
 * **    blink.c -    blink with 1s delay
 * */

#include <stdio.h>
#include <unistd.h>
#include <gpiod.h>

#define GPIOCHIP        3


//gpio 19 is P9_27
//gpio 21 is P9_25

int
main(int argc, char *argv[])
{
    struct gpiod_chip *output_chip;
    struct gpiod_line *output_line19;
    struct gpiod_line *output_line21;


    /* open chip and get line */
    output_chip = gpiod_chip_open_by_number(3);
    output_line19 = gpiod_chip_get_line(output_chip, 19);
    output_line21 = gpiod_chip_get_line(output_chip, 21);

    /* config as output and set a description */
    gpiod_line_request_output(output_line19, "bp",
            GPIOD_LINE_ACTIVE_STATE_HIGH);
    gpiod_line_request_output(output_line21, "rf",
            GPIOD_LINE_ACTIVE_STATE_HIGH);


    gpiod_line_set_value(output_line19, 1); //turn off bp
    gpiod_line_set_value(output_line21, 0); //turn on rf
}
