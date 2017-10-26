#include <p18f452.h>
#include <delays.h>
#include "xlcd.h"
#include <string.h>
#include <stdio.h>

#pragma config WDT = OFF //Disable watchdog timer
#pragma config LVP = OFF //Disable low voltage programming

#define _XTAL_FREQ 4000000UL

unsigned int MapIndex = 0;
extern void MapNamee(void);     
extern char getMapChar(void);
extern char MapName;
char grpName[7];


void DelayFor18TCY(void){
     Nop(); Nop(); Nop(); Nop(); 
     Nop(); Nop(); Nop(); Nop(); 
     Nop(); Nop(); Nop(); Nop(); 
     Nop(); Nop();
     return;
}

void DelayXLCD(void){
    Delay1KTCYx(5);	
    return;
}

void DelayPORXLCD(void){
    Delay1KTCYx(15);
    return;
}
 
void main(void){
    
    MapNamee();
    
    for(MapIndex=0;MapIndex<=6;MapIndex++){
        grpName[MapIndex] = getMapChar();
    }
    
    PORTD = 0X00;
    TRISD = 0x00;
    OpenXLCD(FOUR_BIT & LINES_5X7);
    while( BusyXLCD() );
    SetDDRamAddr(0x00);
    WriteCmdXLCD( SHIFT_DISP_LEFT );
    while( BusyXLCD() );
    WriteCmdXLCD( BLINK_ON );
    
    while(1){
        
        while( BusyXLCD() );
        SetDDRamAddr(0x00);
        while( BusyXLCD() );
        putsXLCD(grpName);
        while( BusyXLCD() );
        Delay1KTCYx(110);//give LCD time to refresh
    }
}
 