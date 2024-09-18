#include <Arduino.h>
#define DECODE_DISTANCE_WIDTH
#include <IRremote.hpp>

#include "AudioTools.h"
#include "AudioLibs/AudioBoardStream.h"
#include "AudioLibs/MozziStream.h"
#include <Oscil.h>
#include <tables/sin2048_int8.h>

const int sample_rate = 16384;
AudioInfo info(sample_rate, 1, 16);
AudioBoardStream i2s(AudioKitEs8388V1);  // audio sink
MozziStream mozzi;                       // audio source
StreamCopy copier(i2s, mozzi);           // copy source to sink
Oscil<SIN2048_NUM_CELLS, sample_rate> aSin(SIN2048_DATA);
byte gain = 0;

uint32_t control_frame_counter = 0;
bool led1_state = false;
constexpr int LED_1 = 19;
constexpr int LED_2 = 22;

constexpr uint16_t BOB_SPEAKER_A = 0x3CC3;
constexpr uint16_t BOB_SPEAKER_B = 0x3EC1;

constexpr uint16_t BOB_LIGHT_A = 0x5CA3;
constexpr uint16_t BOB_LIGHT_B = 0x5EA1;

constexpr uint16_t BOB_LEVER_UP_A = 0x748B;
constexpr uint16_t BOB_LEVER_NEUTRAL_A = 0x7887;
constexpr uint16_t BOB_LEVER_DOWN_A = 0x6C93;

constexpr uint16_t BOB_LEVER_UP_B = 0x7689;
constexpr uint16_t BOB_LEVER_NEUTRAL_B = 0x7A85;
constexpr uint16_t BOB_LEVER_DOWN_B = 0x6E91;

constexpr uint8_t IR_RECEIVE_PIN = 5;

struct LED_info {
  bool state;
  int pin;
  LED_info(int p)
    : state(false), pin(p) {}
};

LED_info led1(19);
LED_info led2(22);

void setup_audio_codec() {
  auto cfg = mozzi.defaultConfig();
  cfg.control_rate = CONTROL_RATE;
  cfg.copyFrom(info);
  mozzi.begin(cfg);

  auto out_cfg = i2s.defaultConfig();
  out_cfg.copyFrom(info);
  i2s.begin(out_cfg);
}

void setup_led(LED_info& led) {
  pinMode(led.pin, OUTPUT);
}

void setup_leds() {
  setup_led(led1);
  setup_led(led2);
}

void setup() {
  Serial.begin(115200);

  IrReceiver.begin(IR_RECEIVE_PIN, DISABLE_LED_FEEDBACK);

  setup_audio_codec();
  setup_leds();

  aSin.setFreq(3320);
}

void handle_decoded_IRData(int hexval) {
  switch (hexval) {
    case BOB_SPEAKER_A:
      Serial.println("SPEAKER_A");
      gain = 255;
      aSin.setFreq(3320);
      break;
    case BOB_SPEAKER_B:
      gain = 255;
      aSin.setFreq(3320 / 3);
      break;
    default:
      /* print unrecognized value */
      Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
  }
}

void loop() {
  copier.copy();

  if (IrReceiver.decode()) {
    if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
      IrReceiver.resume();
    } else {
      handle_decoded_IRData(IrReceiver.decodedIRData.decodedRawData);
      IrReceiver.resume();
    }
  }
}

void toggleLED(LED_info& led) {
  led.state = !led.state;
  digitalWrite(led.pin, led.state);
}

void updateControl() {
  if (gain > 4) {
    gain = gain - 3;
  }

  control_frame_counter++;
  if (control_frame_counter % 16 == 0) {
    toggleLED(led1);
    toggleLED(led2);
  }
}

AudioOutputMozzi updateAudio() {
  return (aSin.next() * gain) >> 8;  // shift back to STANDARD audio range, like /256 but faster
}