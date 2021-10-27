# Tech-manual

## Goal

![image](https://user-images.githubusercontent.com/29665951/139068844-4bfb8b13-4a81-46ea-bbe4-84a7c0651e22.png)


## Benodigheden

1x Arduino Board(met wifi)

1x ledstrip

1x usb naar arduino poort

3x verbindingsdraden (vast gelijmt aan ledstrip)


![IMG_20211007_161030206](https://user-images.githubusercontent.com/29665951/136402185-46be7434-224d-4d7e-a826-abde8273721e.jpg)

## Aansluiten arduino

Om de ledstrip te gebruiken moet je de verbindingsdraden vast lijmen aan de ledstrip. Het maakt niet uit welke kleur de verbindingsdraden zijn gelijmt. Wanneer de verbindingsdraden vast zitten aan de ledstrip kan je deze koppelen aan de arduino. Het maakt niet uit hoe je de verbindingsdraden in de arduino klikt alle kanten werkt.

ledstrip = arduino

+5v = 3v3 

Din = D5 (je kan hier een keuze maken tussen D0 tot D10 als je dat maar in je code aangeeft)

GND = GND

Connect daarna de arduino aan de computer en upload je code.

![Web 1920 – 9](https://user-images.githubusercontent.com/29665951/136686528-b7c93de2-8cdb-4c1b-a002-b9e73e0f1c60.jpg)

## Testen arduino
Ga naar de arduino software en klik op file > examples > 01.Basics > Blink. Upload deze code naar de arduino wanneer er een lapje knippert op het board weet je dat de arduino werkt.

## Testen led

Open de arduino software en ga naar Sketch > Include library > Mannage libraries.

![image](https://user-images.githubusercontent.com/29665951/136405326-cf4ddd80-7a95-4a07-acf5-65730b938cf8.png)

Een nieuw venster moet dan openen van de library manager hier type je dan in het zoekveld Adafruit Neopixel. Zoek in de lijst en klik vervolgens op instaleren > install all.

![image](https://user-images.githubusercontent.com/29665951/136687786-ef39ab39-7d8a-42c2-8b74-2e20cda58217.png)

Wanneer je de libary heb gedownload kan je een test script laden. Ga naar File > Examples > Adafruit NeoPixel > strandtest. Belangerijk om te weten als je de led verlichting gebruikt moet je in de code altijd de LED_PIN aanpassen naar de pin die je in de arduino heb geplaatst (D5). Klik vervolgens op uploaden en de ledstrip zou van kleur moeten veranderen.

https://www.youtube.com/watch?v=9hJyyUTflXA

## Fouten

Een probleem dat ik had was dat mijn ledstrip niet werkten en je dit ook niet terug kon zien in de fout melding. De oplossing die ik heb gevonden is dat ik de ledstrip heb geleend van iemand uit mijn klas en daarna heb vervangen voor een nieuwe.


## Final code 

### Adafruit code

```
//Libaries you need for this project
#include "config.h"
#include "Adafruit_NeoPixel.h"
#include <NTPClient.h>
#include <WiFiUdp.h>

//Change time in seconds
const long utcOffsetInSeconds = 3600;

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);


//Connect the ledstrip to the right pixel pin
#define PIXEL_PIN     D5
//Amounth of pixels on the led strip
#define PIXEL_COUNT   9
//Devining what type of pixels to use
#define PIXEL_TYPE    NEO_GRB + NEO_KHZ800

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

// set up the color feed from adafruit
AdafruitIO_Feed *color = io.feed("color-change");


void setup() {
  // start the serial connection
  Serial.begin(115200);

  // wait for serial monitor to open
  while(! Serial);

  // connect to io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  // set up a message handler for the 'color' feed.
  // the handleMessage function (defined below)
  // will be called whenever a message is
  // received from adafruit io.
  color->onMessage(handleMessage);

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

//  Start time client
   timeClient.begin();

  // we are connected
  Serial.println();
  Serial.println(io.statusText());
  color->get();

  // neopixel init
  pixels.begin();
  pixels.show();

}

void loop() {

  // io.run(); is required for all sketches.
  // it should always be present at the top of your loop
  // function. it keeps the client connected to
  // io.adafruit.com, and processes any incoming data.
  io.run();

//  get new time data from time client
  timeClient.update();

//Check if time in seconds is even
  if ( (timeClient.getSeconds() % 2) == 0) { 
    Serial.print(timeClient.getSeconds());
  for(int i=0; i<PIXEL_COUNT; ++i) {
    pixels.begin();
pixels.setBrightness(100);
  }
 }

// Check if time in seconds is odd
 else{
  Serial.print(timeClient.getSeconds());
  for(int i=0; i<PIXEL_COUNT; ++i) {
    pixels.begin();
pixels.setBrightness(50);
  }
 }
  pixels.show();

//loop every 1 second
   delay(1000);
}

// this function is called whenever a 'color' message
// is received from Adafruit IO. it was attached to
// the color feed in the setup() function above.
void handleMessage(AdafruitIO_Data *data) {

  // print RGB values and hex value from adafruit 
  Serial.println("Received HEX: ");
  Serial.println(data->value());

//change color data to neopixel
  long color = data->toNeoPixel();

//loop all pixels to change
  for(int i=0; i<PIXEL_COUNT; ++i) {
    pixels.setPixelColor(i, color);
  }

  pixels.show();

}
```

### Config file

```
/************************ Adafruit IO Config *******************************/

// visit io.adafruit.com if you need to create an account,
// or if you need your Adafruit IO key.
#define IO_USERNAME "PLACE HERE YOUR USERNAME FROM ADAFRUIT"
#define IO_KEY "PLACE HERE YOUR KEY FROM ADAFRUIT"

/******************************* WIFI **************************************/

// the AdafruitIO_WiFi client will work with the following boards:
//   - HUZZAH ESP8266 Breakout -> https://www.adafruit.com/products/2471
//   - Feather HUZZAH ESP8266 -> https://www.adafruit.com/products/2821
//   - Feather HUZZAH ESP32 -> https://www.adafruit.com/product/3405
//   - Feather M0 WiFi -> https://www.adafruit.com/products/3010
//   - Feather WICED -> https://www.adafruit.com/products/3056
//   - Adafruit PyPortal -> https://www.adafruit.com/product/4116
//   - Adafruit Metro M4 Express AirLift Lite ->
//   https://www.adafruit.com/product/4000
//   - Adafruit AirLift Breakout -> https://www.adafruit.com/product/4201
//   - Adafruit AirLift Shield -> https://www.adafruit.com/product/4285
//   - Adafruit AirLift FeatherWing -> https://www.adafruit.com/product/4264

#define WIFI_SSID "PLACE HERE YOUR WIFI SSID/USERNAME"
#define WIFI_PASS "PLACE HERE YOUR WIFI PASWORD"

// uncomment the following line if you are using airlift
// #define USE_AIRLIFT

// uncomment the following line if you are using winc1500
// #define USE_WINC1500

// comment out the following lines if you are using fona or ethernet
#include "AdafruitIO_WiFi.h"

#if defined(USE_AIRLIFT) || defined(ADAFRUIT_METRO_M4_AIRLIFT_LITE) ||         \
    defined(ADAFRUIT_PYPORTAL)
// Configure the pins used for the ESP32 connection
#if !defined(SPIWIFI_SS) // if the wifi definition isnt in the board variant
// Don't change the names of these #define's! they match the variant ones
#define SPIWIFI SPI
#define SPIWIFI_SS 10 // Chip select pin
#define NINA_ACK 9    // a.k.a BUSY or READY pin
#define NINA_RESETN 6 // Reset pin
#define NINA_GPIO0 -1 // Not connected
#endif
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS, SPIWIFI_SS,
                   NINA_ACK, NINA_RESETN, NINA_GPIO0, &SPIWIFI);
#else
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);
#endif
/******************************* FONA **************************************/

// the AdafruitIO_FONA client will work with the following boards:
//   - Feather 32u4 FONA -> https://www.adafruit.com/product/3027

// uncomment the following two lines for 32u4 FONA,
// and comment out the AdafruitIO_WiFi client in the WIFI section
// #include "AdafruitIO_FONA.h"
// AdafruitIO_FONA io(IO_USERNAME, IO_KEY);

/**************************** ETHERNET ************************************/

// the AdafruitIO_Ethernet client will work with the following boards:
//   - Ethernet FeatherWing -> https://www.adafruit.com/products/3201

// uncomment the following two lines for ethernet,
// and comment out the AdafruitIO_WiFi client in the WIFI section
// #include "AdafruitIO_Ethernet.h"
// AdafruitIO_Ethernet io(IO_USERNAME, IO_KEY);

```
