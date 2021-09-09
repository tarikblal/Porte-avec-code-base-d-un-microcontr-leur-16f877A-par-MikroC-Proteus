int i,l,j,k=1;
char password[4];
char keypadPort at PORTb;
sbit LCD_RS at RD2_bit;
sbit LCD_EN at RD3_bit;
sbit LCD_D4 at RD4_bit;
sbit LCD_D5 at RD5_bit;
sbit LCD_D6 at RD6_bit;
sbit LCD_D7 at RD7_bit;

// Pin direction
sbit LCD_RS_Direction at TRISD2_bit;
sbit LCD_EN_Direction at TRISD3_bit;
sbit LCD_D4_Direction at TRISD4_bit;
sbit LCD_D5_Direction at TRISD5_bit;
sbit LCD_D6_Direction at TRISD6_bit;
sbit LCD_D7_Direction at TRISD7_bit;
void get_password()
{Loop:        trisa=0; porta=0;
  Lcd_Init();
Lcd_Cmd(_Lcd_Clear);
LCD_OUT(1, 1, "Enter Password:");
for(i=0;i<3;i++)
{while(password[i]==0)
{ password[i]= Keypad_Key_Click();}
if (password[i]==1) password[i]='7';
if (password[i]==2) password[i]='8';
if (password[i]==3) password[i]='9';
if (password[i]==5) password[i]='4';
if (password[i]==6) password[i]='5';
if (password[i]==7) password[i]='6';
if (password[i]==9) password[i]='1';
if (password[i]==10) password[i]='2';
if (password[i]==11) password[i]='3';
LCD_Chr(2,i+1,'*');
}
if(strcmp(password,"123")==0)
{
porta.b0 = 1;
}
else {
for(j=0;j<3;j++){
password[j]='\0';}
Lcd_Cmd(_Lcd_Clear);
porta.b1 = 1;

delay_ms(500);k++;
if(k==3)
{Lcd_Cmd(_Lcd_Clear);
while(1)
{LCD_OUT(1, 1,"Error lock");
}
}
goto Loop;}
}



void main() {

trisa=0; porta=0;
trisc= 0; portc= 0;
Lcd_Init();keypad_init();
Lcd_Cmd(_LCD_CURSOR_OFF);
get_password();
lcd_Cmd(_lcd_Clear);
lcd_Out(1,1," welcome");
porta.b0 = 1;
PORTC=0b10000001;
delay_ms(500);
PORTC=0b01000010;
delay_ms(500);
PORTC=0b00100100;
 delay_ms(500);
PORTC=0b00011000;

  
delay_ms(5000);

PORTC=0b00011000;
delay_ms(500);
PORTC=0b00100100;
delay_ms(500);
PORTC=0b01000010;
delay_ms(500);
PORTC=0b10000001;
 delay_ms(500);

/*while (1){????
portc.b0 = 1;
delay_ms(500);
portc.b0 = 0;
delay_ms(500);
}????  */


}