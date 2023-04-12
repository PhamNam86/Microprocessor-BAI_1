#include <16f887.h>
#device *=16 ADC=8 // Khai bao during con tro 16-bt 
#FUSES NOWDT, HS, NOPUT, NOBROWNOUT,NOPROTECT, NOLVP 
#use delay(clock = 8000000) // Khai bao su ðung Thach Anh 8 - Mhz
//#include<luutinh.h>
unsigned char x = 0;
const char led7[] = {0x3f,0x06, 0x5b, 0x4f,0x66,0x6d, 0x7d, 0x07,0x7f,0x6f};
                  //  0    1     2     3    4    5     6     7    8    9   
void Button2()
{
if(input(pin_d3)==0)
{
x=x+1;
delay_ms(300);
}
if(x==1)
{
output_b(~led7[1]);
delay_ms(300);
output_b(~led7[3]);
delay_ms(300);
output_b(~led7[5]);
delay_ms(300);
output_b(~led7[7]);
delay_ms(300);
output_b(~led7[9]);
delay_ms(300);
x=0;
}

} 
void Button1(){
if(input(pin_d4)==0){

output_high(pin_c5);

output_high(pin_c7); 
}
/*else{

output_low(pin_c5);

output_low(pin_c7);

}*/
}
void main()
{


set_tris_b(0x00);  // khai bao port b la output 
set_tris_c(0x00);  // khai bao port c la output 
set_tris_d(0xFF); 

output_b(0x00);
output_c(0x00);
while(TRUE){




if(input(pin_d4)==0)
{
Button1();
}

if(input(pin_d3)==0) 
{
Button2();
}


}
}






