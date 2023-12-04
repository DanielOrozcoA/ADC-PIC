#INCLUDE <18f4550.h>
#DEVICE ADC = 10
#FUSES NOPROTECT, NOWDT, NOLVP, HSPLL, PLL5, CPUDIV2
#USE delay(clock = 48M)

#BYTE TRISA = 0xF92

#BYTE TRISB = 0xF93
#BYTE PORTB = 0xF81

#BYTE TRISD = 0xF95
#BYTE PORTD = 0xF83

#BYTE TRISC = 0xF94
#BIT BTN0 = 0xF82.7

#BYTE ADRESH = 0xFC4
#BYTE ADRESL = 0xFC3
#BYTE ADCON0 = 0xFC2
#BIT    GD = 0xFC2.1
#BYTE ADCON1 = 0xFC1
#BYTE ADCON2 = 0xFC0

void main(){
   //int16 val = 0;
   TRISA = 0b0001111;
   TRISB = 0b00000000;
   TRISC = 0b00000001;
   TRISD = 0b00000000;
   PORTB = 0;
   PORTD = 0;
   
   ADCON0 = 0b00000001;
   ADCON1 = 0b00111101;
   ADCON2 = 0b10000000;
   
   while(TRUE){
      
      while(BTN0){
         ADCON0 = 0b00000001;
         GD = 1;
         PORTB = ADRESL;
         PORTD = ADRESH;
      }
      
      while(!BTN0){
         ADCON0 = 0b00000101;
         GD = 1;
         PORTB = ADRESL;
         PORTD = ADRESH;
      }
      
      /*
         while(B0 == 1){
         for(n = 0; n < 5; n++){
            dat = read_adc();
            B0 = input(pin_B0);
            output_b(MACLK[n]);
            dat = (int)(100 - dat*0.069);
            delay_ms(dat);
            if(B0 == 0) break;
         }
      }
      
      while(B0 == 0){
         for(n = 0; n < 5; n++){
            dat = read_adc();
            B0 = input(pin_B0);
            output_b(MCLK[n]);
            dat = (int)(100 - dat*0.069);
            delay_ms(dat);
            if(B0 == 1) break;
         }
      }
      */
   }
}
