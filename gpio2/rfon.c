#include <stdio.h>
#include <unistd.h>
#include <gpiod.h>
 
int main(){

        struct gpiod_chip *output_chip;
        struct gpiod_line *output_line46;
        struct gpiod_line *output_line47;
        int line_value;

        /* open chip and get line */
        output_chip = gpiod_chip_open_by_number(0);
        output_line46 = gpiod_chip_get_line(output_chip, 46);
        output_line47 = gpiod_chip_get_line(output_chip, 47);

        /* config as output and set a description */
        gpiod_line_request_output(output_line46, "blink",
                GPIOD_LINE_ACTIVE_STATE_HIGH);
        gpiod_line_request_output(output_line47, "blink",
                GPIOD_LINE_ACTIVE_STATE_HIGH);

        
        
        gpiod_line_set_value(output_line46, 0);
        gpiod_line_set_value(output_line47, 1);

}

