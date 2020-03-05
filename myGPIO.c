/*
 * GPIO.c
 *
 *  Created on: 3/5/2020
 *  Author: Mithil Adsul
 */

// For the code you place here, you may use your code that uses register references.
// However, I encourage you to start using the Driver Library as soon as possible.

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myGPIO.h"

// TODO: Create a function to initialize the GPIO.
// Even though this assignment does not use all of the pushbuttons, you should write one function that does a complete GPIO init.
void initGPIO()
{
    // Launchpad S1
    P1DIR &= ~BIT1;     //Set Bit 1 = 0.
    P1REN |= BIT1;      //Enable the pull resistor.
    P1OUT |= BIT1;      //Configure the pull resistor as a pull-up resistor.


    // Launchpad S2
    P1DIR &= ~BIT4;     //Set Bit 4 = 0.
    P1REN |= BIT4;      //Enable the pull resistor.
    P1OUT |= BIT4;      //Configure the pull resistor as a pull-up resistor.


    // Boosterpack S1
    P5DIR &= ~BIT1;     //Set Bit 1 = 0.
    P5REN |=  BIT1;     //Enable the pull resistor.
    P5OUT |=  BIT1;     //Configure the pull resistor as a pull-up resistor.


    // Boosterpack S2
    P3DIR &= ~BIT5;     //Set Bit 5 = 0.
    P3REN |=  BIT5;     //Enable the pull resistor.
    P3OUT |=  BIT5;     //Configure the pull resistor as a pull-up resistor.


    // Launchpad LED1
    P1DIR |= BIT0;      //Set Bit 0 = 0;


    // Launchpad LED2 Red
    P2DIR |= BIT0;      //Set Bit 0 = 0;


    // Launchpad LED2 Green
    P2DIR |= BIT1;      //Set Bit 1 = 0;


    // Launchpad LED2 Blue
    P2DIR |= BIT2;      //Set Bit 2 = 0;


    // Boosterpack LED Red
    P2DIR |= BIT6;      //Set Bit 6 = 0;


    // Boosterpack LED Green
    P2DIR |= BIT4;      //Set Bit 4 = 0;


    // Boosterpack LED Blue
    P5DIR |= BIT6;      //Set Bit6 = 0;


    // Turn off all LEDs at the start.

    P1DIR &= ~BIT0;     //Turn off Launchpad LED1.

    P2DIR &= ~BIT0;     //Turn off Launchpad LED2 RED.

    P2DIR &= ~BIT1;     //Turn off Launchpad LED2 GREEN.

    P2DIR &= ~BIT2;     //Turn off Launchpad LED2 BLUE.

    P2DIR &= ~BIT6;     //Turn off Boosterpack LED Red.

    P2DIR &= ~BIT4;     //Turn off Boosterpack LED Green.

    P5DIR &= ~BIT6;     //Turn off Boosterpack LED Blue.
}

// TODO: Create a function to return the status of Launchpad Pushbutton S1
unsigned char checkStatus_LaunchpadS1()
{
    return P1IN & BIT1;     //Returns the status of Launchpad Pushbutton S1
}



// TODO: Create a function to return the status of Launchpad Pushbutton S2
unsigned char checkStatus_LaunchpadS2()
{
    return P1IN & BIT4;     //Returns the status of Launchpad Pushbutton S2
}



// TODO: Create a function to return the status of Boosterpack Pushbutton S1
unsigned char checkStatus_BoosterpackS1()
{
    return P5IN & BIT1;     //Returns the status of Boosterpack Pushbutton S1
}



// TODO: Create a function to return the status of Boosterpack Pushbutton S2
unsigned char checkStatus_BoosterpackS2()
{
    return P3IN & BIT5;     //Returns the status of Boosterpack Pushbutton S2
}



// TODO: Create a function to turn on Launchpad LED1.
void turnOn_LaunchpadLED1()
{
    P1DIR |= BIT0;          //Turns on Launchpad LED1
}



// TODO: Create a function to turn off Launchpad LED1.
void turnOff_LaunchpadLED1()
{
    P1DIR &= ~BIT0;          //Turns off Launchpad LED1
}



// TODO: Create a function to turn on the Red Launchpad LED2.
void turnOn_LaunchpadLED2Red()
{
    P2DIR |= BIT0;          //Turns on Red Launchpad LED2
}



// TODO: Create a function to turn off the Red Launchpad LED2.
void turnOff_LaunchpadLED2Red()
{
    P2DIR &= ~BIT0;         //Turns off Red Launchpad LED2
}



// TODO: Create a function to turn on the Green Launchpad LED2.
void turnOn_LaunchpadLED2Green()
{
    P2DIR |= BIT1;          //Turns on Green Launchpad LED2
}



// TODO: Create a function to turn off the Green Launchpad LED2.
void turnOff_LaunchpadLED2Green()
{
    P2DIR &= ~BIT1;         //Turns off Green Launchpad LED2
}



// TODO: Create a function to turn on the Blue Launchpad LED2.
void turnOn_LaunchpadLED2Blue()
{
    P2DIR |= BIT2;          //Turns on Blue Launchpad LED2
}



// TODO: Create a function to turn off the Blue Launchpad LED2.
void turnOff_LaunchpadLED2Blue()
{
    P2DIR &= ~BIT2;         //Turns off Blue Launchpad LED2.
}



// TODO: Create a function to turn on the Red Boosterpack LED2.
void turnOn_BoosterpackLEDRed()
{
    P2DIR |= BIT6;          //Turns on Red Boosterpack LED2
}



// TODO: Create a function to turn off the Red Boosterpack LED2.
void turnOff_BoosterpackLEDRed()
{
    P2DIR &= ~BIT6;          //Turns off Red Boosterpack LED2
}



// TODO: Create a function to turn on the Green Boosterpack LED2.
void turnOn_BoosterpackLEDGreen()
{
    P2DIR |= BIT4;         //Turns on the Green Boosterpack LED2.
}



// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDGreen()
{
    P2DIR &= ~BIT4;         //Turns off the Green Boosterpack LED2.
}



// TODO: Create a function to turn on the Blue Boosterpack LED2.
void turnOn_BoosterpackLEDBlue()
{
    P5DIR |= BIT6;          //Turns on the Blue Boosterpack LED2.
}



// TODO: Create a function to turn off the Blue Boosterpack LED2.
void turnOff_BoosterpackLEDBlue()
{
    P5DIR &= ~BIT6;         //Turns off the blue boosterpack LED2.
}
