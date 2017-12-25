//-------------------------------------------------------------------
// Filename: keypad_lcd.c
// Description: LLL
//-------------------------------------------------------------------
//-------------------------------------------------------------------
// INCLUDES
//-------------------------------------------------------------------
#include "hal_defs.h"
#include "hal_mcu.h"
#include "hal_board.h"
#include "hal_led.h"
#include "hal_lcd.h"
#include "hal_keypad.h"
#include "hal_buzzer.h"
#include "hal_uart.h"
#include "util.h"
#include "util_lcd.h"
#include "M270.h"
#include "hal_cc8051.h"
void main(void)
{
  halBoardInit();
  halLedSet(8);
  M270_Init();
  uint8 udi;
  uint8 key;
  uint8 udo;
    while(1)
    {
        while(1)
        {
          udi = M270_GetDI();
          halLcdWriteChar(HAL_LCD_LINE_2, 4,(udi&0x01)+'0');
          halLcdWriteChar(HAL_LCD_LINE_2, 7,((udi>>1)&0x01)+'0');
          halLcdWriteChar(HAL_LCD_LINE_2, 14,udo+'0');
          
          if((udi&0x01)==0x00)
          {
            udo=1;
            M270_SetDO(udo);
          }
          if((udi&0x02)==0x00)
          {
            udo=0;
            M270_SetDO(udo);
          }
          key=halKeypadPushed();
          halMcuWaitMs(100);
          if(key=='*')
          {
            break;
          }
        }
      HAL_RELAY_OFF();
    }
}
          

//-------------------------------------------------------------------
/*void main(void)
{
    uint8 no;
    uint8 buf[3];
    halBoardInit();						//�{���@�}�l����l�ƨ禡
    halLedSet(8);						//�Хܸ˸m�H�q�q

    
    utilPrintLogo("Keypad LCD Test");	//Print Logo and splash screen on LCD
    halBuzzer(300);					 	//Turn Buzzer on.  
    while(halKeypadPushed()==0);		//This function detects(�d��) if the keypad is being pushed.
    halLcdClear();						//Clear all lines on display

    no = 0;								//�ŧino�ܼ�
    while (TRUE)						//while�j�餺��True�~�����AFalse���X
    {
        uint8 key;						//0-255 integer with Unsigned
        key = halKeypadPushed();		
        if (key > 0)
        {
            if (key == '1')
            {
                halLedSet(1);
            }
            if (key == '2')
            {
               //���󦨥߫�A���檺�ʧ@
            }
            if (key == 'A')
            {
                halBuzzer(500);
            }
            if (key == 'U')
            {
               //���󦨥߫�A���檺�ʧ@
            }
            if (key == 'N')
            {
               //���󦨥߫�A���檺�ʧ@
            }
            if (key == '*')
            {
                break;
            }
           
            
            //LCD���
            if (no >= 16)
            {
                halLcdWriteChar(HAL_LCD_LINE_2, no - 16, key);	//Write single character
                halUartWrite(buf,1);							//Write a buffer(�ǰe��ƽw�İ�) to the UART.
            }
            else
            {
                halLcdWriteChar(HAL_LCD_LINE_1, no, key);
                halUartWrite(buf,1);
            }
            no++;
            if (no >= 32)
            {
                halBuzzer(300);
                halLcdClear();
                no = 0;             
            } 
        }
        halMcuWaitMs(300);      
    }
}*/

