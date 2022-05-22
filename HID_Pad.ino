//#include <Keyboard.h> //Arduino Keyboard Library
#include <HID-Project.h> //NicoHood


#define LED0 9
#define LED1 8

#define copyBtn 5
#define pasteBtn 6
#define selectAll 7

#define inputCLK 14
#define inputDT 15
#define inputSW 16



int mode = 1;
int maxModes = 4;

int currentStateCLK;
int previousStateCLK; 

void setup()
{
  pinMode(14,OUTPUT);
  digitalWrite(14,LOW);
  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);

  pinMode(copyBtn, INPUT);
  pinMode(pasteBtn, INPUT);
  pinMode(selectAll, INPUT);

  pinMode (inputCLK,INPUT);
  pinMode (inputDT,INPUT);
  pinMode(inputSW, INPUT_PULLUP);

  /////////////////////////////////
  Serial.begin(9600);
  ////////////////////////////////
   
  Consumer.begin();
  Keyboard.begin();
}


void loop()
{ 
 ////////////////////////////ROTARY ENCODER/////////////////////////////////////////////
    currentStateCLK = digitalRead(inputCLK);

    if (currentStateCLK != previousStateCLK){ 
    // If the inputDT state is different than the inputCLK state then 
    // the encoder is rotating counterclockwise
    if (digitalRead(inputDT) != currentStateCLK) { 
        rotateRight();
      } 
    else {
      rotateLeft();
         }
     }
    previousStateCLK = currentStateCLK;
    
    if(digitalRead(inputSW) == LOW)
    {
      changeMode();
      delay(300);  
    }
//////////////////////////////TOUCH BUTTONS///////////////////////////////////////////
    if(digitalRead(copyBtn) == HIGH)
    {
      //CTRL+C
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('c');
      delay(50);
      Keyboard.releaseAll();
      delay(500);
      Serial.println("Copying..");
    }

    if(digitalRead(pasteBtn) == HIGH)
    {
      //CTRL=V
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('v');
      delay(50);
      Keyboard.releaseAll();
      delay(500);
      Serial.println("Pasting..");
    }

    if(digitalRead(selectAll)==HIGH)
    {
      //CTRL=A
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('a');
      delay(50);
      Keyboard.releaseAll();
      delay(500);
      Serial.println("Selecting All..");
    }
}
void changeMode() {
    mode = (mode % maxModes) + 1;
    switch(mode)
    {
      case 1:
      ZERO();
      break;

      case 2:
      ONE();
      break;

      case 3:
      TWO();
      break;

      case 4:
      THREE();
      break;
    }
}

void rotateLeft() {
  switch(mode) {
    case 1:
      // Decrease the volume.
      //ZERO();
      Consumer.write(MEDIA_VOLUME_DOWN);    
      break;
    case 2: 
      //ALT + SHIFT + TAB
      //ONE();
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(KEY_TAB);
      delay(100);
      Keyboard.release(KEY_LEFT_SHIFT);
      Keyboard.release(KEY_TAB);
      break;
    case 3:
      //Scroll Chrome Tabs
      //TWO();
      Keyboard.release(KEY_LEFT_ALT);
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(KEY_TAB);
      Keyboard.releaseAll();
      break;
    case 4:
      // Zoom Out
      //THREE();
      Keyboard.press(KEY_LEFT_CTRL);     
      Keyboard.press('-');
      Keyboard.releaseAll();
      break;
  }
}

void rotateRight() {
  switch(mode) {
    case 1:
      // Increase the volume.
      //ZERO();
      
      Consumer.write(MEDIA_VOLUME_UP);   
      break;
    case 2: 
      //Alt + TAB
      //ONE();
      
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_TAB);
      delay(100);
      Keyboard.release(KEY_TAB);  
      break;
    case 3:
      //Scroll Chrome Tabs
      //TWO();
      Keyboard.release(KEY_LEFT_ALT);
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_TAB);
      Keyboard.releaseAll();
      break;
    case 4:
      // Zoom In
      //THREE();
      Keyboard.press(KEY_LEFT_CTRL);     
      Keyboard.press('+');
      Keyboard.releaseAll();
      break;
  }
}

void ZERO()
{
  digitalWrite(LED0,LOW);
  digitalWrite(LED1,LOW);
}

void ONE()
{
  digitalWrite(LED0,HIGH);
  digitalWrite(LED1,LOW);
}
void TWO()
{
  digitalWrite(LED0,LOW);
  digitalWrite(LED1,HIGH);
}
void THREE()
{  
  digitalWrite(LED0,HIGH);
  digitalWrite(LED1,HIGH);
}
