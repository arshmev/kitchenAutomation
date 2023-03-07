/*************************************************************
  Blynk is a platform with iOS and Android apps to control
  ESP32, Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build mobile and web interfaces for any
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: https://www.blynk.io
    Sketch generator:           https://examples.blynk.cc
    Blynk community:            https://community.blynk.cc
    Follow us:                  https://www.fb.com/blynkapp
                                https://twitter.com/blynk_app

  Blynk library is licensed under MIT license
 *************************************************************
  Blynk.Edgent implements:
  - Blynk.Inject - Dynamic WiFi credentials provisioning
  - Blynk.Air    - Over The Air firmware updates
  - Device state indication using a physical LED
  - Credentials reset using a physical Button
 *************************************************************/

/* Fill in information from your Blynk Template here */
/* Read more: https://bit.ly/BlynkInject */
#define BLYNK_TEMPLATE_ID "TMPLxLP_tsDI"
#define BLYNK_TEMPLATE_NAME "PH scale"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
//#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI
#define SensorPin 01;
#include "BlynkEdgent.h"
float PH;
void PHvalue()
{
 PH=analogRead(SensorPin);

if(PH>=6.5){
  if(PH<=7.5){
  Serial.print("water is suitable for drink");
  delay(1000);
}

}
else{
 Serial.print("water is not suitable for drink..clean water Tank");
 delay(1000);
}

Blynk.virtualWrite(V0, 7.06);
}

void setup()
{
  Serial.begin(9600);
  delay(1000);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
  PHvalue();
}

