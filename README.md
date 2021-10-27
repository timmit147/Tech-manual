# Tech-manual

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


