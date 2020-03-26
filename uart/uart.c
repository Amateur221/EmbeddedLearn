#include "s3c24xx.h"
#define Buadrate 115200
#define Uartclock 50000000



void init_uart()
{
	/*�������� */
	GPHCON &= ~((3<<4)|(3<<6));
	GPHCON |= (2<<4)|(2<<6);
	
	GPHUP &= ~((1<<2) | (1<<3));

	/*���ò�����
	UBRDIVn = (int)( UART clock / ( buad rate x 16) ) �C1
	*/ 
	UBRDIV0 = 26;

	/*���ݸ�ʽ*/
	ULCON0 =0x03;

	UCON0 = 0x00000005;
}

int putchar(int c)
{
	while(!(UTRSTAT0 & (1<<2)));
	UTXH0 = (unsigned char)c;
}

int getchar(void)
{
	while(!(UTRSTAT0 & (1<<0)));
	return URXH0;
}

int puts(const char *s)
{
	while(*s)
	{
		putchar(*s);
		s++;
	}
}

