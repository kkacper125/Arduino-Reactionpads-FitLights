# Arduino-Reactionpads-FitLights
Reactionpads made by a 17 year old student using arduino. Pleas remember that this code is not perfect and has a lot that can be inproved.

This game worked in Proteus simulator but ended up never working in reality using physical components.
The point of the game is that some leds light up and you need to press the button that belongs to the led.
A game with 3 program buttons and 3 playbuttons. Adding more playbuttons wont be very hard.
Two gamemodes and one reset button.


Picker:
  The picker funcion let you decide the order of the buttons that will light up. 
  First press the picker buttton, then press the buttons in the order you choose.
  Then press the picker button again and the leds/buttons should light up in the choosen order. 
  The program will automaticly stop when there is no more buttons in the order. 
  Max amount if buttons in order is 50.
  
Endless: 
  The endless function make random buttons light up. When the lights light up, hit the button. 
  The function will go as long as you want. 
  If you want to stop the function from running, press the endless button or reset button. 
  If you want the function to stop automaticly, uncomment lines 146-150.
  
Reset:
  The reset button resets variables like picker order or endless score.
