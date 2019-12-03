# IoTHub & ESP8266
Welcome to this tutorial on setting an ESP8266 microcontroller up for retriving sensor measurements, and sending these to the Azure IoTHub. 

### Prerequisits
 - A Windows PC 
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

![Select board](https://github.com/kaareseras/IoTHub_ESP8266/blob/master/Images/image008.jpg)

##### Select the CPU Frequency and Upload Speed
Match the picture below.

![Select settings](https://github.com/kaareseras/IoTHub_ESP8266/blob/master/Images/image009.png)

The Arduino IDE is now set up and ready to for you to start to work with :-)

## Connect the ESP8266 board to your PC

![connect](https://github.com/kaareseras/IoTHub_ESP8266/blob/master/Images/image011.jpg)

##### First Time Connecting
If this is your first time connecting your development board, it will start installing drivers for the usb-serial port

in the windows device list, you can read the port number of the new device

right click the start button, and select Device manager
![connect](https://github.com/kaareseras/IoTHub_ESP8266/blob/master/Images/port.png)

Chose the right port in the Arduino IDE -> Tools -> Port

## Hello World

##### Blink the onboard Led
Now its time to upload the first simple program: Hello World


Get the sample application from GitHub
The sample application is hosted on GitHub.  
To clone the sample repository to your computer, follow these steps:
1.	Open a command prompt or a terminal window.
2.	Go to a folder where you want the sample application to be stored.
3.	Run the following command: git clone https://github.com/kaareseras/IoTHub_ESP8266.git
4.	Open the folder where the sample application is stored.
5.	Open the HelloWorld.ino file in the HelloWorld folder in the Arduino IDE.

**If you have not installed GIT, you can download it here: https://git-for-windows.github.io/

In you Arduino IDE: 

1. Open the HelloWorld.ino file from the HelloWorld folder
2. Make sure that the right port is selected
3. Click the right arrow in the top left

The Arduino IDE will now compile and upload the code to the ESP processor, and if all goes well, the onboard blue LED schould start to blink.

## Test the Wifi is working
##### List the available wifi networks

Lets move on to a bit harder chalenge

1. Open the ScanWifi.ino file from the ScanWifi folder
2. Make sure that the right port is selected
3. Click the right arrow in the top left

The Arduino IDE will now compile and upload the code to the ESP processor
When the code is uploaded, click the Serial Monitor icon in the top right connor, make sure to set the serial speed to 115200 Baud

![baud](https://github.com/kaareseras/IoTHub_ESP8266/blob/master/Images/baud.png)

The Serial Monitor schould now list all the wifi networks that the ESP8266 can see


## Azure IoTHub setup

##### Create an IoT hub
This section describes how to create an IoT hub using the Azure portal.
1.	Log in to the [Azure portal](https://portal.azure.com).
2.	Choose +Create a resource, then Search the Marketplace for the IoT Hub.
3.	Select IoT Hub and click the Create button. You see the first screen for creating an IoT hub.

![create1](https://github.com/kaareseras/IoTHub_ESP8266/blob/master/Images/image013.jpg)
 
Fill in the fields.

Subscription: Select the subscription to use for your IoT hub.

Resource Group: You can create a new resource group or use an existing one. To create a new one, click Create new and fill in the name you want to use. To use an existing resource group, click Use existing and select the resource group from the dropdown list. For more information, see Manage Azure Resource Manager resource groups.

Region: This is the region in which you want your hub to be located. Select the location closest to you from the dropdown list.

IoT Hub Name: Put in the name for your IoT Hub. This name must be globally unique. If the name you enter is available, a green check mark appears.

4. Click Next: Size and scale to continue creating your IoT hub.

![scale](https://github.com/kaareseras/IoTHub_ESP8266/blob/master/Images/image014.png)
 
On this screen, you can take the defaults and just click **Review + create** at the bottom.

**Pricing and scale tier**: You can choose from several tiers depending on how many features you want and how many messages you send through your solution per day. The free tier is intended for testing and evaluation. It allows 500 devices to be connected to the IoT hub and up to 8,000 messages per day. Each Azure subscription can create one IoT Hub in the free tier.

**IoT Hub units**: The number of messages allowed per unit per day depends on your hub's pricing tier. For example, if you want the IoT hub to support ingress of 700,000 messages, you choose two S1 tier units.

**Advanced / Device-to-cloud partitions**: This property relates the device-to-cloud messages to the number of simultaneous readers of the messages. Most IoT hubs only need four partitions.

5. Click **Review + create** to review your choices. You see something similar to this screen. 

![Create](https://github.com/kaareseras/IoTHub_ESP8266/blob/master/Images/image016.png)

6. Click **Create** to create your new IoT hub. Creating the hub takes a few minutes.

### Retrieve connection string for IoT hub

After your hub has been created, retrieve the connection string for the hub. This is used to connect devices and applications to your hub.

1. Click on your hub to see the IoT Hub pane with Settings, and so on. Click **Shared access policies**.
2. In **Shared access policies**, select the **iothubowner** policy.
3. Under **Shared access keys**, copy the **Connection string -- primary key** to be used later.

![Retrieve](https://github.com/kaareseras/IoTHub_ESP8266/blob/master/Images/image017.png)
 
### Register a new device in the IoT hub
In this section, you create a device identity in the identity registry in your IoT hub. A device cannot connect to IoT hub unless it has an entry in the identity registry. For more information, see the "Identity registry" section of the IoT Hub developer guide
1. In your IoT hub navigation menu, open **IoT Devices**, then select **Add** to register a new device in your IoT hub

![Add](https://github.com/kaareseras/IoTHub_ESP8266/blob/master/Images/image019.png)

2. Provide a name for your new device, such as **myDeviceID**, and select **Save**. This action creates a new device identity for your IoT hub.

![Add](https://github.com/kaareseras/IoTHub_ESP8266/blob/master/Images/image021.png)

3. After the device is created, open the device from the list in the **IoT devices** pane. **Copy the Connection string---primary key to use later**.

![Add](https://github.com/kaareseras/IoTHub_ESP8266/blob/master/Images/image023.png)
 

## Setup Sample code for device

Now everything is ready to start working on the actual code for the device

Open the app.ino file in the app folder in the Arduino IDE.

##### Install necessary libraries
The sketch we need to import all the Microsoft SDKs and som other Libs:

1. In the Arduino IDE select : Sketch -> Include libraries -> Manage libraries.

![Libs](https://github.com/kaareseras/IoTHub_ESP8266/blob/master/Images/image025.png)

2. Search for the following library names one by one. For all libraries, click Install.
*	AzureIoTHub
*	AzureIoTUtility
*	AzureIoTProtocol_MQTT  
*	ArduinoJson	**Important Select version 5.13.5**
*	DHT sensor library
*	Adafruit Unified Sensor

### Bug Fix :-(
Currently there is a few bugs that we need to fix before moving on

Open the file **Arduino.H** from the folder C:\Users\username\AppData\Local\Arduino15\packages\esp8266\hardware\esp8266\2.6.2\cores\esp8266 

*Replace username with the correct name from your computer 

delete line 137: #define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))

Open the file **WiFiClientSecure.h** from the folder C:\Users\username\AppData\Local\Arduino15\packages\esp8266\hardware\esp8266\2.6.2\libraries\ESP8266WiFi\src

*Replace username with the correct name from your computer 

Replace the code in the file with this code:

```
//#include "WiFiClientSecureAxTLS.h"
//using namespace axTLS;

/**********************************
 * !! Now BearSSL is the default !!
 *
 * While not advised,
 * Use legacy API without updating with:
 */
#define USING_AXTLS
#include <ESP8266WiFi.h>
//#include <WiFiClientSecure.h>
#include "WiFiClientSecureAxTLS.h"
using namespace axTLS;
 /*
 *
 **********************************/

#include "WiFiClientSecureBearSSL.h"

#ifndef USING_AXTLS
// do not default to BearSSL API ("using" has no "unusing" counterpart)
using namespace BearSSL;
#endif
```
Open the userConfig.h file in the app folder.

// Physical device information for board and sensor

#define DEVICE_ID "myDeviceId "  **Change to match the DeviceID in Azure**

#define DHT_TYPE DHT11 **Change to math the sensor you have**

* Save the file
* Deploy code to device
* Attach DHT11 to device **Very important to wire it correctly**
 
![Libs](https://github.com/kaareseras/IoTHub_ESP8266/blob/master/Images/image028.png)

Deploy the sample application to ESP8266
After the upload completes successfully, follow these steps to enter your credentials:
1.	Open Arduino IDE, click Tools > Serial Monitor.
2.	In the serial monitor window, notice the two drop-down lists in the lower-right corner.
3.	Select No line ending for the left drop-down list.
4.	Select 115200 baud for the right drop-down list.
5.	In the input box located at the top of the serial monitor window, enter the following information if you are asked to provide them, and then click Send.
* Wi-Fi SSID
* Wi-Fi password
* Device connection string
 
Note

The credential information is stored in the EEPROM of ESP8266. If you click the reset button on the ESP8266 board, the sample application asks if you want to erase the information. Enter Y to have the information erased. You are asked to provide the information a second time.
Verify the sample application is running successfully
If you see the following output from the serial monitor window and the blinking LED on ESP8266, the sample application is running successfully.
 
**Congratulations, your device is now sending sensordata to IoTHub**


