// Copyright (c) 2015-19, Joe Krachey
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

#include "main.h"


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

void aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaacontextlog(const char * file, const int line, const char *msg)
{
    printf("%s:%d: %s\n", file, line, msg);
}



//*****************************************************************************
//*****************************************************************************


//GAME VARIABLES
	bool mainMenu = true;
	bool startGame = false;
	bool highScores = false;
	bool gameOver = false;
	int score = 0;
	uint8_t touch_event;
	uint16_t touchX, touchY;

int 
main(void)
{
	

	//STARTUP
	initialize_all_hardware();	
	lcd_clear_screen(LCD_COLOR_WHITE); //changed what the main menu would be
  lcd_draw_image(
                  120,                 // X Pos
                  mainMenuWidthPixels,   // Image Horizontal Width
                  160,                 // Y Pos
                  mainMenuHeightPixels,  // Image Vertical Height
                  mainMenuBitmaps,       // Image
                  LCD_COLOR_BLACK,      // Foreground Color
                  LCD_COLOR_WHITE    // Background Color
                );
//MAINMENU
while(mainMenu) {
		gp_timer_wait(TIMER0_BASE, 5000000);
		touch_event = ft6x06_read_td_status();
		if (touch_event > 0) {
		touchY = ft6x06_read_y();
		if (touchY > 90 & touchY < 170){
				mainMenu = false;
				startGame = true;
		}
		else if (touchY > 190)
		{
			mainMenu = false;
			highScores = true;
		}
	}
};

if (startGame) {
	startGameFunc();
	
		
//GAME LOGIC
		while(!gameOver){
			
			//TODO create a watchdog timer that will reload when each game is successful and will be connected to leds
			int gameType = (rand () % 2) + 1; // the 2 will eventually be changed to a 4 when all games enabled 
			printf(("%d"), gameType);
			//BOPIT
//			if(gameType == 1)
				bopItFunc();
//			//TWISTIT
//			else if (gameType == 2)
//					twistItFunc();
			
		};
}
//HIGH SCORES
else if (highScores){
	//need to implement the high scores
}

}



//EXTRA FUNCTIONS
int getMolePositionX (void)
{
	return ((rand () % 180) + 30); 
};

int getMolePositionY (void)
{
	return ((rand () % 230) + 30); 
};

void startGameFunc(void)
{
	lcd_clear_screen(LCD_COLOR_WHITE); //changed what the main menu wowuld be
  lcd_draw_image(
                  120,                 // X Pos
                  _3WidthPixels,   // Image Horizontal Width
                  160,                 // Y Pos
                  _3HeightPixels,  // Image Vertical Height
                  _3Bitmaps,       // Image
                  LCD_COLOR_BLACK,      // Foreground Color
                  LCD_COLOR_WHITE    // Background Color
                );
	
	//TODO wait 1 second, timer wait function doesnt work
	delay_ms(1000);
		
	lcd_draw_image(
                  120,                 // X Pos
                  _2WidthPixels,   // Image Horizontal Width
                  160,                 // Y Pos
                  _2HeightPixels,  // Image Vertical Height
                  _2Bitmaps,       // Image
                  LCD_COLOR_BLACK,      // Foreground Color
                  LCD_COLOR_WHITE    // Background Color
                );
								
	//TODO wait 1 second, timer wait function doesnt work
	delay_ms(1000);
		
	lcd_draw_image(
                  120,                 // X Pos
                  _1WidthPixels,   // Image Horizontal Width
                  160,                 // Y Pos
                  _1HeightPixels,  // Image Vertical Height
                  _1Bitmaps,       // Image
                  LCD_COLOR_BLACK,      // Foreground Color
                  LCD_COLOR_WHITE    // Background Color
                );
								
	//TODO wait 1 second, timer wait function doesnt work
	delay_ms(1000);
}


void bopItFunc (void)
{
	bool bopIt = true;
	int moleX = getMolePositionX();
	int moleY = getMolePositionY();
				
			lcd_draw_image(
                  120,                 // X Pos
                  bopItWidthPixels,   // Image Horizontal Width
                  160,                 // Y Pos
                  bopItHeightPixels,  // Image Vertical Height
                  bopItBitmaps,       // Image
                  LCD_COLOR_BLACK,      // Foreground Color
                  LCD_COLOR_WHITE    // Background Color
                );
			
			
			lcd_draw_image(
                  moleX,                 // X Pos
                  moleUpWidthPixels,   // Image Horizontal Width
                  moleY,                 // Y Pos
                  moleUpHeightPixels,  // Image Vertical Height
                  moleUpBitmaps,       // Image
                  LCD_COLOR_BLACK,      // Foreground Color
                  LCD_COLOR_WHITE    // Background Color
                );
								
			while (bopIt) //will be changing this while just for testing purposes
			{
				gp_timer_wait(TIMER0_BASE, 5000000);
				touch_event = ft6x06_read_td_status();
				if (touch_event > 0) {
				touchY = ft6x06_read_y();
				touchX = ft6x06_read_x();
					
				if ((touchX > (moleX - moleUpWidthPixels/2)  & touchX < (moleX + moleUpWidthPixels/2)) & 
					(touchY > (moleY - moleUpHeightPixels/2)  & touchY < (moleY + moleUpHeightPixels/2))){
						lcd_draw_image(
												moleX,                 // X Pos
												moleUpWidthPixels,   // Image Horizontal Width
												moleY,                 // Y Pos
												moleUpHeightPixels,  // Image Vertical Height
												moleUpBitmaps,       // Image
												LCD_COLOR_WHITE,      // Foreground Color
												LCD_COLOR_WHITE    // Background Color
											);
							lcd_draw_image(
												moleX,                 // X Pos
												moleDownWidthPixels,   // Image Horizontal Width
												moleY,                 // Y Pos
												moleDownHeightPixels,  // Image Vertical Height
												moleDownBitmaps,       // Image
												LCD_COLOR_BLACK,      // Foreground Color
												LCD_COLOR_WHITE    // Background Color
											);
						
						score++;
						//needs to wait 1 sec then move to next game
						delay_ms(1000);
						
						//needs to reload watchdog timer
						bopIt = false;
						
				}
			}
		};
			return;
}

void twistItFunc (void)
{
	
	lcd_draw_image(
                  120,                 // X Pos
                  twistItWidthPixels,   // Image Horizontal Width
                  160,                 // Y Pos
                  twistItHeightPixels,  // Image Vertical Height
                  twistItBitmaps,       // Image
                  LCD_COLOR_BLACK,      // Foreground Color
                  LCD_COLOR_WHITE    // Background Color
                );
	
	while (1) //will be changing this while just for testing purposes
			{
				int twistX = accel_read_x();	
				int twistY = accel_read_y();
					if (twistX > 12000 | twistY > 120000)
					{
							score++;
							//needs to wait 1 sec then move to next game
						delay_ms(1000);
							//needs to reload watchdog timer
							return;
					}
				};
}

void delay_ms(uint16_t count)
{
    int i,j;                                                                                
    for(i=0;i<count;i++)                                                                    
       {
       for(j=0;j<5000;j++);
       }                                                                                     
}


