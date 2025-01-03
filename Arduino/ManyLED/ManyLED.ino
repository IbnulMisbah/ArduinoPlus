/*
    Bismillahir Rahmanir Rahim .
    Now I will make program that turn on many LED in parallel .
    So let's go .
*/

void setup ()                               //Setup() function is the main function for arduino IDE .
{
    pinMode ( 2 , OUTPUT );
    pinMode ( 4 , OUTPUT );
    pinMode ( 7 , OUTPUT );
    pinMode ( 8 , OUTPUT );
    pinMode ( 10 , OUTPUT );                //Pin declaration for output .
    pinMode ( 11 , OUTPUT );
    pinMode ( 12 , OUTPUT );
    pinMode ( 13 , OUTPUT );
}

void loop ()                                //loop() function runs over and over forever .
{
    digitalWrite ( 13 , LOW );              //To turn of the builtin LED .
    
    digitalWrite ( 2 , HIGH );              //Turn on pin 2 with 5 volt .
    delay ( 1000 );                         //wait for 1000 mili seconds .
    digitalWrite ( 2 , LOW );               //Turn of pin 2 with 0 volt .

    digitalWrite ( 4 , HIGH );              //Turn on pin 4 with 5 volt .
    delay ( 1000 );                         //wait for 1000 mili seconds .
    digitalWrite ( 4 , LOW );               //Turn of pin 4 with 0 volt .    

    digitalWrite ( 7 , HIGH );              //Turn on pin 7 with 5 volt .
    delay ( 1000 );                         //wait for 1000 mili seconds .
    digitalWrite ( 7 , LOW );               //Turn of pin 7 with 0 volt .

    digitalWrite ( 8 , HIGH );              //Turn on pin 8 with 5 volt .
    delay ( 1000 );                         //wait for 1000 mili seconds .
    digitalWrite ( 8 , LOW );               //Turn of pin 8 with 0 volt .
    
    digitalWrite ( 10 , HIGH );              //Turn on pin 10 with 5 volt .
    delay ( 1000 );                         //wait for 1000 mili seconds .
    digitalWrite ( 10 , LOW );               //Turn of pin 10 with 0 volt .
            
    digitalWrite ( 11 , HIGH );              //Turn on pin 11 with 5 volt .
    delay ( 1000 );                         //wait for 1000 mili seconds .
    digitalWrite ( 11 , LOW );               //Turn of pin 11 with 0 volt .
    
    digitalWrite ( 12 , HIGH );              //Turn on pin 12 with 5 volt .
    delay ( 1000 );                         //wait for 1000 mili seconds .
    digitalWrite ( 12 , LOW );               //Turn of pin 12 with 0 volt .
    

}
