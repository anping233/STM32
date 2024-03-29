#include    "include.h"
void gpio_init(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;


    GPIOA->AFR[1]   &= ~(0x0f << 20);    /*引脚13设置为输出模式*/
    GPIOA->AFR[1]   |= GPIO_AF_SWJ;    /*引脚13设置为输出模式*/
    GPIOA->AFR[1]   |= GPIO_AF_SWJ;    /*引脚13设置为输出模式*/
    GPIOA->MODER    &= ~GPIO_MODER_MODER13_Msk;    /*引脚13设置为输出模式*/
    GPIOA->MODER    &= ~GPIO_MODER_MODER14_Msk;    /*引脚13设置为输出模式*/
    GPIOA->MODER    |= GPIO_MODER_MODER13_1;    /*引脚13设置为输出模式*/
    GPIOA->MODER    |= GPIO_MODER_MODER14_1;    /*引脚13设置为输出模式*/


    GPIOC->MODER   |= GPIO_MODER_MODER13_0;    /*引脚13设置为输出模式*/
    GPIOC->OTYPER  &= ~GPIO_OTYPER_OT13;    /*引脚13设置为推挽模式*/
    GPIOC->OSPEEDR &= ~GPIO_OSPEEDR_OSPEED13;
    GPIOC->OSPEEDR |= GPIO_OSPEEDR_OSPEED13_0;    /*引脚13设置为中速模式*/
    GPIOC->PUPDR   |= GPIO_PUPDR_PUPD13_0;  /*引脚13设置为上拉模式*/

    return;
}

void usart_gpio_init(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;/*使能GPIOA*/

    GPIOA->MODER &= ~(GPIO_MODER_MODER9_Msk);
    GPIOA->MODER |= (GPIO_MODER_MODE9_1);
    GPIOA->AFR[1] &= ~(0xf << 4);
    GPIOA->AFR[1] |= (GPIO_AF_USART1 << 4);
    GPIOA->OTYPER &= ~(GPIO_OTYPER_OT9);
    GPIOA->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED9);
    GPIOA->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR9_0);
    GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPD9);
    GPIOA->PUPDR |= (GPIO_PUPDR_PUPD9_0);

    GPIOA->MODER &= ~(GPIO_MODER_MODER10_Msk);
    GPIOA->MODER |= (GPIO_MODER_MODE10_1);
    GPIOA->AFR[1] &= ~(0xf << 8);
    GPIOA->AFR[1] |= (GPIO_AF_USART1 << 8);
    GPIOA->OTYPER &= ~(GPIO_OTYPER_OT10);
    GPIOA->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED10);
    GPIOA->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR10_0);
    GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPD10);
    GPIOA->PUPDR |= (GPIO_PUPDR_PUPD10_0);
    return;
}
