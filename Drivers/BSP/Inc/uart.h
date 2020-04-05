#ifndef _UART__H
#define _UART__H
/**
 * FileName     uart.h
 * Description  driver for uart
 * Author       Fyra-BH
 * email        1656832207@qq.com
 * 2020/4/3/19:26
*/
#include "stm32h7xx_hal.h"
#include "stdint.h"
#include "stdarg.h"
#include "string.h"


void uart_init(void);
void uprint(const char *s, ...);

#endif

