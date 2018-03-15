# README

## Descrizione

Il repository contiene software e datasheet per l'hardware sviluppati durante le fasi di prototipazione per un sistema che impieghi sensori ottici per valutare presenza/assenza di ostacoli.

## Contenuti

Nel repository si trovano le seguenti sottocartelle:

* ```datasheet```
* ```Arduino_Code```:
* ```Arduino_libraries```:
* ```Processing_code```:

## Refernces and links

Test con sensore Pololu sds 01 a [link](https://www.pololu.com/product/1134). Il codice prodotto Pololu è 1134 e monta un sensore SHARP [GP2Y0D810Z0F](http://www.sharp-world.com/products/device/lineup/data/pdf/datasheet/gp2y0d810z_e.pdf). Eccone il [datasheet](http://www.sharp-world.com/products/device/lineup/data/pdf/datasheet/gp2y0d810z_e.pdf). Sembra essere disponibile anche da RobotItaly [codice prodotto 341134](https://www.robot-italy.com/it/1134-sensore-ir-digitale-10cm-pololu-con-sharp-gp2y0d810z0f.html).

### Break Beam

* da [Adafruit](https://www.adafruit.com/product/2168)
* da [Robot Italy](https://www.robot-italy.com/it/ir-break-beam-sensor-3mm-leds.html)

### Fork

Su RS ce ne sono di disponibili anche con larghezza tra emettitore e ricevitore >= 5mm (es, 8 o 9mm).

### Multiplexing

Mayhew [Mux shield](http://mayhewlabs.com/products/arduino-mux-shield). La scheda monta 3 IC texas Instruments 4067 che sono multiplexer/demultiplexer analogici da 16 canali l'uno. Questo significa che la singola scheda è in grado di gestire fino a 48 sensori analogici (o anche digitali) e impiega 3 Input analogici dell'Arduino e soli 4 pin digitali di Arduino per l'indirizzamento.

### Filtering

[link](https://www.megunolink.com/articles/3-methods-filter-noisy-arduino-measurements/)

### Others
* [https://learn.sparkfun.com/tutorials/qrd1114-optical-detector-hookup-guide]()
* [tutorial w/ a custom made IR reflective sensor](http://www.me.umn.edu/courses/me2011/arduino/technotes/irbeam/irbeam.html).
