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
#define LED0 P1_0
#define LED1 P1_1
#define LED2 P1_2
#define LED3 P1_3
#define LED4 P1_4
#define LED5 P1_5
#define LED6 P1_6
#define LED7 P1_7
void main(void)
{
  P1SEL &= ~0xFF;	//將P0_6、P0_7設置為通用I/O         
  P1DIR |= 0xFF;    //將P0_6、P0_7設置為輸出
  while(1)
  {   
      LED0 = 1;
      halMcuWaitMs(250);
      LED1 = 1;
      halMcuWaitMs(250);
      LED2 = 1;
      halMcuWaitMs(250);
      LED3 = 1;
      halMcuWaitMs(250);
      LED4 = 1;
      halMcuWaitMs(250);
      LED5 = 1;
      halMcuWaitMs(250);
      LED6 = 1;
      halMcuWaitMs(250);
      LED7 = 1;
      halMcuWaitMs(250);
      LED0 = 0;
      halMcuWaitMs(250);
      LED1 = 0;
      halMcuWaitMs(250);
      LED2 = 0;
      halMcuWaitMs(250);
      LED3 = 0;
      halMcuWaitMs(250);
      LED4 = 0;
      halMcuWaitMs(250);
      LED5 = 0;
      halMcuWaitMs(250);
      LED6 = 0;
      halMcuWaitMs(250);
      LED7 = 0;
      halMcuWaitMs(250);
  }
}
          

