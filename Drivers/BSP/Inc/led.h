#ifndef _LED__H
#define _LED__H
/**
 * FileName     led.h
 * Description  driver for led
 * Author       Fyra-BH
 * email        1656832207@qq.com
 * 2020/4/3/18:55
*/
#include "stm32h7xx_hal.h"
#include "stdint.h"

#define LED_pin GPIO_PIN_1
#define LED_GPIO_Port GPIOA

void led_init(void);
void led_on(uint8_t which);
void led_off(uint8_t which);

#endif