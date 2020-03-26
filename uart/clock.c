/*
	Mpll = (2*m * Fin) / (p * 2s)
	m = MDIV+ 8, p = PDIV + 2
*/
#include "s3c24xx.h"

void init_clock()
{
	/*
	*MPLL:400MHZ
	*MDIV[19:12]:0X5C
	*PDIV[9:4]:1
	*SDIV[1:0]:1
	*/
	MPLLCON = (1<<0)|(1<<4)|(92<<12);

	CLKDIVN = 0x05;

	__asm__(
		"mrc p15,0,r0,c1,c0,0\n"
		"orr r0,r0,#0xc0000000\n"
		"mcr p15,0,r0,c1,c0,0\n"
	);
}
