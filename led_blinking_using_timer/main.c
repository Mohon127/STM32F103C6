#define RCC_BASE 0x40021000 
#define GPIOC_BASE 0x40011000
#define TIM2_BASE 0x40000000

#define RCC_APB2ENR *(volatile unsigned int *) (RCC_BASE + 0x18)
#define RCC_APB1ENR *(volatile unsigned int *) (RCC_BASE + 0x1C)	

#define GPIOC_CRH *(volatile unsigned int *) (GPIOC_BASE + 0x04)
#define  GPIOC_BSRR *(volatile unsigned int *) (GPIOC_BASE +  0x10)
#define  GPIOC_ODR *(volatile unsigned int *) (GPIOC_BASE +  0x0C)
	
#define  TIM2_CR1 *(volatile unsigned int *) (TIM2_BASE + 0x0)
#define TIM2_PSC *(volatile unsigned int *) (TIM2_BASE + 0x28)
#define  TIM2_ARR *(volatile unsigned int *) (TIM2_BASE + 0x2C)
#define TIM2_SR *(volatile unsigned int *) (TIM2_BASE +  0x10)


int main() {
		RCC_APB2ENR |= (1U << 4);
		
	
		GPIOC_CRH &= ~(0xF << 20);
		GPIOC_CRH &= ~(0x1 << 20);
		GPIOC_CRH |= (0x1 << 21);
		GPIOC_CRH &= ~(0x1 << 22);
		GPIOC_CRH &= ~(0x1 << 23);
	
		RCC_APB1ENR |= (1U << 0);
		
		TIM2_CR1 |= (1U << 0);
		TIM2_PSC = 7999;
		TIM2_ARR = 999;
	
	
		while (1) {			
			
			// Using clock control delay:			
			if (TIM2_SR & (1U << 0)) {
				TIM2_SR &= ~(1U << 0);
				GPIOC_ODR ^= (1U << 13);
								
			}
			
			
		}
}