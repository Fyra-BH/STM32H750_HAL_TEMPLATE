/**
 * FileName     main.c
 * Description  
 * Author       Fyra-BH
 * email        1656832207@qq.com
 * 2020/4/3/19:55
*/
#include "stm32h7xx_hal.h"
#include "bsp.h"

int main(void)
{
  HAL_Init();
  bsp_init();

  uint8_t led_state=0;
  while (1){
    HAL_Delay(500);
    print("hello world\r\n");
    if(led_state){
      led_on(0);
    }else{
      led_off(0);
    }
    led_state=!led_state;
  }
  
}
