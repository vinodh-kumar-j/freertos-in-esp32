# ESP32 FreeRTOS LED Blink + Serial Task Demo

This project demonstrates how to use **FreeRTOS** on an **ESP32** board with the Arduino framework.  
It creates two simple tasks that run in parallel to showcase the FreeRTOS scheduler and multitasking on a dual-core microcontroller.

---

## 📋 Features

- **Task 1:** Blinks an onboard LED every 500 ms.
- **Task 2:** Prints a message to the Serial Monitor every 500 ms.
- Uses `xTaskCreatePinnedToCore()` to pin tasks to a specific core.
- Demonstrates how FreeRTOS handles scheduling and time-slicing.

---

## 🧩 What I Learned

- Basics of the **FreeRTOS scheduler** and how it switches tasks.
- Key FreeRTOS functions:
  - `xTaskCreatePinnedToCore()` — create tasks on a specific core.
  - `vTaskDelay()` — suspend tasks without blocking other tasks.
- Difference between **FreeRTOS (RTOS)** and a **General-Purpose OS (GPOS)**:
  - RTOS = deterministic timing, predictable task execution.
  - GPOS = fairness and throughput, not strict real-time guarantees.

---

## 🔌 Hardware Used

- **Board:** ESP32 DevKit (or similar)
- **Onboard LED:** Pin 2 (adjust if your board uses a different pin)

---

## 🚀 How to Run

1. **Install ESP32 Board Support**  
   - Open Arduino IDE  
   - Tools → Board → Boards Manager → Install **ESP32 by Espressif Systems**

2. **Connect your ESP32** and select the correct port.

3. **Upload the sketch**

4. **Open the Serial Monitor** at `115200 baud` to see the second task printing messages.

5. **Watch the onboard LED blink** while the Serial output runs at the same time.

---
