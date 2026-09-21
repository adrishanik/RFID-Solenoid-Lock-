# RFID-Solenoid-Lock-
An automated electronic access control system using a RFID scanner and solenoid locking system 
### What it does
- **Card-based unlocking:** Tap an authorized RFID tag or keyfob to trigger the latch.
- **Screen feedback:** A 16x2 LCD displays status messages like "Access Granted" or "Door Unlocked" so you know what's happening.
- **Relay-driven power:** Uses a relay to safely switch the higher power needed by the solenoid without frying the microcontroller.
- **Auto-relock:** The latch pulls back for a few seconds to let you open the door, then locks itself again automatically.

---

### Parts used
- Microcontroller board (ESP8266 / Arduino)
- RC522 RFID reader module + RFID keyfob/card
- 12V Solenoid door lock latch
- 5V Relay module
- 16x2 LCD display (with I2C backpack)
- 12V DC power source + 5V regulator/step-down
- Breadboard and jumper wires

---

### Problems I ran into & how I fixed them
- **Voltage drops and reboots:** When the 12V solenoid fired, it pulled a quick burst of power that caused the microcontroller to reset. I fixed this by separating the solenoid power rail from the logic board's power.
- **Wiring clutter & pin issues:** Getting the SPI pins for the RC522 reader and the I2C pins for the display to play nicely took some careful wiring and breadboard planning.
- **Lock timing:** Getting the latch open-duration right was tricky at first—keeping it open long enough to open the door, but not so long that the solenoid coil got hot.

---

### What I learned
- How to isolate and safely switch higher-voltage inductive loads using relays.
- Interfacing SPI devices (the RFID reader) alongside an I2C display.
- Troubleshooting power glitches in mixed-voltage embedded setups.
## Thumbnail 
<img width="720" height="369" alt="image" src="https://github.com/user-attachments/assets/57c05a9d-b5c0-431e-9227-751739349936" />
# Lisence 


MIT Lisence 
## Demo video link  

https://youtu.be/OTqfoC74szY?si=QAPdyNSwLQM4U7Er.    

