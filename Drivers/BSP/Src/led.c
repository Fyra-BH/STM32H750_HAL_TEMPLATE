/**
 * FileName     led.c
 * Description  driver for led
 * Author       Fyra-BH
 * email        1656832207@qq.com
 * 2020/4/3/18:55
*/

#include "led.h"

/**
  * @brief  initialize leds
  * @note   none
  * @param  void
  * @retval void
  */
void led_init(void)
{
     GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_GPIO_Port, LED_pin, GPIO_PIN_SET);

  /*Configure GPIO pin : LED_Pin */
  GPIO_InitStruct.Pin = LED_pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_GPIO_Port, &GPIO_InitStruct);
}

void led_on(uint8_t which)
{
    switch (which)
    {
    case 0:
        HAL_GPIO_WritePin(LED_GPIO_Port,LED_pin,GPIO_PIN_RESET);
        break;
    
    default:
        break;
    }
}
void led_off(uint8_t which)
{
    switch (which)
    {
    case 0:
        HAL_GPIO_WritePin(LED_GPIO_Port,LED_pin,GPIO_PIN_SET);
        break;
    
    default:
        break;
    }
}
