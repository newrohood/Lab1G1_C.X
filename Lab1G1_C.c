#include <xc.h>
#define _XTAL_FREQ 1000000
#pragma config FOSC=INTOSCIO
#pragma config WDTEN=OFF
void Transmitir(unsigned char);
unsigned char Recibir(void);
void Transmitir2(char *);
void main(void){
  unsigned char BufferR; 
  TRISC6=1;
  TRISC7=1;
  TXSTA=0b00100100;
  RCSTA=0b10010000;
  SPBRG=25;
  BAUDCON=0b00001000;
  BufferR=RCREG;
  RCIF=0;
  while(1){
    /*BufferR=Recibir();
    Transmitir2("Usted presiono: ");
    Transmitir('\t');
    Transmitir(BufferR);
    Transmitir('\n');*/
    Transmitir('H');
    Transmitir('o');
    Transmitir('l');
    Transmitir('a');
    Transmitir(' ');
    Transmitir('m');
    Transmitir('u');
    Transmitir('n');
    Transmitir('d');
    Transmitir('o');
    Transmitir('\n');
    __delay_ms(1000);
  }  
}
void Transmitir(unsigned char BufferT){
  while(TRMT==0);
  TXREG=BufferT;  
}
unsigned char Recibir(void){
  while(RCIF==0);
  return RCREG;    
}    
void Transmitir2(char *BufferT){
  while(*BufferT!='\0'){
    Transmitir(*BufferT);
    BufferT++;
  }
}    
