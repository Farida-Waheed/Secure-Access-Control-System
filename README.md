# 🔐 Secure Access: Upgraded Password-Based Door Lock and Home Automation System

A dual-microcontroller secure access and home control system based on the 8051 microcontroller. This enhanced version upgrades the traditional password-protected door lock system by introducing **I²C communication** between two microcontrollers, enabling advanced functionality such as lighting and air conditioning control after secure access.
The Original Project [Password-Protected Door Lock System](https://github.com/Farida-Waheed/Password-Protected-Door-Lock-System)

---

## 🏫 Project Information

* **University:** Benha University, Faculty of Engineering (Shoubra)
* **Department:** Communications and Computer Engineering
* **Course:** Embedded Systems

---

## 👩‍💻 Team Members

* Farida Waheed Abdelbary
* Nourhan Farag Mohamed
* Malak Mounier Abdellatif
* Razan Ahmed Fawzy
* Nour Hesham Elsayed
* Lujain Ahmed Yousef
* Raneem Ahmed Refaat

---

## 📌 Project Overview

This project introduces a **dual-8051 microcontroller system** for a secure, password-based door lock combined with **smart home features**.

* **Microcontroller 1 (Door Unit):**

  * Manages password entry via keypad
  * Displays messages via LCD
  * Controls access using LEDs and buzzer
  * Sends access status over I²C

* **Microcontroller 2 (Home Unit):**

  * Manages lighting and AC controls
  * Displays room status on LCD
  * Responds to I²C signals to unlock home controls

---

## 🧠 System Features

| Feature              | Description                                            |
| -------------------- | ------------------------------------------------------ |
| 🔐 Password Entry    | 4-digit password required for access                   |
| 🔁 I²C Communication | Serial communication between Door and Home Units       |
| 📺 LCD Display       | Real-time system feedback                              |
| 🎛 Keypad            | 4x3 matrix keypad for input                            |
| 🔴🟢 LEDs            | Red for alert, green for access granted                |
| 🔊 Buzzer            | Activates on intrusion or error                        |
| 💡 AC/Light Control  | Controlled from the second microcontroller post-access |

---

## 🔌 Components & Connections

### 🔧 Door Unit (Microcontroller 1)

| Component      | 8051 Port/Pin | Function                 |
| -------------- | ------------- | ------------------------ |
| LCD RS         | P2.0          | LCD Register Select      |
| LCD RW         | P2.1          | LCD Read/Write           |
| LCD E          | P2.2          | LCD Enable               |
| LCD Data       | P3.0 - P3.7   | LCD Data                 |
| Keypad Rows    | P1.0 - P1.3   | Keypad Row Pins          |
| Keypad Columns | P1.4 - P1.7   | Keypad Column Pins       |
| Green LED      | P2.4          | Access Granted Indicator |
| Red LED        | P2.3          | Error/Intruder Indicator |
| Buzzer         | P0.0          | Sound Alert              |
| SDA/SCL        | P0.6, P0.7    | I²C Communication Lines  |

### 💡 Home Unit (Microcontroller 2)

| Component | 8051 Port/Pin | Function                    |
| --------- | ------------- | --------------------------- |
| LCD       | P1.0, P1.7    | Display Home Controls       |
| Buttons   | P3.2, P3.3    | Toggle AC and Lights        |
| LEDs      | P0.2, P0.     | White, Blue, Yellow, Orange |
| SDA/SCL   | P0.6, P0.7    | I²C Communication Lines     |

---

## ⚙️ How It Works

### Door Unit

1. Displays "Welcome Home".
2. Waits for 4-digit password input.
3. If password is **correct**:

   * Green LED ON
   * Displays "Open" then "Close"
   * Sends 'S' to the Home Unit via I²C
4. If password is **incorrect**:

   * Red LED + buzzer ON
   * Displays "Wrong Pass"
   * After 3 attempts: "Intruder Alert", system locks until reset

### Home Unit

1. Initially displays “Home - We’re Always Here”.
2. Waits for I²C message ('S').
3. If 'S' is received:

   * LCD updates to show control interface
   * Enables AC and lighting controls via buttons
4. Buttons toggle:

   * AC ON/OFF
   * Lighting modes (different LED combos)

---

## 🧠 Algorithm Flow

### 🔐 Door Unit

1. Initialize peripherals (LCD, keypad, LEDs, buzzer).
2. Wait for 4-digit password.
3. If correct → show access granted, send I²C signal.
4. If wrong → show alert, limit to 3 tries, trigger intruder alarm if exceeded.

### 💡 Home Unit

1. Wait for I²C 'S' signal.
2. On signal → activate LCD + button controls.
3. Toggle LEDs and AC based on user input.
4. Reset option available.

---

## 🧪 Testing Results

| Test Case                 | Expected Result                   | Passed |
| ------------------------- | --------------------------------- | ------ |
| Correct Password          | Door opens, Home Unit activates   | ✅      |
| Incorrect Password (x1)   | “Wrong Pass”                      | ✅      |
| Incorrect Password (x3)   | “Intruder Alert” + buzzer         | ✅      |
| I²C Signal Sent           | Home Unit displays control screen | ✅      |
| Button Press (AC / Light) | Toggle LEDs / AC on LCD           | ✅      |

---

## 💾 Source Files

* `main_door.a51`: Main code for Door Unit
* `main_home.a51`: Main code for Home Unit
* `i2c.asm`: I²C Master and Slave implementations
* `lcd.asm`, `keypad.asm`, `button.asm`, `leds.asm`, `buzzer.asm`, `delay.asm`: Support modules
* `.uvproj`, `.uvopt`, `.uvgui.*`: Keil project files
* `SecureAccess.pdsprj`: Proteus simulation project

---

## 🖼 Circuit Design

### 🧪 Simulation

![image](https://github.com/user-attachments/assets/1f4bfd00-921a-4c2c-a3ff-8c808c6220a9)
.

### 🔌 Real Hardware

![image](https://github.com/user-attachments/assets/33a558fe-cf14-4e51-9fec-8363b6ec4ac2)


---

## 🛠 Tools Used

* **Keil µVision** – Assembly development for 8051
* **Proteus** – Circuit simulation and testing
* **8051 Development Kits** – Real hardware testing
* **Bit-banged I²C** – Software-implemented communication

---

## 📷 Screenshots

* First Microcontroller Breadboard
  
![image](https://github.com/user-attachments/assets/24ff9ecc-ed45-40cd-88a1-b8d4e77f4c8b)
* Second Microcontroller Breadboard
  
![image](https://github.com/user-attachments/assets/d8dab038-6dff-4655-a477-0256966f3098)
* Serial Communication Breadboard
  
![image](https://github.com/user-attachments/assets/024de99a-b0e8-4a8a-ba5f-50e1cd283d98)


---

## 🔄 Improvements Over Original

| Feature               | Original Project | Upgraded Version |
| --------------------- | ---------------- | ---------------- |
| Password Protection   | ✅ Yes            | ✅ Yes            |
| LCD + Keypad          | ✅ Yes            | ✅ Yes            |
| Buzzer & LED Alert    | ✅ Yes            | ✅ Yes            |
| I²C Communication     | ❌ No             | ✅ Yes            |
| Dual Microcontrollers | ❌ No             | ✅ Yes            |
| Home Automation       | ❌ No             | ✅ Yes            |
| AC & Light Control    | ❌ No             | ✅ Yes            |

---

## 💡 Future Enhancements

* Store and change passwords dynamically
* Add real-time clock for timed automation
* Add sensors (e.g. temperature or motion)
* Mobile app control via Bluetooth or Wi-Fi

---

Let me know if you'd like me to export this as a `.md` file or want help adding screenshots, schematics, or links!
