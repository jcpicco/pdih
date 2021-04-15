<h1><b><p align=center> PDIH: Seminario Arduino</p></b></h1>

## **1. Introducción a Arduino**

&nbsp;&nbsp;&nbsp;&nbsp;En este seminario hemos visto Arduino. Debido a la situación actual no nos ha sido posible adquirir prestado una placa Arduino, por lo que hemos usado programas de emulación de Arduino.

&nbsp;&nbsp;&nbsp;&nbsp;De entre las dos opciones que se nos han presentado he escogido usar TinkerCad, lo cual ya había utilizado antes de cursar PDIH, y había realizado un pequeño circuito con el. A continuación explicaré los dos programas del seminario y enseñaré el proyecto que realicé. 

## **2. Doble LED alternando**

&nbsp;&nbsp;&nbsp;&nbsp;Este programa es bastante sencillo. Consiste en dos leds que se alternan encendiéndose uno y otro. El circuito lo veremos a continuación:

![1](https://github.com/jcpicco/pdih/blob/main/S-arduino/capturas/1.png "1")

&nbsp;&nbsp;&nbsp;&nbsp;El código se divide en dos partes:

```cpp
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
}
```

&nbsp;&nbsp;&nbsp;&nbsp;En esta primera parte, en la función *setup()* se declaran los leds que vamos a utilizar. Al estar conectados a los puertos 11 y 13 y al ser un conector de salida, se declaran de esa manera. Ahora en la segunda parte se define su funcionamiento.

```cpp
void loop()
{
  digitalWrite(11, LOW);
  digitalWrite(13, HIGH);
  delay(500); // Wait for 500 millisecond(s)
  digitalWrite(13, LOW);
  digitalWrite(11, HIGH);
  delay(500); // Wait for 500 millisecond(s)
}
```

&nbsp;&nbsp;&nbsp;&nbsp;En la función *loop()* utilizamos *digitalWrite()* para alternar entre encendido y apagado con cada uno de los leds. Es un funcionamiento muy muy sencillo. Usamos *delay()* para definir un retardo de 500ms entre encendido y apagado.

&nbsp;&nbsp;&nbsp;&nbsp;Para ver su funcionamiento, en la carpeta S-arduino/pruebas puede encontrarlo con el nombre de *prueba-leds.mp4*. Puedes acceder al circuito haciendo [click aquí](https://www.tinkercad.com/things/75yZmUjsXVp-leds-alternos/).

## **2. Pulsador LED**

&nbsp;&nbsp;&nbsp;&nbsp;Este programa consiste en un led y un pulsador. Cuando clickas en el pulsador el led se enciende. El circuito es el siguiente:

![2](https://github.com/jcpicco/pdih/blob/main/S-arduino/capturas/2.png "2")

&nbsp;&nbsp;&nbsp;&nbsp;En el circuito el led está conectado de la misma manera que en el ejercicio anterior, y el pulsador requiere de conectarlo a la corriente de 5V para que funcione. Ambos están conectados a una resistencia de 220Ω para que no se quemen.

&nbsp;&nbsp;&nbsp;&nbsp;El código está dividido en dos partes distintas como el otro:

```cpp
int val;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(7, INPUT);
}
```

&nbsp;&nbsp;&nbsp;&nbsp;En esta primera parte declaramos la variable *val* que nos servirá para *loop()*. Luego declaramos el led como output y el pulsador como input.

```cpp
void loop()
{
  val=digitalRead(7);
  digitalWrite(13, val);
}
```

&nbsp;&nbsp;&nbsp;&nbsp;En la segunda parte en *loop()* leemos con *digitalRead()* el estado del pulsador contínuamente y lo almacenamos en la variable *val*. Si se activa se sobreescribirá su estado con *digitalWrite()*.

&nbsp;&nbsp;&nbsp;&nbsp;Para ver su funcionamiento, en la carpeta S-arduino/pruebas puede encontrarlo con el nombre de *prueba-pulsador.mp4*. Puedes acceder al circuito haciendo [click aquí](https://www.tinkercad.com/things/5dgxOEw2qEL-led-pulsador).

## **3. [EXTRA] Minijuego con Arduino**

&nbsp;&nbsp;&nbsp;&nbsp;Este trabajo lo realicé para la asignatura de EC como trabajo voluntario. El minijuego consiste en una tira circular de leds por la cual pasa una luz una y otra vez. Nuestro objetivo es clickar el pulsador en el momento en que este pase por el principio. Si ganamos sonará una canción con el zumbador. El circuito es el siguiente:

![3](https://github.com/jcpicco/pdih/blob/main/S-arduino/capturas/3.png "3")

&nbsp;&nbsp;&nbsp;&nbsp;Sobre el circuito no hay mucho que decír. Solamente que la rueda de leds está en el puerto 13, el pulsador en el 12 y el zumbador en el 11.

&nbsp;&nbsp;&nbsp;&nbsp;El código está dividido en varias partes:

```cpp
#include <Adafruit_NeoPixel.h>
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
...
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
```

&nbsp;&nbsp;&nbsp;&nbsp;En esta parte estamos incluyendo la librería que vamos a utilizar para que la rueda encienda los led que queramos, la cual es *Adafruit_NeoPixel.h*. También hemos declarado todas las notas distintas para el zumbador.

```cpp
Adafruit_NeoPixel NEOPIXEL = Adafruit_NeoPixel( 24, 13, NEO_GRB );
int melody[]={NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};
int buttonPin= 12;
int noteDurations[]={4, 8, 8, 4, 4, 4, 4, 4};
int state = 0;
int end = 0;
```

&nbsp;&nbsp;&nbsp;&nbsp;Aquí hemos declarado todas las variables. Se inicializa la rueda de leds, creamos tanto la melodía como la duración de cada nota en dos arrays distintos, dos booleanos que nos servirán más adelante y la variable *buttonPin*, la cual está ahí porque sí y no la quité sin darme cuenta durante la implementación, pero dentro del código no hace absolutamente nada.

```cpp
void set_pixel_color( Adafruit_NeoPixel &strip, int index, unsigned char red, unsigned char green, unsigned char blue, int brightness = 256 )
{
    strip.setPixelColor( index, ( ( (int) red ) * brightness ) >> 8, ( ( (int) green ) * brightness ) >> 8, ( ( (int) blue ) * brightness ) >> 8 );
}

void encenderTodo(){
  	set_pixel_color( NEOPIXEL, 0, 0, 255, 0, 256 );
  	set_pixel_color( NEOPIXEL, 1, 0, 255, 0, 256 );
  	set_pixel_color( NEOPIXEL, 2, 255, 0, 0, 256 );
  	set_pixel_color( NEOPIXEL, 3, 255, 0, 0, 256 );
    ...
  	set_pixel_color( NEOPIXEL, 21, 255, 0, 0, 256 );
  	set_pixel_color( NEOPIXEL, 22, 255, 0, 0, 256 );
  	set_pixel_color( NEOPIXEL, 23, 0, 255, 0, 256 );
    NEOPIXEL.show();
}

void apagarTodo(){
  	set_pixel_color( NEOPIXEL, 0, 0, 255, 0, 0 );
  	set_pixel_color( NEOPIXEL, 1, 0, 255, 0, 0 );
  	set_pixel_color( NEOPIXEL, 2, 255, 0, 0, 0 );
  	set_pixel_color( NEOPIXEL, 3, 255, 0, 0, 0 );
  	...
  	set_pixel_color( NEOPIXEL, 21, 255, 0, 0, 0 );
  	set_pixel_color( NEOPIXEL, 22, 255, 0, 0, 0 );
  	set_pixel_color( NEOPIXEL, 23, 0, 255, 0, 0 );
    NEOPIXEL.show();
}

void start()
{
    encenderTodo();
  	delay(1000);
  	apagarTodo();
  	delay(1000);
  	encenderTodo();
  	delay(1000);
  	apagarTodo();
  	delay(1000);
}
```

&nbsp;&nbsp;&nbsp;&nbsp;La función *set_pixel_color()* la saqué de internet y sirve para cambiarle el color a cada led de la rueda. Las funciones *encenderTodo()* y *apagarTodo()* encienden y apagan la rueda completa. Finalmente la función *start()* hace la animación del principio, la cual enciende y apaga todos los leds 2 veces mostrando qué leds son con los que ganas si los pulsas en el momento justo (color verde), y cuales no (color rojo).

```cpp
void setup()
{
    pinMode(12,INPUT);
  	pinMode(13,OUTPUT);
	NEOPIXEL.begin();
  	start();
}
```

&nbsp;&nbsp;&nbsp;&nbsp;En *setup()* se declaran como siempre los dispositivos conectados a la placa, y en este caso se realiza la animación de *start()*.

```cpp
void loop(){
  	if(state == 0){
        for(int i=0 ; i<24 ;i++){
            if(i==0)
                set_pixel_color( NEOPIXEL, 23, 255, 0, 0, 0 );
            if(i!=0)
                set_pixel_color( NEOPIXEL, i-1, 255, 0, 0, 0 );

            set_pixel_color( NEOPIXEL, i, 255, 0, 0, 256 );
            NEOPIXEL.show();
          
          	if(digitalRead(12)==HIGH){
              if(i==0 || i==23 || i==1){
                set_pixel_color( NEOPIXEL, i, 0, 255, 0, 256 );
  	  			NEOPIXEL.show();
              	state = 1;
                break;
              }
              else{
                start();
                break;
              }
            }
        }
    }
```

&nbsp;&nbsp;&nbsp;&nbsp;Si *state* sigue siendo 0 se hace el for, que lo que hace es ir moviendo la luz por toda la rueda completa, encendiendo y apagando leds. Si el pulsador se activa y se encuentra en la posición inicial o su anterior o su posterior, *state* se pone a 1 y se pasa a finalizar el juego. De lo contrario se reinicia el juego desde el principio.

```cpp
  	if(state == 1){
      if(end == 0){
        for (int thisNote=0; thisNote <9; thisNote++){
            int noteDuration = 1000 / noteDurations [thisNote];

            tone(11, melody [thisNote], noteDuration);

            int pauseBetweenNotes = noteDuration * 1.30;

            delay(pauseBetweenNotes);
            noTone(11);
        }
        end = 1;
      }
  	}
}
```

&nbsp;&nbsp;&nbsp;&nbsp;En este último paso el juego finaliza si *state* es 1, y suena la canción de fin del juego. Finalmente *end* se pone a 1 para que no siga en *loop()*.

&nbsp;&nbsp;&nbsp;&nbsp;Para ver su funcionamiento, en la carpeta S-arduino/pruebas puede encontrarlo con el nombre de *prueba-minijuego1.mp4* y *prueba-minijuego2.mp4*. Puedes acceder al circuito haciendo [click aquí](https://www.tinkercad.com/things/gaVzKDV09qe-practica-5).