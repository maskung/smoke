/**********************************
 * This code for detec the smoke  
 * if the smoke has detected it will open 
 * alarm system and sedn notify to LINE application
 *********************************/

//get needed library

#include <wiringPi.h>
#include <stdio.h>

//pin specfication
#define  LED       0
#define  BUZZER    1
#define  ALGOHOL    4

void siren(void);

// main funcion
int main(void)
{
    int sensordetect = 0;  // set default sensor value
    //initial device
	if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
		printf("setup wiringPi failed !");
		return 1; 
	}
	printf("linker LedPin : GPIO %d(wiringPi pin)\n",BUZZER); //when initialize wiring successfully,print message to screen
	
    //setup pin for device
	pinMode(LED, OUTPUT);
	pinMode(BUZZER, OUTPUT);
	pinMode(ALGOHOL, INPUT);

    //run forever
	while(1){
        

        sensordetect = digitalRead(ALGOHOL);

        printf("sensor status : %d\n",sensordetect);

        //echo siren and show bliking led if sensor has detected ( 0 means senser has detected)
        if (sensordetect == 0) {
            siren();
        }
            
	}

	return 0;
}

//make a siren sound and blinking led
void siren(void) {
    int i;

    //generate siren low sound
    digitalWrite(LED,HIGH);
    for (i = 0; i <80; i++) // Wen a frequency sound
    {
        digitalWrite (BUZZER, HIGH) ;// send voice
        delay (1) ;// Delay 1ms
        digitalWrite (BUZZER, LOW) ;// do not send voice
        delay (1) ;// delay ms
    }
    digitalWrite(LED,LOW);
    //generate siren high sound
    for (i = 0; i <100; i++) // Wen Qie out another frequency sound
    {
        digitalWrite (BUZZER, HIGH) ;// send voice
        delay (2) ;// delay 2ms
        digitalWrite (BUZZER, LOW) ;// do not send voice
        delay (2) ;// delay 2ms
    }
}

