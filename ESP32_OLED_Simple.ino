/*****************************************************************************************************************  
 *  Juergen Walter
 *  17.07.2017  
 *  ESP32_OLED_Simple
 *    
 *  Different TextSizes - Character: TextSize 1,2,4,7
 *  Text-Anzeige auf OLED-Display in verschiedenen Größen 
 *  brauchbar für Buchstaben: 1,2,4,7
 *  
*******************************************************************************************************************/

#include <Wire.h>                 // I2C
#include <Adafruit_GFX.h>         // OLED
#include <Adafruit_SSD1306.h>     // Graphic

#define OLED_RESET 4 // not used / nicht genutzt bei diesem Display
Adafruit_SSD1306 display(OLED_RESET);

/*******************************************************************************************************************/
void setup()
{
  Serial.begin(115200);                                         // Initilize hardware serial:

// initialize with the I2C addr 0x3C
// mit I2C-Adresse 0x3c initialisieren
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(INVERSE); 
                 
}
    unsigned int TextS=0;         // Textgroeße
    
/******************************************************************************************************************
* Textsize varied from 1 to "RESET"
* Textgröße variiert von 1 bis "RESET"
 ******************************************************************************************************************/
void loop()
{ 
    unsigned int i=0;              // Index 
    for(TextS=1;TextS<10;TextS++)
    {
    Serial.println();
    Serial.print("Start TextSize:  ");
    Serial.println(TextS);
    
    display.clearDisplay();
    display.setCursor(0,0);
    display.setTextSize(TextS);
    
/*******************************************************************************************************************
 * Manual: Button - wait  -  Warten auf Taste "Boot"
 *******************************************************************************************************************/    
/*    while (digitalRead(0) == HIGH)
     {
        yield();    //warten 
     }
*/
// send numbers to Display - Zahlen an Anzeige senden

    for ( i=10;i<65;i++)
    {              
    display.print(i);
    display.print("-");
    display.display();    
    }
    
//2s warten bis zur nächsten Anzeige
    delay(2000); 
    }     
}
  

