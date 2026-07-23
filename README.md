🏠 AURA HOME
An Integrated IoT Framework for Cloud-Based Domestic Automation

📌 Overview

AURA HOME is an IoT-enabled smart home automation system designed to remotely monitor and control household appliances through the Internet. The project combines the processing capability of the ARM7 LPC2129 microcontroller with the wireless connectivity of the ESP8266 Wi-Fi module and Arduino IoT Cloud.

Users can securely control electrical appliances such as lights and fans from anywhere using a mobile phone or web dashboard. The system provides reliable UART communication between the LPC2129 and ESP8266 while ensuring efficient relay-based switching of AC loads.

🎯 Objectives
Automate household appliances using IoT.
Enable remote monitoring and control.
Reduce manual intervention.
Improve energy efficiency.
Provide a scalable smart home platform.
✨ Features
📱 Remote appliance control
☁️ Arduino IoT Cloud integration
📶 Wi-Fi connectivity
🔄 Real-time device status
⚡ Relay-based appliance switching
💻 LPC2129 firmware written in Embedded C
🔗 UART communication between ARM7 and ESP8266
🔒 Reliable and low-cost implementation

🏗 System Architecture
                  Internet
                      │
                      │
              Arduino IoT Cloud
                      │
                  Wi-Fi Network
                      │
                 ESP8266 Module
              (UART Communication)
                      │
                ARM7 LPC2129
                      │
                Relay Driver Circuit
                      │
      ┌──────────┬──────────┬──────────┬──────────┐
      │          │          │          │
   Light 1    Light 2     Light 3     Light4
🔷 Block Diagram
                +----------------------+
                |   Arduino IoT Cloud  |
                +----------+-----------+
                           |
                     Internet / Wi-Fi
                           |
                   +-------+--------+
                   |    ESP8266     |
                   +-------+--------+
                           |
                    UART Communication
                           |
                 +---------+---------+
                 |    LPC2129 ARM7   |
                 +---------+---------+
                           |
                   GPIO Output Pins
                           |
                  +--------+--------+
                  | Relay Driver IC |
                  +--------+--------+
                           |
          +----------------+----------------+-----------------+
          
          |                |                |                 |
      Light 1          Light 2           Light 3            Light4
      
🔩 Hardware Components
Component            	      Purpose
LPC2129 ARM7	          Main Controller
ESP8266 Wi-Fi           Module	Internet Connectivity
Relay Module	          Controls AC Appliances
Relay Driver Circuit  	Drives Relay Coils
230V AC Bulbs	          Home Appliances
Fan	                    Electrical Load
5V Power Supply        	Relay Power
3.3V Regulator	        LPC2129 & ESP8266 Supply
Crystal Oscillator	    System Clock
USB-UART Converter	    Programming & Debugging
Connecting Wires      	Hardware Connections

💻 Software Requirements
*Keil uVision
*Flash Magic
*Arduino IDE
*Arduino IoT Cloud
*Embedded C
*Windows 10/11
*⚙️ Technologies Used
*Embedded C
*ARM7 LPC2129
*UART Protocol
*ESP8266 Wi-Fi
*Arduino IoT Cloud
*IoT
*Relay Automation

🔄 Working Principle
1.User sends command from Arduino IoT Cloud.
2.ESP8266 receives the command over Wi-Fi.
3.ESP8266 transmits the command to LPC2129 through UART.
4.LPC2129 processes the received command.
5.Corresponding GPIO pin becomes HIGH or LOW.
6.Relay driver energizes the relay.
7.Connected appliance turns ON or OFF.
8.Device status is updated back to the cloud.

📡 Communication Flow
User
 │
 ▼
Arduino IoT Cloud
 │
 ▼
ESP8266 Wi-Fi Module
 │ UART
 ▼
LPC2129 ARM7
 │
 ▼
Relay Driver
 │
 ▼
Electrical Appliance

📂 Project Structure
AURA_HOME
│
├── ARM7 Firmware
│     ├── mainprog.c
│     ├── lcdheader.h
│     ├── config.h
│     ├── uartheader.h
│
├── ESP8266 Code
│
├── Arduino IoT Cloud
│
├── Circuit Diagram
│
├── Images
│
└── README.md

🚀 Future Enhancements
1.Voice Assistant Integration
2.Mobile Application
3.Energy Consumption Monitoring
4.Security Alerts
5.AI-based Automation
6.Sensor Integration
7.MQTT Communication
8.Smart Scheduling

📚 Applications
1.Smart Homes
2.Offices
3.Industries
4.Hostels
5.Hotels
6.Hospitals
7.Laboratories

📈 Advantages
*Low Cost
*Easy Installation
*Remote Access
*Low Power Consumption
*User Friendly
*Expandable Architecture
*Reliable Communication

👨‍💻 Author

Sowmiyaraj K S

Bachelor of Engineering (EEE)

Embedded Systems Enthusiast

