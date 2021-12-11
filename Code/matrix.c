#include <mega32.h>
#include <delay.h>

void main(void)
{
int a[16] = {0x00,0x00,0xFC,0x12,0x11,0x12,0xFC,0x00,0x00,0xFF,0x89,0x89,0x89,0x76,0x00,0x00};
int tmp = 0;
DDRA=0xFF;
DDRB=0xFF;
DDRC=0xFF;
while (1)
      {   
        for (tmp = 0; tmp < 8; tmp++)   
        {  
            PORTB = a[tmp + 8]; 
            PORTC = (0x01 << (tmp));    
            delay_us(100);
            PORTC = 0x00; 
        }       
        
        for (tmp = 0; tmp < 8; tmp++)   
        {
            PORTB = a[tmp];   
            PORTA = (0x01 << (tmp));    
            delay_us(100);
            PORTA = 0x00;
        }                   
      }
}