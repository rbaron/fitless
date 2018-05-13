#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"
#include "nrf_gpio.h"
#include "SEGGER_RTT.h"

int main(void)
{

    SEGGER_RTT_WriteString(0, "Hello, world!\n");

    for (int i = 0; i < 32; i++ ) {
      nrf_gpio_cfg_output(i);
    }

    while (true)
    {
        nrf_gpio_pin_toggle(30);
        nrf_delay_ms(500);
        nrf_gpio_pin_toggle(0);
        SEGGER_RTT_WriteString(0, "$ bling bling $!\n");
    }
}
