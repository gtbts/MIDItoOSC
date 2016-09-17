#  MIDItoOSC plug-in
---
![MIDItoOSC](https://github.com/gtbts/MIDItoOSC/blob/master/screenshot.png)

## Overview

---
+ This virtual instruments convert **MIDI** to **[OSC (Open Sound Control)](http://opensoundcontrol.org/introduction-osc)** message.
+ The main purpose of this is to control **[mbed OSCtoCV Converter for Modular Synthesizer](https://developer.mbed.org/users/casiotone401/code/OSCtoCVConverter/)**.

## How it works.

---
The two text boxes bottom of the plug-in set target IP address & port, you can input target address, port number and press the return key to connect on a UDP socket.

When **Mono** button is off, **Polyphony** slider set max polyphony.
If **Polyphony** is set greater than 1 (Max 6) converts each MIDI note to OSC message with address **/fader1** ~ **/fader6** and argument **float** 0.0f ~ 1.0f, if **Polyphony** is 1 send to **/fader1** **/fader2** with the same value.

Likewise, convert MIDI Note ON/Off state to OSC message with address **/gate1** **/gate2** and argument **int** is 0 or 1, MIDI NoteON velocity, MIDI CC1 (Modulation Wheel) each value to OSC message with address **/fader7** **/fader8** and argument **float** 0.0f ~ 1.0f.

**Glide** slider set **[mbed OSCtoCV Converter](https://developer.mbed.org/users/casiotone401/code/OSCtoCVConverter/)** **_glide_** (portamento) value with address **/ctrl4** and argument **float**.

### Load Calibration Data

---
The **Load Calibration Data** button is load a **_calibration data_** text file. The **_calibration data_** are made with **[OSCtoCV Calibrator](https://github.com/gtbts/OSCtoCV-Calibrator)**.
If the calibration data have been successfully loaded, OSC **/fader1** ~ **/fader6** with **float** value is adjusted (quantized) musical scale and you can choose several scale from **Scale** combo box to change **[mbed OSC to CV Converter](https://developer.mbed.org/users/casiotone401/code/OSCtoCVConverter/)** quantize scale with address **/ctrl4**.

### Mono Mode

---
When **Mono** button is on, plug-in convert each received MIDI message channel 1 ~ 8 to OSC message with address **/fader1** ~ **/fader8** and convert each MIDI channel 1 ~ 4  NoteON/Off state to **/gate1** ~ **/gate4**

### Shift Mode

---
When **Shift** button is on, plug-in works like a shift-register. In **Shift Mode**, plug-in convert each MIDI note in order of arrival to OSC message with address **/fader1** ~ **/fader8** and shifted, data send with Note ON/Off timing.

### Requirements

---
+ **[The JUCE cross-platform C++ framework](https://www.juce.com/)**.
+ **[oscpack](http://www.rossbencina.com/code/oscpack)**

### License

---
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see http://www.gnu.org/licenses/.
