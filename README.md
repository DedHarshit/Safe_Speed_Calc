# 📟 Keypad Configuration – Arduino Safe Speed Calculator

## 🔧 Overview

This project uses a **4x4 matrix keypad** to take user input for calculating the safe driving speed on an inclined road. The keypad allows the user to input numerical values for:

* Radius of curvature
* Angle of inclination
* Coefficient of friction
* Vehicle speed

---

## 🔢 Keypad Layout

The 4x4 keypad consists of the following keys:

```
1   2   3   A
4   5   6   B
7   8   9   C
*   0   #   D
```

---

## 🎮 Key Functions

| Key | Function                                |
| --- | --------------------------------------- |
| 0–9 | Numeric input                           |
| #   | Confirm / Enter value                   |
| *   | Clear current input                     |
| A–D | Not used (reserved for future features) |

---

## 🔌 Pin Configuration

The keypad is connected to the Arduino using 8 pins:

### Rows → Analog Pins

* R1 → A0
* R2 → A1
* R3 → A2
* R4 → A3

### Columns → Analog + Digital Pins

* C1 → A4
* C2 → A5
* C3 → D8
* C4 → D9

---

## ⚙️ Working Principle

The keypad operates as a **matrix input device**:

* Rows and columns form a grid
* When a key is pressed, it connects a specific row and column
* The Arduino scans the matrix to detect which key is pressed

---

## 🔢 Input Method

Since the keypad does not include a decimal point:

* Friction values are entered as integers (e.g., `5`)
* The program internally converts them:

  ```
  μ = input / 10
  ```

### Example:

* Input: `5` → Actual value: `0.5`

---

## 🧠 Integration with Code

The keypad is handled using the `Keypad.h` library:

* Detects key presses
* Stores input as a string
* Converts input to numerical values using `toFloat()`

---

## ⚠️ Limitations

* No decimal (.) key available
* Limited to numeric input only
* Special keys (A–D) currently unused
* No use of sensors for real time calculation

---

## 🚀 Future Improvements

* Use `*` as decimal input
* Assign A–D keys for advanced controls (reset, mode selection, etc.)
* Add input validation for better accuracy
* Use of sensors for real time calculation
---

