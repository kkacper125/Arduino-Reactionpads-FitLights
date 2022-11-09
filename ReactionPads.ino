// Playing Buttons
byte K1 = 8;
byte K2 = 9;
byte K3 = 10;


// LEDS
byte LED1 = 1;
byte LED2 = 2;
byte LED3 = 3;


// Program_Buttons
byte Picker_Button = 11;   
byte EndLess_Button = 12;
byte Reset_Button = 13;


// Other Variables
byte Program = 0;   // Choose program
int Ran_Button;
int Picker_Order[50];   // List to picker program with button order      
byte Picker_Flag = 0;      
int Picker_Index = 0;   // Current index in list   
int EndLess_Score = 0;
int EndLess_Array[10];



void setup(){
    pinMode(K1, INPUT);
    pinMode(K2, INPUT);
    pinMode(K3, INPUT);
    pinMode(Picker_Button, INPUT);
    pinMode(EndLess_Button, INPUT);
    pinMode(Reset_Button, INPUT);
    pinMode(LED1 , OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3 , OUTPUT);
    //Serial.begin(9600);
      Ran_Button = random(1, 4);
}



void loop(){

  randomSeed(millis());

   if (digitalRead(Picker_Button) == HIGH){    // Choose program
        Program = 1;
    }



   if (digitalRead(EndLess_Button) == HIGH){   // Choose program
        Program = 2;
        delay(500);
    }



   if (digitalRead(Reset_Button) == HIGH){     // Choose program
        Program = 3;
    }



   switch (Program){
        case 1:
            Picker();
            break;



       case 2:
            EndLess();
            break;



       case 3:
            Reset();
            break;
        }
}




void Picker(){     // Program where you choose the order of lights
    
    while (Picker_Flag == 0 && Program == 1){

       digitalWrite(0, HIGH);

       if (digitalRead(K1) == HIGH){
            Picker_Order[Picker_Index] = LED1;            // Adds K1 to the end of list
            Picker_Index++;                                            // Uppdates what is the last place in list
            delay(100);
        }


       else if (digitalRead(K2) == HIGH){
            Picker_Order[Picker_Index] = LED2;
            Picker_Index++;
            delay(100);
        }



       else if (digitalRead(K3) == HIGH){
            Picker_Order[Picker_Index] = LED3;
            Picker_Index++;
            delay(100);
        }

       if (digitalRead(Picker_Button) == HIGH){
            Picker_Flag = 1;
            Picker_Index = 0;            // Setts picker index to zero so the program start reading the list from the beginning
            delay(500);
        }

       
        if (digitalRead(Reset_Button) == HIGH){
            PORTD = B0;
            Program = 3;
        }
    }

   while (Picker_Flag == 1 && Program == 1){
       digitalWrite(0, LOW);

       digitalWrite(Picker_Order[Picker_Index], HIGH);            // Makes the led/button light up based of the list index

       if (Picker_Order[Picker_Index] == LED1  && digitalRead(K1) == HIGH){
            digitalWrite(Picker_Order[Picker_Index], LOW);        // Turns the led off when the button has been trigered
            Picker_Index++;
            delay(100);
        }


       else if (Picker_Order[Picker_Index] == LED2  && digitalRead(K2) == HIGH){
            digitalWrite(Picker_Order[Picker_Index], LOW);
            Picker_Index++;
            delay(100);
        }

       else if (Picker_Order[Picker_Index] == LED3  && digitalRead(K3) == HIGH){
            digitalWrite(Picker_Order[Picker_Index], LOW);
            Picker_Index++;
            delay(100);
        }

       if (Picker_Order[Picker_Index] == 0){   // Resets picker if the order is done            
            digitalWrite(Picker_Order[Picker_Index], LOW);
            Picker_Flag = 0;
        }
        
        if (digitalRead(Picker_Button) == HIGH){    // Resets and turnes of program
            PORTD = B0;
            Program = 0;
            Picker_Flag = 0;
            delay(150);
        }

        if (digitalRead(Reset_Button) == HIGH){
            PORTD = B0;
            Program = 3;
        }
    }
}


void EndLess(){     // Function that makes random led light up

  digitalWrite(Ran_Button, HIGH);

    if ((Ran_Button == LED1) && (digitalRead(K1) == HIGH)){
       digitalWrite(Ran_Button, LOW);
       delay(1000);
      Ran_Button = random(1, 4);

    }
    
    else if ((Ran_Button == LED2) && (digitalRead(K2) == HIGH)){
       digitalWrite(Ran_Button, LOW);
       delay(1000);
      Ran_Button = random(1, 4);
    }
    
    else if ((Ran_Button == LED3) && (digitalRead(K3) == HIGH)){
       digitalWrite(Ran_Button, LOW);
       delay(1000);
      Ran_Button = random(1, 4);
    }
 
    if (digitalRead(EndLess_Button) ==HIGH){
        PORTD = B0;
        Program = 0;
        delay(500);
    }

    if (digitalRead(Reset_Button) == HIGH){
        PORTD = B0;
        Program = 3;
    }
}



void Reset(){   // Resets variables
    PORTD = B0;
    EndLess_Score = 0;
    Picker_Order[50] =  {};
    Picker_Flag = 0;
    Picker_Index = 0;
    Program = 0;  
}
