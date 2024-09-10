---
size: 4:3
---

# \-------------------------------------------------------------
# Digital Music Workshop / 04 / Algorithmic Compositions Basics
# \-------------------------------------------------------------

---

# \-------------------------------------------------------------
# Digital Music Workshop / 04 / Algorithmic Compositions Basics
# \-------------------------------------------------------------

- prerequisites
- techniques

---

## \-------------
## prerequisites
## \-------------

a few common ( musical ) techniques that are useful in algoritmic compositions:

- sampler
- scale
- sequencer
- arpeggio

---

### \-------
### sampler
### \-------

a *sampler* can play back *pre-recorded* chunks of data:

see `Digital_Music_Workshop--02--Digital_Audio_Signal_Processing / Sampler`

---

### \-----
### scale
### \-----

a scale is a sequence of ordered musical notes. 

see `Digital_Music_Workshop--03--Music_Basics / Scales`

---

### \---------
### sequencer
### \---------

a sequencer can store and playback a series of values ( often muscial notes but also other properties ). a specific version of a sequencer is the *step sequencer* that is often triggered and *stepped* forward by a beat. 

- see `ExampleTechnique01Sequencer`
- see `AppSequenceRecorder` ( + [Quantization](https://en.wikipedia.org/wiki/Quantization_(music)) )

---

### \--------
### arpeggio
### \--------

an [arpeggio](https://en.wikipedia.org/wiki/Arpeggio) is a series of notes, often a broken down chord, that is played sequentially.

see `ExampleTechnique02Arpeggiator`

---

## \----------
## techniques
## \---------

a *cheat sheet* of some basic techniques for algorithmic composition:

- modulo
- loops
- visual model
- grammar
- functions

---

### \------
### modulo
### \------

modulo can be used to repeatedly trigger events.

- the [modulo](https://en.wikipedia.org/wiki/Modulo_operation) operation returns the remainder of a division
- notation for the module operation is the percentage sign: `%` 
- example ( "count from 0 to 3 repeatedly" ):
    - `0 % 4 == 0`
    - `1 % 4 == 1`
    - `2 % 4 == 2`
    - `3 % 4 == 3`
    - `4 % 4 == 0`
    - `5 % 4 == 1`
- see `AppAlgorithmicComposition00Modulo`

---

### \-----
### loops
### \-----

using loops of identical or similar structures to create complex emerging patterns and structures:

- see `AppAlgorithmicComposition01Loops`
- see [The Euclidean Algorithm Generates Traditional Musical Rhythms](http://cgm.cs.mcgill.ca/~godfried/publications/banff.pdf) ( "varying number of beats evenly distributed across a number of steps" )
- see [Steve Reich: Clapping Music](https://www.youtube.com/watch?v=lzkOFJMI5i8)

---

### \------------
### visual model
### \------------

using visual models to structure parameter manipulation or create a parameter space.

see `AppAlgorithmicComposition02VisualModel`

---

### \-------
### grammar
### \-------

developing a grammar to organize notes and other paramters.

see `AppAlgorithmicComposition03Grammar`

---

### \---------
### functions
### \---------

using mathematical functions to organize notes and pitches or generate waveforms directly.

- see `AppAlgorithmicComposition04FunctionSineWaves`
- see `AppAlgorithmicComposition05FunctionDSPFormula`

---

## \----------
## references
## \----------

see [Algorithmic Composition](https://en.wikipedia.org/wiki/Algorithmic_composition)
