#include "s3c24xx.h"
#include "clock.h"
#include "uart.h"


int main()
{
	init_clock();
	init_uart();
	puts("HELLO\n");
	unsigned char c;
	
	while(1)
		{
			c=getchar();
			putchar(c);
		}
	return 0;
}
