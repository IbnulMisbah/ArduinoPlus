//Bismillahir Rahmanir Rahim .
//Now we will make a program to turn on and off pin of an Esp32 board .


//The setup() function is main function in arduino program .
void setup() 
{
    pinMode ( 2 , OUTPUT );                //Initialize the GPIO2 = (LED PIN,D2) no pin as an output pin .
}

//The loop() function will run over and over after running the setup() function .
void loop() 
{
    digitalWrite ( 2 , HIGH );             //The 2 no pin will work with 5 volt .
    delay ( 100 );                          //And wait for 100 mili seconds .
    
    digitalWrite ( 2 , LOW );              //The 2 no pin will work will 0 volt .
    delay ( 100 );                          //And delay for 100 mili seconds . 
}
