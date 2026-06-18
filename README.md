🌐 System Block Diagram
[ Cloud Dashboard ] ──► [ ESP8266 Wi-Fi Module ] ──(UART Serial)──► [ LPC2129 MCU ] ──► [ 16x2 LCD & Relays ]

🛠️ Pin Connections
1. ESP8266 to LPC2129 Connection

    ESP8266 TX ──► LPC2129 P0.1 (RXD0)

    ESP8266 RX ──► LPC2129 P0.0 (TXD0)

    ESP8266 GND ──► LPC2129 GND (Common Ground)

2. LPC2129 Peripherals Connection

    LCD Pins (D4, D5, D6, D7) ──► LPC2129 pins P0.4, P0.5, P0.6, P0.7

    LCD RS Pin ──► LPC2129 pin P0.8

    LCD E Pin ──► LPC2129 pin P0.9

    Light 1 Relay ──► LPC2129 pin P0.14

    Light 2 Relay ──► LPC2129 pin P0.15

    Fan 1 Relay ──► LPC2129 pin P0.16

    Fan 2 Relay ──► LPC2129 pin P0.17

🕹️ Command Mapping Sheet

When you toggle a switch on the Arduino Cloud dashboard, the ESP8266 sends a single character over Serial to the LPC2129:

    Switch 1 (Light 1): L = ON, l = OFF

    Switch 2 (Light 2): B = ON, b = OFF

    Switch 3 (Fan 1): F = ON, f = OFF

    Switch 4 (Fan 2): T = ON, t = OFF

📂 Project Files
    main.c: Contains the main state-machine loop running on the LPC2129 to read serial data and handle the appliances.

    finalheader.h: Contains configuration registers, delays, LCD setup, and UART setup functions for LPC2129.

    smart.ino: The Arduino code uploaded to the ESP8266 to link with the Arduino IoT Cloud.

🚀 How to Run

    LPC2129: Compile main.c and finalheader.h in Keil uVision for the LPC2129 target device. Generate the .hex file and flash it using Flash Magic.

    Arduino IoT Cloud: Create a "Thing" with 4 CloudSwitches (switch1, switch2, switch3, switch4) and link them to a Dashboard.

    ESP8266: Paste the gateway code into your Arduino Cloud sketch. Disconnect the LPC2129 TX/RX wires first, then upload the sketch to your ESP8266 board. Reconnect the wires once uploading is complete.
