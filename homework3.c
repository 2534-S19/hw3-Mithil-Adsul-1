#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "homework3.h"
#include "myGPIO.h"
#include "myTimer.h"

int main(void)
{
    // Count variables to control the LEDs.
    unsigned int count0 = 0;
    unsigned int count1 = 0;

    // TODO: Declare the variables that main uses to interact with your state machine.
    unsigned int history = 0;

    // Stops the Watchdog timer.
    initBoard();
    // Initialize the GPIO.
    // YOU MUST WRITE THIS FUNCTION IN myGPIO.c
    initGPIO();
    // Initialize Timer0 to provide a one second count interval for updating LED2.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_0_BASE, TIMER0_PRESCALER, TIMER0_COUNT);
    // Initialize Timer1 to provide a one millisecond count interval for updating the button history.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_1_BASE, TIMER1_PRESCALER, TIMER1_COUNT);

    while(1)
    {
        // Update the color of LED2 using count0 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeLaunchpadLED2(count0);
        // Update the color of the Boosterpack LED using count1 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeBoosterpackLED(count1);

        // TODO: If Timer0 has expired, increment count0.
        // YOU MUST WRITE timer0expired IN myTimer.c
        if(timer0Expired())
        {
            count0 ++;
        }


        // TODO: If Timer1 has expired, update the button history from the pushbutton value.
        if(timer1Expired())
        {
            history++;
        }
        // YOU MUST WRITE timer1expired IN myTimer.c


        // TODO: Call the button state machine function to check for a completed, debounced button press.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        fsmBoosterpackButtonS1(history);



        // TODO: If a completed, debounced button press has occurred, increment count1.
        if (fsmBoosterpackButtonS1(history))
        {
            count1++;
        }



    }
}

void initBoard()
{
    WDT_A_hold(WDT_A_BASE);
}

// TODO: Map the value of a count variable to a color for LED2.
// Since count is an unsigned integer, you can mask the value in some way.
void changeLaunchpadLED2(unsigned int count)
{
    if (count == 0)     //Create Red
    {
        P2DIR |= BIT0;  //Turn on Launchpad LED2 Red

        //Turn off the other Launchpad LEDs.
        P2DIR &= ~BIT1;     //Turn off Launchpad LED2 GREEN.
        P2DIR &= ~BIT2;     //Turn off Launchpad LED2 BLUE.
    }

    else if (count == 1) //Create Green
    {
        P2DIR |= BIT1;  //Turn on Launchpad LED2 Green

        //Turn off the other Launchpad LEDs.
        P2DIR &= ~BIT0;     //Turn off Launchpad LED2 RED.
        P2DIR &= ~BIT2;     //Turn off Launchpad LED2 BLUE.

    }

    else if (count == 2) //Create Yellow
    {
        P2DIR |= BIT0;  //Turn on Launchpad LED2 RED
        P2DIR |= BIT1;  //Turn on Launchpad LED2 GREEN


        //Turn off the remaining Launchpad LED2.
        P2DIR &= ~BIT2;     //Turn off Launchpad LED2 BLUE
    }

    else if (count == 3) //Create Blue
    {
        P2DIR |= BIT2;  //Turn on Launchpad LED2 BLUE

        //Turn off the remaining Launchpad LEDs.
        P2DIR &= ~BIT0;     //Turn off Launchpad LED2 RED.
        P2DIR &= ~BIT1;     //Turn off Launchpad LED2 GREEN.
    }

    else if (count == 4) //Create Purple
    {
        P2DIR |= BIT2;  //Turn on Launchpad LED2 BLUE
        P2DIR |= BIT0;  //Turn on Launchpad LED2 RED

        //Turn off the remaining Launchpad LED
        P2DIR &= ~BIT1;     //Turn off Launchpad LED2 GREEN

    }

    else if (count == 5) //Create Cyan
    {
        P2DIR |= BIT2;  //Turn on Launchpad LED2 BLUE
        P2DIR |= BIT1;  //Turn on Launchpad LED2 GREEN

        //Turn off the remaining launchpad LED
        P2DIR &= ~BIT0;     //Turn off Launchpad LED2 RED

    }

    else if (count == 6)    //Create White
    {
        //Turn on all the Launchpad LEDs
        P2DIR |= BIT2;  //Turn on Launchpad LED2 BLUE
        P2DIR |= BIT1;  //Turn on Launchpad LED2 GREEN
        P2DIR |= BIT0;  //Turn on Launchpad LED2 RED

    }

    else if (count == 7)    //Turn off all LEDS.
    {
        P2DIR &= ~BIT0;     //Turn off Launchpad LED2 RED.
        P2DIR &= ~BIT1;     //Turn off Launchpad LED2 GREEN.
        P2DIR &= ~BIT2;     //Turn off Launchpad LED2 BLUE.
    }
}

// TODO: Map the value of a count variable to a color for the Boosterpack LED
// This is essentially a copy of the previous function, using a different LED
void changeBoosterpackLED(unsigned int count)
{
    if (count == 0) //Create Red
    {
        P2DIR |= BIT6;     //Turn on Boosterpack LED Red.

        //Turn off the remaining Boosterpack LEDs
        P2DIR &= ~BIT4;     //Turn off Boosterpack LED Green.
        P5DIR &= ~BIT6;     //Turn off Boosterpack LED Blue.

    }

    else if (count == 1) //Create Green
    {
        P2DIR |= BIT4;     //Turn on Boosterpack LED Green.

        //Turn off the remaining Boosterpack LEDs
        P2DIR &= ~BIT6;    //Turn off Boosterpack LED Red.
        P5DIR &= ~BIT6;    //Turn off Boosterpack LED Blue.
    }

    else if (count == 2) //Create Yellow
    {
        P2DIR |= BIT6;     //Turn on Boosterpack LED Red.
        P2DIR |= BIT4;     //Turn on Boosterpack LED Green.

        //Turn off the remaining Boosterpack LED
        P5DIR &= ~BIT6;    //Turn off Boosterpack LED Blue.
    }

    else if (count == 3) //Create Blue
    {
        P5DIR |= BIT6;    //Turn on Boosterpack LED Blue.

        //Turn off the remaining Boosterpack LEDs
        P2DIR &= ~BIT6;     //Turn off Boosterpack LED Red.
        P2DIR &= ~BIT4;     //Turn off Boosterpack LED Green.
    }

    else if (count == 4) //Create Purple
    {
        P5DIR |= BIT6;    //Turn on Boosterpack LED Blue.
        P2DIR |= BIT6;    //Turn on Boosterpack LED Red.

        //Turn off the remaining Boosterpack LED
        P2DIR &= ~BIT4;     //Turn off Boosterpack LED Green.
    }

    else if (count == 5) //Create Cyan
    {
        P5DIR |= BIT6;    //Turn on Boosterpack LED Blue.
        P2DIR |= BIT4;    //Turn on Boosterpack LED Green.

        //Turn off the remaining Boosterpack LED
        P2DIR &= ~BIT6;     //Turn off Boosterpack LED Red.
    }

    else if (count == 6) //Create White
    {
        //Turn on all Boosterpack LEDs
        P2DIR |= BIT6;     //Turn on Boosterpack LED Red.
        P5DIR |= BIT6;    //Turn on Boosterpack LED Blue.
        P2DIR |= BIT4;    //Turn on Boosterpack LED Green.
    }

    else if (count == 7) //Turn of all Boosterpack LEDs
    {
        P2DIR &= ~BIT6;     //Turn off Boosterpack LED Red.
        P2DIR &= ~BIT4;     //Turn off Boosterpack LED Green.
        P5DIR &= ~BIT6;     //Turn off Boosterpack LED Blue.
    }
}

// TODO: Create a button state machine.
// The button state machine should return true or false to indicate a completed, debounced button press.
bool fsmBoosterpackButtonS1(unsigned int buttonhistory)
{
    bool pressed = false;
//if down, then chsnge to up and return false

    return pressed;
}
