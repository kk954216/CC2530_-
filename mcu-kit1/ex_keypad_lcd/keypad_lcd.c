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
#include "hal_cc8051.h"
#include <ioCC2530.h>
uint8 key;
#define Relay P0_7
void main(void)
{
  halBoardInit();
  halLedSet(8);
  Relay = 0;
  P0SEL &= ~0xC0;	//將P0_6、P0_7設置為通用I/O         
  P0DIR |= 0xC0;    //將P0_6、P0_7設置為輸出
    while(1)
    {
      key = halKeypadPushed();
      
      if(key=='*')
      {
        Relay = 0;
        //MCU_IO_SET_LOW(0,5);
        halLcdWriteChar(HAL_LCD_LINE_2, 1,key);
      }
      if(key=='#')
      {
        Relay = 1;
        //MCU_IO_SET_HIGH(0,5);
        halLcdWriteChar(HAL_LCD_LINE_2, 1,key);
      }
      halMcuWaitMs(250);
    }
}
          

