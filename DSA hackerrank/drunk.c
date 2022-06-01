#include<lpc21xx.h>
void delay(unsigned int x)
{
	unsigned int i;
	for(i=0;i<x;i++);
}
void seg1()
{
	PINSEL1=0x00000000;
	while(1)
	{
		IODIR0=0x10FF0000;//G
		IOSET0=0x10000000;
		IOSET0=0X00BD0000;
		delay(10000);
		IODIR0=0x20FF0000;//0
		IOSET0=0x20000000;
		IOSET0=0X003F0000;
	}
}

void seg2()
{
	PINSEL1=0x00000000;
	while(1)
	{
		IODIR0=0x10FF0000;//0
		IOSET0=0x10000000;
		IOSET0=0X003F0000;
		
		IODIR0=0x20FF0000;//F
		IOSET0=0x20000000;
		IOSET0=0X00710000;
	}
}
void serial()
{
	PINSEL0=0x00000005;
	U0LCR=0x83;
	U0DLL=0x61;
	U0LCR=0x03;
}

unsigned char UART1_RxChar(void)
{
    while(!(U1LSR & 0x01));
        return U1RBR;
}

int main()
{
	serial();
	while(1)
	{
		unsigned char receive;
        receive = UART1_RxChar();
			U1THR = receive;
		delay(500);
		if(receive<=30)
		{
			seg1();
			PINSEL1=0x00000000;
			IODIR0=0x000F0000;
			IOCLR0=0x000F0000;
			delay(500);
			IOSET0=0x000F0000;
			delay(500);
		}
		else
		{
			PINSEL0=0x00000000;
			seg2();
			IODIR0=0x00004000;
			IOSET0=0x00004000;
			delay(500);
			IOCLR0=0x00004000;
			delay(500);
		}
	}
}
