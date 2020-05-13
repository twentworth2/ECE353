// Copyright (c) 2015-16, Joe Krachey
// All rights reserved.
//
// Redistribution and use in source or binary form, with or without modification, 
// are permitted provided that the following conditions are met:
//
// 1. Redistributions in source form must reproduce the above copyright 
//    notice, this list of conditions and the following disclaimer in 
//    the documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; 
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
// EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "TM4C123.h"
#include "eeprom.h"
#include "lcd.h"
#include "lcd_images.h"
#include "timers.h"
#include "ps2.h"
#include "launchpad_io.h"
#include "ft6x06.h"
#include "accel.h"
#include "serial_debug.h"
#include "project_interrupts.h"
#include "project_hardware_init.h"
#include "spi_select.h"
#include "spi.h"
#include "uart.h"
#include "io_expander.h"
#include "gpio_port.h"

//#include "fonts/fonts.h"
//#include "image_src/stickman_image.h"

//graphics
#include "BopIt.h"
#include "BumpIt.h"
#include "PushIt.h"
#include "TwistIt.h"
#include "GameOver.h"
#include "MainMenu.h"
#include "2.h"
#include "1.h"
#include "3.h"
#include "MoleDown.h"
#include "MoleUp.h"
//end graphics

//functions
int getMolePositionX (void);
int getMolePositionY (void);
void bopItFunc (void);
void startGameFunc(void);
void twistItFunc (void);
void delay_ms(uint16_t count);




// https://stackoverflow.com/questions/23916351/automatically-inserting-filename-line-number-in-logging-statements-of-a-c-prog
// logging function
void aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaacontextlog(const char * file, const int line, const char *msg);
// logging macro - passes __FILE__ and __LINE__ to logging function
#define CONTEXTLOG(msg) do { aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaacontextlog(__FILE__, __LINE__, msg); } while (0)


#endif
