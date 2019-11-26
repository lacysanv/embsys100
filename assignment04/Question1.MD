##1. Using bit-band region for peripherals:
a. Convert the Blinking Led demo to use the corresponding bit-band address instead of the register address used in the peripheral region.
	    RCC_AHB1ENR |= 0x1;	
	   0x800'0042: 0x4813         LDR.N     R0, [PC, #0x4c]         ; RCC_AHB1ENR	
	   0x800'0044: 0x6801         LDR       R1, [R0]	
	   0x800'0046: 0xf051 0x0101  ORRS.W    R1, R1, #1	
	   0x800'004a: 0x6001         STR       R1, [R0]	


	    *((unsigned int*)((0x42000000) + (0x23830 * 32) + (0 * 4))) = 0x1;	
	   0x800'0042: 0x2001         MOVS      R0, #1	
	   0x800'0044: 0x4911         LDR.N     R1, [PC, #0x44]         ; 0x4247'0600	
	   0x800'0046: 0x6008         STR       R0, [R1]

b. What instructions does the compiler produce in assembly for the “writing” to the GPIO bit when using bit-band address?

	    *((unsigned int*)((0x42000000) + (0x23830 * 32) + (0 * 4))) = 0x1;	
	   0x800'0042: 0x2001         MOVS      R0, #1	
	   0x800'0044: 0x4911         LDR.N     R1, [PC, #0x44]         ; 0x4247'0600	
	   0x800'0046: 0x6008         STR       R0, [R1]

c. What were the instructions produced when writing to the GPIOx_ODR bit[5] without using bit-banding?

	    GPIOA_ODR |= GPIOA;	
	   0x800'006a: 0x490c         LDR.N     R1, [PC, #0x30]         ; GPIOA_ODR	
	   0x800'006c: 0x680a         LDR       R2, [R1]	
	   0x800'006e: 0xf052 0x0220  ORRS.W    R2, R2, #32             ; 0x20	
	   0x800'0072: 0x600a         STR       R2, [R1]