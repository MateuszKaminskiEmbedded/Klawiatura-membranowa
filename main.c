#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "DeviceConfig.h"
#include "klawiatura.h"
#include "delay.h"
#include "UART.h"

void main(){
	// Ustaw porty jako cyfrowe
    ANSELA = 0;
    ANSELB = 0;
    ANSELC = 0;
    ANSELE = 0;
    ANSELG = 0;
    
    // Set up PPS for UART 5
	U5RXR = 0b1100; // RF0 = U5RX
	RPE15R = 0b01011; // RC9 = U5TX
    
	Set_MaxSpeed_Mode();
    Keypad_Init();
    uchar_t button;
    
    // Initialise peripheral UART 5
	UART_Init();

	while (1){
        button = Keypad_ScanKey();
        if(button != 0){
        printf("%c\n\r", button);
        delay_ms(250);
        button = 0;
        }        
    }
}