//*****************************************************************************
// main.c
// Author: jkrachey@wisc.edu
//*****************************************************************************
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "TM4C123.h"
#include "driver_defines.h"
#include "validate.h"

/******************************************************************************
 * Includes
 *****************************************************************************/
// ADD CODE 02

/******************************************************************************
 * MACROS
 *****************************************************************************/
// ADD CODE 03


/******************************************************************************
 * Global Variables
 *****************************************************************************/
// ADD CODE 04




//*****************************************************************************
// External Functions
//*****************************************************************************
extern void WS2812B_write(uint32_t port_base_addr, uint8_t *led_array_base_addr, uint16_t num_leds);

//*****************************************************************************
//*****************************************************************************
void DisableInterrupts(void)
{
  __asm {
         CPSID  I
  }
}

//*****************************************************************************
//*****************************************************************************
void EnableInterrupts(void)
{
  __asm {
    CPSIE  I
  }
}


//*****************************************************************************
//*****************************************************************************
int 
main(void)
{
  int i;
  
	if( validate_ice(ICE_INTRO_TO_C) == false)
	{
		// Error in configuing the board, so enter infinite loop.
		DisableInterrupts();
		while(1){};
	}
  put_string("\n\r\n\r");
  put_string("**************************************\n\r");
  put_string("* ECE353: ICE-08-Intro-To-C\n\r");
  put_string("**************************************\n\r");

  // ADD CODE 05
 
  // ADD CODE 06
  
  // Infinite Loop
  while(1){
    
    // ADD CODE 07

    // ADD CODE 08

    // ADD CODE 08

    
  };
}
