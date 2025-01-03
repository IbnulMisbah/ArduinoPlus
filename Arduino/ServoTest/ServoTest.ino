//Bismillahir Rahmanir Rahim .
//This is a test for my Servo motor ..
//So let's go .

//Include the Servo librery ..
#include <Servo.h>

//Declare the Servo pin 
int ServoPin = 9;

//Create a Servo object ..
Servo myServo ;

//The setup() function runs once when it starts and when i press resat button .
void setup() 
{
	//Now we connect the servo controller pin to the 9 ;
	myServo.attach ( ServoPin );						//Digital pin 9 will be used as an output .
}

//The loop() function runs over and over again forever after running setup() function .
void loop() 
{
	//Make Servo go to 0 degree ..
	myServo.write(0);
	delay ( 1000 );									//Delay 1000 mili seconds / 1 second .

    //Make Servo go to 90 degree ..
	myServo.write ( 90 );
	delay ( 1000 );									//Delay 1000 mili seconds / 1 second .
	
    //Make Servo go to 180 degree ..
	myServo.write ( 180 );
	delay ( 1000 );									//Delay 1000 mili seconds / 1 second .
}
