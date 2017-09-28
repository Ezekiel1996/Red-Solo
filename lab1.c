/* Lab 1 first file - ID Number: 815006342 */
#include <p18f452.h>
/* Set configuration bits for use with ICD2 */
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF
int x=0;
void main (void)
{
    INTCONbits.GIEH = 1; //globally enables interrupts that have the priority bit set
    INTCONbits.GIEL = 1; //globally enables interrupts that have the priority bit cleared
    TRISAbits.RA3 = 0; //Configure pin RA3 as an output
    PORTAbits.RA3 =0; 
    TRISB=0; //Configure PORTB as outputs     
    for(x=1; x<=15;x++)
    {
        PORTB=x;
    }
}

