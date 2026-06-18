#include"finalheader.h"

void LCD_LIGHT()
{
	LCD_COMMAND(0X01);
	LCD_COMMAND(0X80);
	LCD_STR("LIGHT 1 :");
	LCD_COMMAND(0XC0);
	LCD_STR("FAN   1 :");
	LCD_COMMAND(0X94);
	LCD_STR("LIGHT 2 :");
	LCD_COMMAND(0XD4);
	LCD_STR("FAN   2 :");
}

int main()
{
	unsigned char rxbyte;
	IODIR0|=LIGHT1|LIGHT2|FAN1|FAN2;	
	IOSET0=LIGHT1|LIGHT2|FAN1|FAN2;	
	LCD_INIT();
	LCD_STR("     THIRU");
	LCD_COMMAND(0XC0);
	LCD_STR("   V25CE5T2");
	delay_milliseconds(1000);
	LCD_COMMAND(0X01);
	delay_milliseconds(5);
	LCD_STR("   SMART HOME");
	LCD_COMMAND(0XC0);
	LCD_STR("   AUTOMATION") ;
	delay_milliseconds(1000);
	LCD_LIGHT();
	UART_CONFIG();	
	while(1)
	{
		rxbyte=UART_RX();

		if(rxbyte=='L')
		{
			IOCLR0=LIGHT1;
			LCD_COMMAND(0X8A);
	        LCD_STR("ON  ");
		}

		else if(rxbyte=='l')
		{
			IOSET0=LIGHT1;
			LCD_COMMAND(0X8A);
	        LCD_STR("OFF");
		}

		else if(rxbyte=='B')
		{
			IOCLR0=LIGHT2;
			LCD_COMMAND(0XCA);
	        LCD_STR("ON  ");
		}
		else if(rxbyte=='b')
		{
			IOSET0=LIGHT2;
			LCD_COMMAND(0XCA);
	        LCD_STR("OFF");
		}
		else if(rxbyte=='F')
		{
			IOCLR0=FAN1;
			LCD_COMMAND(0X9E);
	        LCD_STR("ON  ");
		}
		else if(rxbyte=='f')
		{
			IOSET0=FAN1;
			LCD_COMMAND(0X9E);
	        LCD_STR("OFF");
		}
		else if(rxbyte=='T')
		{
			IOCLR0=FAN2;
			LCD_COMMAND(0XDE);
	        LCD_STR("ON  ");
		}
		else if(rxbyte=='t')
		{
			IOSET0=FAN2;
			LCD_COMMAND(0XDE);
	        LCD_STR("OFF");
		}

		else
			IOSET0=LIGHT1|LIGHT2|FAN1|FAN2;				    
	}
}
