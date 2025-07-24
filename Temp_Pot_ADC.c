#include<lpc214x.h>           
#include"PLL.h"
#include"Lcd_4bit.h" 
#include"ADC.h"




void main (void)
	
{ 
	  
  unsigned int ADC_result1;
	unsigned int ADC_result2;

	PLL_SET();
  LCD_Init();
	ADC_init();
	
	LCD_Command(0x80);
	LCD_string("ADC value1:");
	LCD_Command(0xc0);
	LCD_string("Temp:");
    while(1)                
    {
		   ADC_result1=ADC_read(0,2);
			 Delay(2);
			 ADC_result2=ADC_read(0,1);			
       ADC_result2=(((ADC_result2)*3.22)-500);
				ADC_result2=( (ADC_result2)/10);
		
			
			  LCD_Command(0x8C);
		    display(ADC_result1);	
        LCD_Command(0xCC);
		    display(ADC_result2);			

		}
}



