#include "include.h"

#include "reg.h"


void led_gpio_init(void)
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

void led1_gpio_init(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

    GPIOA->MODER   |= GPIO_MODER_MODER5_0;    /*引脚5设置为输出模式*/
    GPIOA->OTYPER  &= ~GPIO_OTYPER_OT5;    /*引脚5设置为推挽模式*/
    GPIOA->OSPEEDR &= ~GPIO_OSPEEDR_OSPEED5;
    GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEED5_0;    /*引脚5设置为中速模式*/
    GPIOA->PUPDR   |= GPIO_PUPDR_PUPD5_0;  /*引脚5设置为上拉模式*/

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

void gpio_init_24c256(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;

    GPIOB->MODER &= ~(GPIO_MODER_MODE6_Msk);
    GPIOB->MODER |= (GPIO_MODER_MODE6_0);
    GPIOB->OTYPER |= (GPIO_OTYPER_OT6);
    GPIOB->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED6_Msk);
    GPIOB->OSPEEDR |= (GPIO_OSPEEDR_OSPEED6_0);
    GPIOB->PUPDR &= ~(GPIO_PUPDR_PUPD6_Msk);

    GPIOB->MODER &= ~(GPIO_MODER_MODE7_Msk);
    GPIOB->MODER |= (GPIO_MODER_MODE7_0);
    GPIOB->OTYPER |= (GPIO_OTYPER_OT7);
    GPIOB->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED7_Msk);
    GPIOB->OSPEEDR |= (GPIO_OSPEEDR_OSPEED7_0);
    GPIOB->PUPDR &= ~(GPIO_PUPDR_PUPD7_Msk);

    return;
}

void key_gpio_init(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    GPIOA->MODER &= ~(GPIO_MODER_MODE0_Msk);
    GPIOA->OTYPER |= GPIO_OTYPER_OT0;
    GPIOA->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED0_Msk);
    GPIOA->OSPEEDR |= (GPIO_OSPEEDR_OSPEED0_0);
    GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPD0_Msk);
    GPIOA->PUPDR |= (GPIO_PUPDR_PUPD0_0);

    GPIOB->MODER &= ~(GPIO_MODER_MODE2_Msk);
    GPIOB->OTYPER |= GPIO_OTYPER_OT2;
    GPIOB->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED2_Msk);
    GPIOB->OSPEEDR |= (GPIO_OSPEEDR_OSPEED2_0);
    GPIOB->PUPDR &= ~(GPIO_PUPDR_PUPD2_Msk);
    GPIOB->PUPDR |= (GPIO_PUPDR_PUPD2_0);

    return;
}

void spi_gpio_init(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    SPI_SCK_GPIO_PORT->MODER &= ~(GPIO_MODER_MODE5_Msk);
    SPI_SCK_GPIO_PORT->MODER |= (GPIO_MODER_MODE5_1);
    SPI_SCK_GPIO_PORT->OTYPER &= ~(GPIO_OTYPER_OT5);
    SPI_SCK_GPIO_PORT->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED5_Msk);
    SPI_SCK_GPIO_PORT->OSPEEDR |= (GPIO_OSPEEDR_OSPEED5_Msk);
    SPI_SCK_GPIO_PORT->PUPDR |= (GPIO_PUPDR_PUPD5_0);
    SPI_SCK_GPIO_PORT->AFR[0] |= (SPI_SCK_AF5);

    SPI_MOSI_GPIO_PORT->MODER &= ~(GPIO_MODER_MODE7_Msk);
    SPI_MOSI_GPIO_PORT->MODER |= (GPIO_MODER_MODE7_1);
    SPI_MOSI_GPIO_PORT->OTYPER &= ~(GPIO_OTYPER_OT7);
    SPI_MOSI_GPIO_PORT->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED7_Msk);
    SPI_MOSI_GPIO_PORT->OSPEEDR |= (GPIO_OSPEEDR_OSPEED7_Msk);
    SPI_MOSI_GPIO_PORT->PUPDR |= (GPIO_PUPDR_PUPD7_0);
    SPI_MOSI_GPIO_PORT->AFR[0] |= (SPI_MOSI_AF5);


    SPI_MISO_GPIO_PORT->MODER &= ~(GPIO_MODER_MODE6_Msk);
    SPI_MISO_GPIO_PORT->MODER |= (GPIO_MODER_MODE6_1);
    SPI_MISO_GPIO_PORT->OTYPER &= ~(GPIO_OTYPER_OT6);
    SPI_MISO_GPIO_PORT->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED6_Msk);
    SPI_MISO_GPIO_PORT->OSPEEDR |= (GPIO_OSPEEDR_OSPEED6_Msk);
    //SPI_MISO_GPIO_PORT->PUPDR |= (GPIO_PUPDR_PUPD6_0);
    SPI_MISO_GPIO_PORT->AFR[0] |= (SPI_MISO_AF5);

    SPI_CS_GPIO_PORT->MODER &= ~(GPIO_MODER_MODE4_Msk);
    SPI_CS_GPIO_PORT->MODER |= (GPIO_MODER_MODE4_0);
    SPI_MISO_GPIO_PORT->PUPDR |= (GPIO_PUPDR_PUPD4_0);

    gpio_set(GPIOA, gpio_pin4);
    return;
}

void tim_pwm_gpio_init(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;

    TIM_PWM_CH1_GPIO_PORT->MODER &= ~(GPIO_MODER_MODE4_Msk);
    TIM_PWM_CH1_GPIO_PORT->MODER |= (GPIO_MODER_MODE4_1);
    TIM_PWM_CH1_GPIO_PORT->OTYPER &= ~(GPIO_OTYPER_OT4);
    TIM_PWM_CH1_GPIO_PORT->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED4_Msk);
    TIM_PWM_CH1_GPIO_PORT->OSPEEDR |= (GPIO_OSPEEDR_OSPEED4_Msk);
    TIM_PWM_CH1_GPIO_PORT->PUPDR |= (GPIO_PUPDR_PUPD4_0);
    TIM_PWM_CH1_GPIO_PORT->AFR[0] |= (TIM3_CH1_AF2);

    TIM_PWM_CH2_GPIO_PORT->MODER &= ~(GPIO_MODER_MODE5_Msk);
    TIM_PWM_CH2_GPIO_PORT->MODER |= (GPIO_MODER_MODE5_1);
    TIM_PWM_CH2_GPIO_PORT->OTYPER &= ~(GPIO_OTYPER_OT5);
    TIM_PWM_CH2_GPIO_PORT->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED5_Msk);
    TIM_PWM_CH2_GPIO_PORT->OSPEEDR |= (GPIO_OSPEEDR_OSPEED5_Msk);
    TIM_PWM_CH2_GPIO_PORT->PUPDR |= (GPIO_PUPDR_PUPD5_0);
    TIM_PWM_CH2_GPIO_PORT->AFR[0] |= (TIM3_CH2_AF2);

    TIM_PWM_CH3_GPIO_PORT->MODER &= ~(GPIO_MODER_MODE0_Msk);
    TIM_PWM_CH3_GPIO_PORT->MODER |= (GPIO_MODER_MODE0_1);
    TIM_PWM_CH3_GPIO_PORT->OTYPER &= ~(GPIO_OTYPER_OT0);
    TIM_PWM_CH3_GPIO_PORT->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED0_Msk);
    TIM_PWM_CH3_GPIO_PORT->OSPEEDR |= (GPIO_OSPEEDR_OSPEED0_Msk);
    TIM_PWM_CH3_GPIO_PORT->PUPDR |= (GPIO_PUPDR_PUPD0_0);
    TIM_PWM_CH3_GPIO_PORT->AFR[0] |= (TIM3_CH3_AF2);
    return;
}

void timer_gpio_set(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    GPIOA->MODER &= ~(GPIO_MODER_MODE0_Msk);
    GPIOA->MODER |= (GPIO_MODER_MODE0_1);




    return;
}

void timer_gpio_reset(void)
{

    return;
}


void gpio_mod_cfg(GPIO_TypeDef *port, gpio_pin_t pin, gpio_mode_t mod) {
    port->MODER &= ~get_moder_mask(pin);
    port->MODER |= set_moder_mask(pin, mod);
    return;
}



#if 0
void beep_gpio_init(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    GPIOA->MODER &= ~();
    return;
}
#endif

