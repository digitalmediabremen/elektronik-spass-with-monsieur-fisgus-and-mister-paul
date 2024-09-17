---
size: 4:3
---

# \--------------------------------------------------
# Digital Music Workshop / 05 / Digital Audio on MCU
# \--------------------------------------------------

---

# \--------------------------------------------------
# Digital Music Workshop / 05 / Digital Audio on MCU
# \--------------------------------------------------

- small computation
- platforms + setups

---

## \-----------------
## small computation
## \-----------------

- Why make musik on a *Microcontroller Unit* (MCU)?
- if you don t feel it, don t do it. it s a lot of ( extra ) work. ( e.g Automatique Orchestra )
- programming audio on mcu has 2 main areas:
    - DSP
    - communication

---

### \---
### DSP
### \---

- from numbers to voltage and vice versa 
- *integer/fixed-point* versus *floating point*
- no floating-point units (FPU) not *floating point* @note( only *modern* MCU have them )

---

### \-------------
### communication
### \-------------

- e.g MIDI via Serial or USB
- MIDI controller or receiver

---

## \------------------
## platforms + setups
## \------------------

from *bare-metal* to *low-level* hardware. a series of typical platforms + setups:

- MCU + direct output
- MCU + resistor ladder
- MCU + external Digital-Analog Converter (DAC)
- MCU + internal DAC + Analog-Digital Converter (ADC)
- MCU + external DAC + ADC with *Inter-IC Sound* (I2S)
- MCU + external Audio Codec (CODEC) 

---

### \-------------------
### MCU + direct output
### \-------------------

- [Pulse-width modulation](https://en.wikipedia.org/wiki/Pulse-width_modulation) (PWM) + [Low-pass filter](https://en.wikipedia.org/wiki/Low-pass_filter) (LPF)
- e.g [Arduino Uno](https://store.arduino.cc/arduino-uno-rev3) ( Pin `3` with `analogWrite()` )
- usually setup needs an additional amplifier ( e.g Operational Amplifier (OpAmp) [LM386](https://en.wikipedia.org/wiki/LM386) )

---
 
### \---------------------
### MCU + resistor ladder
### \---------------------

- [Resistor ladder](https://en.wikipedia.org/wiki/Resistor_ladder) a series of resistors
- uses a lot of pins, but little overhead
- usually setup needs an additional amplifier

---

### \---------------------------------------------
### MCU + external Digital-Analog Converter (DAC)
### \---------------------------------------------

- dedicated Integrated Circuit (IC) with simple or no protocol
- smaller MCUs are sometimes challenged by audio rate
- e.g [Arduino Uno](https://store.arduino.cc/arduino-uno-rev3) + [MCP4912](https://ww1.microchip.com/downloads/en/DeviceDoc/22248a.pdf) ( SPI, 12BIT, mono )
- usually setup needs an additional amplifier

---

### \---------------------------------------------------
### MCU + internal DAC + Analog-Digital Converter (ADC)
### \---------------------------------------------------

- internal DAC e.g Teensy 3.2 ( Pin `A14` with `analogWrite()` )
- internal ADC e.g Teensy 3.2 ( Pin `A10` with `analogRead()` )
- usually setup needs an additional amplifier

---

### \--------------------------------------------------
### MCU + external DAC + ADC with *Inter-IC Sound* (I2S)
### \--------------------------------------------------

- [I2S](https://en.wikipedia.org/wiki/I²S) interface standard for digital audio devices
- @note(not to be confused with *I2C*)
- only available on *modern* MCUs ( e.g Teensy 3+, [ESP32](https://en.wikipedia.org/wiki/ESP32) )
- usually has built-in amplifier for headphones or line-out and sometimes has built-in amplifier for microphone + line-in

---

### \----------------------------------
### MCU + external Audio Codec (CODEC) 
### \----------------------------------

- CODEC external component ( or IC ), combination of ADC + DAC
- usually has built-in amplifier for headphones or line-out and sometimes has built-in amplifier for microphone + line-in
- e.g [Teensy 3.2](https://www.pjrc.com/store/teensy32.html) + [Audio Adaptor Board](https://www.pjrc.com/store/teensy3_audio.html) + [Audio Library](https://www.pjrc.com/teensy/td_libs_Audio.html)
- e.g [DAISY SEED](https://www.electro-smith.com/daisy/daisy)
- e.g @(TBR) e.g Klangstrom ( STM32 + WM8731 )
