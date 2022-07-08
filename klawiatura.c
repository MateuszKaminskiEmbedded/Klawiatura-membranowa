#include "klawiatura.h"

#define Keypad_Column1 LATAbits.LATA0
#define Keypad_Column2 LATAbits.LATA1
#define Keypad_Column3 LATAbits.LATA4
#define Keypad_Column4 LATAbits.LATA7

#define Keypad_Row1 PORTAbits.RA8
#define Keypad_Row2 PORTAbits.RA10
#define Keypad_Row3 PORTAbits.RA11
#define Keypad_Row4 PORTAbits.RA12

void Keypad_Init(void){
    // Config columns as output
    TRISAbits.TRISA0 = 0;
    TRISAbits.TRISA1 = 0;
    TRISAbits.TRISA4 = 0;
    TRISAbits.TRISA7 = 0;
    // Config rows as input
    TRISAbits.TRISA8 = 1;
    TRISAbits.TRISA10 = 1;
    TRISAbits.TRISA11 = 1;
    TRISAbits.TRISA12 = 1;
    // Pull-down resistors enable
    CNPDAbits.CNPDA8 = 1;
    CNPDAbits.CNPDA10 = 1;
    CNPDAbits.CNPDA11 = 1;
    CNPDAbits.CNPDA12 = 1;
}

uchar_t Keypad_ScanKey1(void){
    uchar_t key = 0;
    
    Keypad_Column1 = 1;
    Keypad_Column2 = 0;
    Keypad_Column3 = 0;
    Keypad_Column4 = 0;
    if(Keypad_Row1 == 1){
        key = '1';
    }else if(Keypad_Row2 == 1){
        key = '4';
    }else if(Keypad_Row3 == 1){
        key = '7';
    }else if(Keypad_Row4 == 1){
        key = '*';
    }
    return key;
}
uchar_t Keypad_ScanKey2(void){
    uchar_t key = 0;
    
    Keypad_Column1 = 0;
    Keypad_Column2 = 1;
    Keypad_Column3 = 0;
    Keypad_Column4 = 0;
    if(Keypad_Row1 == 1){
        key = '2';
    }else if(Keypad_Row2 == 1){
        key = '5';
    }else if(Keypad_Row3 == 1){
        key = '8';
    }else if(Keypad_Row4 == 1){
        key = '0';
    }
    return key;
}
uchar_t Keypad_ScanKey3(void){
    uchar_t key = 0;
    
    Keypad_Column1 = 0;
    Keypad_Column2 = 0;
    Keypad_Column3 = 1;
    Keypad_Column4 = 0;
    if(Keypad_Row1 == 1){
        key = '3';
    }else if(Keypad_Row2 == 1){
        key = '6';
    }else if(Keypad_Row3 == 1){
        key = '9';
    }else if(Keypad_Row4 == 1){
        key = '#';
    }
    return key;
}
uchar_t Keypad_ScanKey4(void){
    uchar_t key = 0;
    
    Keypad_Column1 = 0;
    Keypad_Column2 = 0;
    Keypad_Column3 = 0;
    Keypad_Column4 = 1;
    if(Keypad_Row1 == 1){
        key = 'A';
    }else if(Keypad_Row2 == 1){
        key = 'B';
    }else if(Keypad_Row3 == 1){
        key = 'C';
    }else if(Keypad_Row4 == 1){
        key = 'D';
    }
    return key;
}
uchar_t Keypad_ScanKey(void){
    uchar_t key;
    key = Keypad_ScanKey1() | Keypad_ScanKey2() | Keypad_ScanKey3() | Keypad_ScanKey4();
    return key;
}