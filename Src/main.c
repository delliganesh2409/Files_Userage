#include "MyStm32f407xx.h"

void igniton_on(void);
void igniton_off(void);
void delay(void)
{
	for (uint32_t i=0;i<5000000;i++);
}

int main(void)
{
	GPIO_Handle_t GpioLed, GpioLed1, GpioLed2, GpioLed3, GpioBtn;

	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed);

	GpioLed1.pGPIOx = GPIOD;
		GpioLed1.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
		GpioLed1.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
		GpioLed1.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
		GpioLed1.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
		GPIO_PeriClockControl(GPIOD, ENABLE);
		GPIO_Init(&GpioLed1);


		GpioLed2.pGPIOx = GPIOD;
		GpioLed2.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
		GpioLed2.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
		GpioLed2.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
		GpioLed2.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
		GPIO_PeriClockControl(GPIOD, ENABLE);
		GPIO_Init(&GpioLed2);


		GpioLed3.pGPIOx = GPIOD;
		GpioLed3.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;
		GpioLed3.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
		GpioLed3.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
		GpioLed3.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
		GPIO_PeriClockControl(GPIOD, ENABLE);
		GPIO_Init(&GpioLed3);


		GpioBtn.pGPIOx = GPIOA;
		GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
		GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
		GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
		GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
		GPIO_PeriClockControl(GPIOA, ENABLE);
		GPIO_Init(&GpioBtn);

		uint32_t flag = 0;
		uint32_t key_pressed = 0;

	while(1)
	{
		GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_0, DISABLE);
		if (GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == ENABLE)
		{
			GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
			GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
			GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_14);
			GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
		}
	}
}

					/*delay();
					flag++;
					if ((flag == 1) && (key_pressed == 0))
					{
						igniton_on();
						delay();
						key_pressed = flag;
						flag = 0;
					}
					else if ((flag==1) && (key_pressed == 1))
					{
						igniton_off();
						//key_pressed = flag;
						flag = 0;
					}
				}

	}

}

void igniton_on(void)
{
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_14);
}

void igniton_off(void)
{
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, 0);
}*/
