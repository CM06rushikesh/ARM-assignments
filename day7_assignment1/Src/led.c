#include "led.h"
#include "stm32f4xx.h"


void LedInit (uint32_t pin) {
	// clock enable
	RCC->AHB1ENR |= BV (LED_GPIO_EN);
	// SET GPIO PIN OUTPUT
  BB_ALS(&LED_GPIO->MODER, (pin*2))=1;
  BB_ALS(&LED_GPIO->MODER, (pin*2+1))=0;
  // set pin speed to low
  BB_ALS (&LED_GPIO->OSPEEDR, (pin*2))=0;
  BB_ALS (&LED_GPIO->OSPEEDR,(pin*2+1))=0;
  // set gpio for nopull no pull down
  BB_ALS (&LED_GPIO->PUPDR, (pin*2))=0;
  BB_ALS (&LED_GPIO->PUPDR,(pin*2+1))=0;
	// set gpio pin for push pull
  BB_ALS(&LED_GPIO->OTYPER, pin) = 0;
}
  void LedOn(uint32_t pin) {
  	// set led pin (in ODR)
  	BB_ALS(&LED_GPIO->ODR, pin) = 1;
  }

  void LedOff(uint32_t pin) {
  	// clear led pin (in ODR)
  	BB_ALS(&LED_GPIO->ODR, pin) = 0;
  }

  void LedBlink(uint32_t pin, uint32_t delay) {
  	LedOn(pin);
  	DelayMs(delay);
  	LedOff(pin);


}
