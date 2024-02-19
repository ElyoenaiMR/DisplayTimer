#include <timer_picc.h>

void active_display(int actDisplay){
   switch(actDisplay){
      case 1:
       output_high(PIN_A0);
       output_low(PIN_A1);
       output_low(PIN_A2);
       output_low(PIN_A3);  
       break;
    
     case 2:
       output_low(PIN_A0);
       output_high(PIN_A1);
       output_low(PIN_A2);
       output_low(PIN_A3);
       break;
       
     case 3:
       output_low(PIN_A0);
       output_low(PIN_A1);
       output_high(PIN_A2);
       output_low(PIN_A3);
       break;
     
     case 4:
      output_low(PIN_A0);
      output_low(PIN_A1);
      output_low(PIN_A2);
      output_high(PIN_A3);
      break;
      
    default:
      break;
   
   }

}


void number(int num){
   switch(num){
      case 0:
       output_high(PIN_B0);   //a
       output_high(PIN_B1);   //b
       output_high(PIN_B2);   //c
       output_high(PIN_B3);   //d
       output_high(PIN_B4);   //e
       output_high(PIN_B5);   //f
       output_low(PIN_B6);    //g
       output_low(PIN_B7);   //dp
      break;
      
      case 1:
       output_low(PIN_B0);   //a
       output_high(PIN_B1);   //b
       output_high(PIN_B2);   //c
       output_low(PIN_B3);   //d
       output_low(PIN_B4);   //e
       output_low(PIN_B5);   //f
       output_low(PIN_B6);    //g
       output_low(PIN_B7);   //dp      
      break;
      
      case 2:
       output_high(PIN_B0);   //a
       output_high(PIN_B1);   //b
       output_low(PIN_B2);   //c
       output_high(PIN_B3);   //d
       output_high(PIN_B4);   //e
       output_low(PIN_B5);   //f
       output_high(PIN_B6);    //g
       output_low(PIN_B7);   //dp      
      break;
      
      case 3:
       output_high(PIN_B0);   //a
       output_high(PIN_B1);   //b
       output_high(PIN_B2);   //c
       output_high(PIN_B3);   //d
       output_low(PIN_B4);   //e
       output_low(PIN_B5);   //f
       output_high(PIN_B6);    //g
       output_low(PIN_B7);   //dp      
      break;
      
      case 4:
       output_low(PIN_B0);   //a
       output_high(PIN_B1);   //b
       output_high(PIN_B2);   //c
       output_low(PIN_B3);   //d
       output_low(PIN_B4);   //e
       output_high(PIN_B5);   //f
       output_high(PIN_B6);    //g
       output_low(PIN_B7);   //dp     
      break;
      
      case 5:
       output_high(PIN_B0);   //a
       output_low(PIN_B1);   //b
       output_high(PIN_B2);   //c
       output_high(PIN_B3);   //d
       output_low(PIN_B4);   //e
       output_high(PIN_B5);   //f
       output_high(PIN_B6);    //g
       output_low(PIN_B7);   //dp     
      break;
      
      case 6:
       output_high(PIN_B0);   //a
       output_low(PIN_B1);   //b
       output_high(PIN_B2);   //c
       output_high(PIN_B3);   //d
       output_high(PIN_B4);   //e
       output_high(PIN_B5);   //f
       output_high(PIN_B6);    //g
       output_low(PIN_B7);   //dp     
      break;
      
      case 7:
       output_high(PIN_B0);   //a
       output_high(PIN_B1);   //b
       output_high(PIN_B2);   //c
       output_low(PIN_B3);   //d
       output_low(PIN_B4);   //e
       output_low(PIN_B5);   //f
       output_low(PIN_B6);    //g
       output_low(PIN_B7);   //dp      
       
      case 8:
       output_high(PIN_B0);   //a
       output_high(PIN_B1);   //b
       output_high(PIN_B2);   //c
       output_high(PIN_B3);   //d
       output_high(PIN_B4);   //e
       output_high(PIN_B5);   //f
       output_high(PIN_B6);    //g
       output_low(PIN_B7);   //dp      
      break;
      
      case 9:
       output_high(PIN_B0);   //a
       output_high(PIN_B1);   //b
       output_high(PIN_B2);   //c
       output_high(PIN_B3);   //d
       output_low(PIN_B4);   //e
       output_high(PIN_B5);   //f
       output_high(PIN_B6);    //g
       output_low(PIN_B7);   //dp
      break;
          
      default:
         break;
      
   
   }

}


void all_off()
{
    output_low(PIN_B0);   //a
    output_low(PIN_B1);   //b
    output_low(PIN_B2);   //c
    output_low(PIN_B3);   //d
    output_low(PIN_B4);   //e
    output_low(PIN_B5);   //f
    output_low(PIN_B6);    //g
    output_low(PIN_B7);   //dp
}



void standbyDisplay(int *num_in_display, int modifiedDigit){
   int flashingCounter=0;     //counter used to turn on or off the selected number
   int actDisp=0;
   static int digit=0;
   do{
      
      flashingCounter++;
      
     ////Reading buttons//////
      
       if(input(PIN_A7)==0)  //changes blinking number
       {
         modifiedDigit++;
         if(modifiedDigit>4)
            modifiedDigit=1;         
       }  
   
   
              
       if(input(PIN_A6)==0){   //detects if increment button is pressed
        num_in_display[digit]=num_in_display[digit]+1;
        
         if(num_in_display[digit]>9)
            num_in_display[digit]=0;
       } 
   
     ///////////
   
      for(actDisp=0; actDisp<4; actDisp++){
   
         if(modifiedDigit != (actDisp+1))  //If the number is not being edited, show number as normal
         {
            number(*(num_in_display+actDisp));       //number stored in the numbers' array - number function is the  LO and HI configuration for each pin
            active_display(actDisp+1);    //display to be turned on
            DELAY_MS(2);
         }
         
               
         if(flashingCounter<50 && (modifiedDigit == (actDisp+1)))
         {
            all_off();
         }
         else
         {
            number(*(num_in_display+actDisp));       //number stored in the numbers' array
            active_display(actDisp+1);    //display to be turned on
            DELAY_MS(2);
         }
      
         //check if botton 1 is pressed
      //   if
         
      }
   }while(flashingCounter<100);

}

void runningDisplay(int *num){
   int actDisp=0;
   for(actDisp=0; actDisp<4; actDisp++){
      number(*(num+actDisp));       //number stored in the numbers' array
      active_display(actDisp+1);    //display to be turned on
   
      DELAY_MS(10);
   }

}


void main()
{
   int num_in_display[4]={0,0,0,0};  //this array stores the current value of each digit in the display
   num_in_display[0]=0;
   num_in_display[1]=1;
   num_in_display[2]=2;
   num_in_display[3]=3;
     
   set_tris_a(0b11000000);       //Port A salidas y entradas RA6 y RA7
//   set_tris_b(0b00000000);       //Port B salidas nibble bajo   
     
   int editedDisplay=1;   //1 to 4, blinking number in the display
   
   while(TRUE)
    {
    
     standbyDisplay(num_in_display, editedDisplay);
     
     /*
     if(input(PIN_A7)==0)  //changes blinking number
       {
         editedDisplay++;
         if(editedDisplay>4)
            editedDisplay=1;         
       } 
       
           //detects if increment button is pressed
      if(input(PIN_A6)==0){
        num_in_display[editedDisplay-1]=num_in_display[editedDisplay-1]+1;
        
        if(num_in_display[editedDisplay-1]>9)
            num_in_display[editedDisplay-1]=0;
      }  
     */
    }
   
  

 //    standbyDisplay(num_in_display, 2);
    //  runningDisplay(num_in_display);

}
