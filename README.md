AI

### Requirements:

- #### Windows

  - Make sure WSL is installed

  - Run `./run.ps1`

  - To access server from other devices within local network, you need to change WSL port forward [this](https://learn.microsoft.com/en-us/windows/wsl/networking)      

- #### Mac

  - Make sure virtual env is installed, wget, unzip also required

  - Run **run.sh** file `chmod 755 ./run.sh ; sh ./run.sh`

  - Or Download model directly from [this](https://drive.google.com/drive/folders/1ZtWU8fJB8nI16NkN4mavjut6a5kPCNLl?usp=sharing) then extract inside root folder

### Run:

- Activate vitual env `./bin/activate`
- Run server `python3 -m flask  run --host=0.0.0.0` or `flask run --host=0.0.0.0`

IoT

# Source code to load hardware modules

## ESP8266

1. In the Arduino IDE, open Preferences (File > Preferences).
2. Add the following URL:

```
http://arduino.esp8266.com/stable/package_esp8266com_index.json
```

3. Click "OK" to save the settings and close the Preferences window.
4. Select the board as ESP8266 and select first item
5. Replace the wifi in the source code with yours
6. Load code to the board

## ESP32CAM

1. Select the board as AI thinker CAM
2. Replace the wifi and server addresses in the source code with yours
3. Load code to the board

## ARDUINO UNO R3

1. Select the board as Arudino Uno
2. Install Servo.h library in Arduino IDE
3. Load code to the board

Web Server
Project Topic: This project is a Spring Boot application that aims to classify garbage automatically by calling API to the AI server

- Requirement :
  Intellij,Apache Maven v3.0.5,Apache Tomcat v8.5

- To start this application,we need:
  First,clone this repository.
  Then,cd garbage-classifition.
  Finally,Write this line in terminal to run application: ./mvnw spring-boot:run
