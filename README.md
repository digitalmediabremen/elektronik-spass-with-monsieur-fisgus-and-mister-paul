# Elektronik-Spass with Monsieur Fisgus and Mister Paul

## Setup

1. install "esp32 by Espressif Systems" **(v2.0.17)** via `Tools > Board: "…" > Board Manager…` ( note, that this is **NOT** the most recent version )
2. select board at `Tools > Board > esp32 > ESP32 Dev Module`
3. select serial port at `Tools > Port: "…"` e.g `cu.usbserial-0001`
4. run example `File > Examples > 01.Basics > Blink` ( define `LED_BUILTIN` as pin `22` with `#define LED_BUILTIN 22` )
5. install libraries ( make sure to install the exact same version as specified ):
    1. manually by downloading the ZIP from:
        - [Arduino Audio Tools](https://github.com/pschatzmann/arduino-audio-tools) (v0.9.8) 
        - [Arduino Audio Driver](https://github.com/pschatzmann/arduino-audio-driver) (v0.1.0)
    2. via Arduino IDE i.e `Sketch > Include Library > Manage Libraries…`     
        - [Mozzi](https://github.com/sensorium/Mozzi) (v2.0.1)
        - [Bounce2](https://github.com/thomasfredericks/Bounce2) (v2.71)
        - [FastLED](https://github.com/FastLED/FastLED)(v3.7.6)
6. run example `File > Examples > audio-tools > examples-dsp > examples-mozzi > control_gain`
7. see [ESP32-Audio-kit Documentation](https://docs.ai-thinker.com/en/esp32-audio-kit) for more details

![](./assets/ESP32-audio-kit.webp)

*ESP-32 Audio Kit 2.2 with ESP32-A1S MCU incl. ES8388 Audio Codec*

## ESP-32 Audio Kit pinmap

| IO | USEABLE?                    | ADC | SPI/ I2C / UART | AUDIOKIT  | AUDIOKIT ALT. | 
| -- | --------------------------- | --- | --------------- | --------- | ------------- |
| 0  | low for flash mode          |  x  |                 |           | IO 0          |
| 1  | FTDI TX                     |     | UART0 TX        | TX        |               |
| 2  | low or float for flash mode |  x  |                 |           | SD DATA 0     |               
| 3  | FTDI RX                     |     | UART0 RX        | RX        |               |               
| 4  |                             |  x  | VSPI CS         |           | SD DATA 1     |               
| 5  | outputs PWM at boot         |     |                 | KEY 6     | IO 5          |               
| 12 | boot fail when high         |  x  | HSPI DI         |           | SD DATA 2     |               
| 13 |                             |  x  | HSPI DO         | KEY 2     | SD DATA 3     |               
| 14 |                             |  x  | HSPI CLK        |           | SD CLK        |               
| 15 |                             |  x  | HSPI CS         |           | SD CMD        |               
| 16 |                             |     | UART2 RX        | n.a.      |               |               
| 17 |                             |     | UART2 TX        | n.a.      |               |               
| 18 |                             |     | VSPI CLK        | KEY 5     | IO 18         |               
| 19 |                             |     | VSPI DO         | KEY 3     | IO 19 / LED D5| 
| 20 |                             |     |                 | n.a.      |               |               
| 21 |                             |     | I2C SDA         |           | IO 21         |               
| 22 |                             |     | I2C SCL         |           | IO 22 /LED D4 |
| 23 |                             |     | VSPI DI         | KEY 4     | IO 23         |
| 24 |                             |     |                 | n.a.      |               |
| 25 |                             |  x  |                 | I2S WS    |               |
| 26 |                             |  x  |                 | I2S DO    |               |
| 27 |                             |  x  |                 | I2S BCK   |               |
| 32 |                             |  x  |                 |           |               |
| 33 |                             |  x  |                 |           |               |
| 34 | input only                  |  x  |                 |           | SD DETECT     |
| 35 | input only                  |  x  |                 | I2S DI    |               |
| 36 | input only                  |  x  |                 | KEY 1     | KEY AD        |
| 39 | input only                  |  x  |                 | HP DETECT |               |

## basic operations input output
- LED
- buttons / switches 
- potentiometer / fader
- neopixel / adressable RGB LED 
- servo motor
- serial sensor I2C / SPI 
- capacitive touch 
