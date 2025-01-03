//Bismillahir Rahmanir Rahim .
//Now we will learn how to turn on and off Led in Esp8266 .

void setup() 
{
	pinMode ( 2 , OUTPUT );					//The pin GPIO2 = (LED PIN,D4) will used as an output pin .
}

void loop() 
{
	digitalWrite ( 2 , HIGH );				//The pin will work by 5 volt .
	delay ( 100 );							//Wait for 100 mili seconds .

	digitalWrite ( 2 , LOW );				//The pin will work by 0 volt .
	delay ( 100 );							//Wait for 100 mili seconds .
}
