---
size: 4:3
---

# \-------------------------------------------------------------
# Digital Music Workshop / 02 / Digital Audio Signal Processing
# \-------------------------------------------------------------

---

# \-------------------------------------------------------------
# Digital Music Workshop / 02 / Digital Audio Signal Processing
# \-------------------------------------------------------------

- writing the audio buffer
- noise
- amplification
- sampler
- oscillator
- echo

---

## \------------------------
## writing the audio buffer
## \------------------------

- blocks of *sample data* are requested by the *audio system*
- application has to writes values to the block
- value range: `FLOAT(-1.0, 1.0)`

---

## \------------------------
## writing the audio buffer
## \------------------------

- block size defines the *latency* ( small block == low latency )
- e.g update rate: `44100 Hz / 512 BLOCKSIZE ≈ 86 Hz`

---

## \-----
## noise
## \-----

*noise* is produced by generating random values:

```
mSample = noise(-1.0, 1.0f);
```

---

## \-------------
## amplification
## \-------------

*amplification* is achieved by multiplying sample values with an *amplification factor*:

```
float mAmplification = 2.0f;
mSample = mSample * mAmplification;
```

- *amplification factor* greater than `1.0` increases the volume
- *amplification factor* smaller than `1.0` and greater than `0.0` decreases volume
- *amplification factor* smaller than `0.0` invertes the signal

---

## \-------
## sampler
## \-------

a *sampler* can play back *pre-recorded* chunks of data:

```
float[] mSampleData = { 0.1f, -0.56f, 0.44f, 0.16f, … }
mSample = mSampleData[i];
```

---

## \-------
## sampler
## \-------

sample data can be exported as *raw* data from other applications ( i.e *Audacity* ).

note, that files are usually stored in `byte` format, i.e 4 bytes are combined into a single `float` sample value ( see `Sampler.load(byte[])` and `Sampler.bytesToFloat32(byte[])` ).

if the sampler produces weird sounds the [endianess](https://en.wikipedia.org/wiki/Endianness) might be wrong ( see `Sampler.bytesToFloat32(byte[], boolean)` ).

see `ExampleDSP07Sampler`

---

## \----------
## oscillator
## \----------

oscillators can be produced by creating alternating values from functions:

```
mSample = sin(r);
```

see `ExampleBasics04DigitalSignalProcessing`

---

## \----
## echo
## \----

an echo ( or delay ) can be created by buffering sample data and adding it back into newer samples.

see `SketchExampleDSP03Echo`

---

## \----------
## references
## \----------

- [Musicdsp.org](https://www.musicdsp.org)
- [VCV Rack Manual / DSP](https://vcvrack.com/manual/DSP)
- [More Awesome Music DSP*](https://github.com/olilarkin/awesome-musicdsp)