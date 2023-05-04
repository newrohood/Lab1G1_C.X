//Primera sección
#include <xc.h>
#define _XTAL_FREQ 1000000
//Segunda sección
#pragma config FOSC=INTOSC_EC
#pragma config WDT=OFF
//Tercera sección
char a=10;
int b;
long c;
float d;    //double e;
char f[3];
int g[2][3];
long *h;
//Cuarta sección
void main(void){ //RD2 rojo  RD1 amarillo  RD0 verde
  TRISD=0;  //clrf TRISD
  //TRISD0=0;   //bcf TRISD,0
  while(1){
    LATD=0b00000001;
    while(RC0==1);
    __delay_ms(3000);
    LATD=0b00000010;
    __delay_ms(3000);
    LATD=0b00000100;
    __delay_ms(10000);
    LATD=0b00000110;
    __delay_ms(3000);
  }  
}