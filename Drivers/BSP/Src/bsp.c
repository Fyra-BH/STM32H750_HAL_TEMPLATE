/**
 * FileName     bsp.c
 * Description  to initialize all the hardware
 * Author       Fyra-BH
 * email        1656832207@qq.com
 * 2020/4/3/19:51
*/

#include "bsp.h"

void bsp_init(void)
{
    SystemClock_Config();
    led_init();
    uart_init();
}

