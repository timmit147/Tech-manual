# Tech-manual

Change the color of the led lights with the internet and change the brightness of the light based on the time.

![image](https://user-images.githubusercontent.com/29665951/139136041-3d93a20c-4a39-49bb-887d-f4e580ca79d6.png)


## Step 1 Getting supplies

1x Arduino Board(with wifi)

1x ledstrip

1x usb to arduino port

3x connecting wires (glued to LED strip)


![IMG_20211007_161030206](https://user-images.githubusercontent.com/29665951/136402185-46be7434-224d-4d7e-a826-abde8273721e.jpg)

## Step 2 Connect arduino

To use the LED strip, you have to glue the connecting wires to the LED strip. It does not matter what color the connecting wires are glued. When the connecting wires are attached to the LED strip, you can connect it to the arduino. It doesn't matter how you click the connecting wires into the arduino, all sides work.

led strip = arduino

+5v = 3v3 

Din = D5 (you can make a choice here between D0 to D10 if you indicate that in your code)

GND = GND

Then connect the arduino to the computer and upload your code.

![Web 1920 – 9](https://user-images.githubusercontent.com/29665951/136686528-b7c93de2-8cdb-4c1b-a002-b9e73e0f1c60.jpg)

## Step 3 Testing arduino
Go to the arduino software and click on file > examples > 01.Basics > Blink. Upload this code to the arduino when a patch flashes on the board you know that the arduino is working.

## Step 4 Testing led

Open the arduino software and go to Sketch > Include library > Mannage libraries.

![image](https://user-images.githubusercontent.com/29665951/136405326-cf4ddd80-7a95-4a07-acf5-65730b938cf8.png)

A new window should open from the library manager here you type in the search field Adafruit Neopixel. Find in the list and then click install > install all.

![image](https://user-images.githubusercontent.com/29665951/136687786-ef39ab39-7d8a-42c2-8b74-2e20cda58217.png)

When you have downloaded the library you can load a test script. Go to File > Examples > Adafruit NeoPixel > beach test. Important to know if you use the LED lighting, you should always adjust the LED_PIN in the code to the pin you placed in the arduino (D5). Then click upload and the LED strip should change color.


https://www.youtube.com/watch?v=9hJyyUTflXA

## Mistakes

A problem I had was that my LED strip did not work and you could not see this in the error message. The solution I found is that I borrowed the LED strip from someone in my class to test if the LED strip was broken and then replaced it with a new one.

### Solution
Always test with a standard script whether all parts of your arduino and your computer work before you continue.

## Step 5 (Install Adafruit IO)
Open the arduino software and go to Sketch > Include library > Mannage libraries.

![image](https://user-images.githubusercontent.com/29665951/136405326-cf4ddd80-7a95-4a07-acf5-65730b938cf8.png)

A new window should open from the library manager here you type in the search field Adafruit IO Arduino. Find in the list and then click install > install all.
To install the time libary you have to do the same NTPClient.

## Mistake 
In the beginning I tried to add other people's code but it didn't work. What I didn't know was that when you use #include you also have to install a library before you can use other people's work I made this mistake a few times.

### Solution
When using #include always check if the libiary is instaled on your computer if not install the library.

![image](https://user-images.githubusercontent.com/29665951/136405252-8be0067d-e780-48c9-88f0-a2a0fab64f59.png)

## Step 6 Sign in and create dashboard

Create an account at https://io.adafruit.com/. When you go to https://io.adafruit.com/timmit147/dashboards you can copy the Username and Active Key at My key.

![image](https://user-images.githubusercontent.com/29665951/136407565-6c9930a1-f342-4b2b-b435-9a73e958fa3f.png)

Then click on new dashboard and choose a name and description.

![image](https://user-images.githubusercontent.com/29665951/136407780-0e244058-1e17-49a4-b7c6-671dbd282989.png)

On the right side you can create a new block, choose color picker and fill in sheet according to the data.

![image](https://user-images.githubusercontent.com/29665951/136408107-436826b9-3d1c-49f6-b578-14f2371caf37.png)

![image](https://user-images.githubusercontent.com/29665951/136408199-3ed8a4a5-84a8-4e2a-ac84-a2541d9e42d6.png)

## Step 7 Connect code

Go to the arduino File > Examples > Adafruit IO Arduino > Adafruitio_14_neopixel

Change in the code:
PIXEL_PIN 5 to D5
io.feed to "io.adafruit.com feed name"

Change in the config:

IO-USERNAME to "io.adafruit.com username"

IO KEY to "io.adafruit.com key"

WIFI_SSID "Wifi name"

WIFI_PASS "wifi password"


Then upload your code to the arduino.

When it works you should see in your Serial Monitor that it is connected to the website.

![image](https://user-images.githubusercontent.com/29665951/136688158-f0c12f67-49fc-462c-a5e0-dfff71263d70.png)

Now you can change the color of the led on the website https://io.adafruit.com/ and click on save to upload the code to the arduino.
![image](https://user-images.githubusercontent.com/29665951/139134946-aabf8478-6151-449f-88ad-9a097c71f811.png)


## Mistakes
At first I didn't understand that the Baud rate can be different per program and that I have to adjust it every time.

https://www.youtube.com/watch?v=4Z8f5MyS_EY

![image](https://user-images.githubusercontent.com/29665951/136686946-8063b42a-a919-4fb9-8327-4645242d5aab.png)

Another mistake I made was that I didn't specify the io.feed name in the code. If you want to adjust this, go to https://io.adafruit.com/timmit147/dashboards and select in the menu feeds and the feed you want to adjust. Then click on Feed info on the right side and there you will see the key of the feed. You can copy key name and put it in your code.

![image](https://user-images.githubusercontent.com/29665951/136688489-985bcf6a-f9cf-4227-87bb-584ca6d403ec.png)

## Step 8 change time

When you use #include <NTPClient.h> on the top of your document than you can use time in your code.

If you want that the code start at 7 you can use this code bellow for a example.

```
if(timeClient.getHours() == 7){
  Start code at 7 o'clock
}
```

https://lastminuteengineers.com/esp8266-ntp-server-date-time-tutorial/

The problem that I had whas that I forgot to add #include <WiFiUdp.h> in the code.

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


```

### Terminal 

When you look at the terminal you wil see that the arduino wil conect to the internet. The arduino is connected to the time and wil show every seconds in real time and the led strip wil change based on that info.

![image](https://user-images.githubusercontent.com/29665951/139133020-34b920ca-7cae-43ec-b96e-bfc678ee4910.png)


### Io adafruit recultaat

![thumbnail_IMG_20211010_102230287](https://user-images.githubusercontent.com/29665951/136688316-9674cdaf-da59-442a-9fdd-3419773ee24c.jpg)

![thumbnail_IMG_20211010_102217719](https://user-images.githubusercontent.com/29665951/136688324-e70048ba-de9e-4d50-89b9-1ea7da9ae2dd.jpg)

## First mistake

I was trying to make a part of my product that was too high a level for me in such a short time. So I started again with a simpler solution. The failed code I tried was to create an app where you can adjust all the settings of the Smart air conditioner without using adafruit. I managed to connect to the wifi, but I couldn't get the content from a website because I kept getting weird error messages like error -1, error -4, error -11. The problem I had with this error is probably that when you want to fetch from a website you need a digital handshake to access the website data. I didn't understand these problems so I switched to a simpler problem to fix.

### Solution 
Start with something easy and if you succeed you can make it more dificult, this prevents you from getting stuck and skiping the basic principles.

![image](https://user-images.githubusercontent.com/29665951/139140248-4fbbd9b3-343c-4a43-950f-9a442aa26063.png)


