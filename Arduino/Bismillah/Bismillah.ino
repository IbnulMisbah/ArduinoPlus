//Bismillahir Rahmanir Rahim .
//This is my first program through the 3 devices . Esp8266-NodeMCU , Esp32 , Arduino UNO .
//So let's go .

//The setup() function runs once when it starts and when i press resat button .
void setup() 
{
	//Initialize the digital pin 13 as an output .
	pinMode ( 13 , OUTPUT );						//Digital pin 13 = (LED PIN) will be used as an output .
}

//The loop() function runs over and over again forever after running setup() function .
void loop() 
{
	digitalWrite ( 13 , HIGH );						//Turn the pin HIGH by 5 Volt .
	delay ( 1000 );									//Delay 1000 mili seconds / 1 second .
	digitalWrite ( 13 , LOW );						//Turn the pin Low by 0 Volt .
	delay ( 1000 );									//Delay 1000 mili seconds / 1 second .
}
