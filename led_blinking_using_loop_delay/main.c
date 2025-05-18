#define RCC_BASE 0x40021000 
#define GPIOC_BASE 0x40011000

#define RCC_APB2ENR *(volatile unsigned int *) (RCC_BASE + 0x18)	

#define GPIOC_CRH *(volatile unsigned int *) (GPIOC_BASE + 0x04)
#define  GPIOC_BSRR *(volatile unsigned int *) (GPIOC_BASE +  0x10)
#define  GPIOC_ODR *(volatile unsigned int *) (GPIOC_BASE +  0x0C)
	

	
#define DELAY 1000000


int main() {
		RCC_APB2ENR |= (1U << 4);
		
	
		GPIOC_CRH &= ~(0xF << 20);
		GPIOC_CRH &= ~(0x1 << 20);
		GPIOC_CRH |= ~(0x1 << 21);
		GPIOC_CRH &= ~(0x1 << 22);
		GPIOC_CRH &= ~(0x1 << 23);
	
		
		
		while (1) {			
			
			GPIOC_ODR ^= (1U << 13);
			for (int i=0; i < DELAY; i++);		
		}
		
	}