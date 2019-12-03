# IoTHub & ESP8266
Welcome to this tutorial on setting an ESP8266 microcontroller up for retriving sensor measurements, and sending these to the Azure IoTHub. 

### Prerequisits
 - ESP8266 developer board. like this [www.banggood.com](https://www.banggood.com/da/Geekcreit-Doit-NodeMcu-Lua-ESP8266-ESP-12F-WIFI-Development-Board-p-985891.html?gmcCountry=DK&currency=DKK&createTmp=1&utm_source=googleshopping&utm_medium=cpc_bgs&utm_content=xibei&utm_campaign=xibei-ssc-dk-da-euw-all-0909-13anv&gclid=CjwKCAiArJjvBRACEiwA-Wiqq3pkx0L9jpYvmwT4z9RT3fmTWhZX5lKq6FmPp0D5VYa5_ToguApTLxoCNnYQAvD_BwE&cur_warehouse=UK)
 - A account on Microsoft [Azure](https://portal.azure.com)
 - Installed the latest version of [arduino IDE](https://portal.azure.com)
 - To work with a real sensor, use the DHT11 or DHT22 (but simulaton is possible)
 
## Preparing the Arduino IDE to Work with the NodeMCU Module
** Please use Ardunio version 1.6.8 or above

##### Go To ‘Preferences’
In the Arduino IDE, Select “Preferences” via the File Menu.

![Preferences](https://github.com/kaareseras/IoTHub_ESP8266/blob/master/Images/image001.png)

##### Add A URL
The Arduino IDE, need to be avare of the definition for ESP8266, so a community driven board definiton is added

Type “http://arduino.esp8266.com/stable/package_esp8266com_index.json”
 into the field for ‘Additional Boards Manager URL’.

![Add URL](https://github.com/kaareseras/IoTHub_ESP8266/blob/master/Images/image002.png)

##### Access ‘Board Manager’
Select “Boards Manager” via the Tool Menu.

![Select Boards Manager](https://github.com/kaareseras/IoTHub_ESP8266/blob/master/Images/image004.png)

##### Install the ESP8266 Files
From the boards manager pop up, scroll until you find the esp8266 board.   Select the latest version and install.

![Install](https://github.com/kaareseras/IoTHub_ESP8266/blob/master/Images/image006.png)

##### Select the NodeMCU V1.0 ESP8266-12E Board
Now that the Arduino IDE is avare of the ESP8266, we need to tell it to use this board
Select it via the ‘Tools’ menu.

![Select board](https://github.com/kaareseras/IoTHub_ESP8266/blob/master/Images/image008.png)

##### Select the CPU Frequency and Upload Speed
Match the picture below.

![Select settings](https://github.com/kaareseras/IoTHub_ESP8266/blob/master/Images/image009.png)

The Arduino IDE is now set up and ready to for you to start to work with :-)

## Connect the ESP8266 board to your PC

![connect](https://github.com/kaareseras/IoTHub_ESP8266/blob/master/Images/image11.png)

##### First Time Connecting
If this is your first time connecting your development board, it will start installing drivers for the usb-serial port

