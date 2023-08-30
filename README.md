# Car Accident Detection using Arduino in Proteus

# Tools Required:
• Proteus 8 Professional (for virtual simulation)
• Arduino Uno (simulated in Proteus)
• Ultrasonic Sensor (HC-SR04 or similar)
• Relay Module
• Vibration Sensor
• Display Board
• GSM Module
• GPS Module

# Procedure:
• Setup in Proteus:
  1. Open Proteus and create a new project.
  2. Search and place Arduino Uno, Ultrasonic Sensor, Relay Module, Vibration Sensor, Display Board, GPS Module and GSM Module components from Proteus library.

• Connections:
  1. Ultrasonic Sensor to Arduino Uno:
     
    a. VCC to 5V pin.
    b. GND to GND pin.
    c. Trig to digital pin 2.
    d. Echo to digital pin 3.
    
  3. Relay Module to Arduino Uno:
     
    a. VCC to 5V pin.
    b. GND to GND pin.
    c. IN1 to digital pin 4.
    
  5. Vibration Sensor to Arduino Uno:

    a. VCC to 5V pin.
    b. GND to GND pin.
    c. Signal to digital pin 5.

  6. Display Board to Arduino Uno:

    a. VCC to 5V pin.
    b. GND to GND pin.
    c. SDA to SDA(A4) pin.
    d. SCL to SCL (A5) pin.

  7. GPS Module to Arduino uno:

    a. VCC to 5V pin.
    b. GND to GND pin.
    c. TX to digital pin 6 (RX).
    d. RX to digital pin 7(TX).

  8. GSM Module to Arduino Uno:

    a. VCC to 5V pin.
    b. GND to GND pin.
    c. TX to digital pin 8 (RX).
    d. RX to digital pin 9 (TX).

# Working:
1. The Ultrasonic Sensor measures the distance to an obstacle in front of it.
2. The Vibration Sensor detects any sudden impact or collision.
3. The Arduino continuously reads data from the Ultrasonic Sensor and the Vibration Sensor.
4. If the Ultrasonic Sensor detects an object closer than a threshold distance (indicating a potential collision), and the Vibration Sensor detects an impact, the Arduino triggers the Relay Module to simulate an accident detection.
5. Upon accident detection, the Arduino activates the GSM Module to send an emergency message with the GPS coordinates of the accident location to a pre-defined emergency contact number.

# Result:
Hence a car accident detection system using Arduino in Proteus is successfully created. In case of an accident, the system will send an emergency message with GPS coordinates to the designated emergency contact. 
