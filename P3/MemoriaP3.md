<h1><b><p align=center> PDIH: Práctica 3: Arduino</p></b></h1>

## **1. Introducción a la práctica**

&nbsp;&nbsp;&nbsp;&nbsp;En el seminario anterior hemos visto Arduino. Debido a la situación actual no nos ha sido posible adquirir prestado una placa Arduino, por lo que hemos usado programas de emulación de Arduino.

&nbsp;&nbsp;&nbsp;&nbsp;De entre las dos opciones que se nos han presentado he escogido usar TinkerCad, lo cual ya había utilizado antes de cursar PDIH y me he familiarizado bien con el. En esta práctica voy a mostraros 4 circuitos distinto con su código correspondiente explicado, y os dejaré un enlace para poder ver su funcionamiento en un video que he grabado, así como el enlace para observarlo personalmente.

## **2. Tres LEDs alternando**

&nbsp;&nbsp;&nbsp;&nbsp;Este programa es bastante sencillo. Consiste en tres leds de colores distintos que se alternan encendiéndose de uno en uno en un intervalo de 1500ms. El circuito lo veremos a continuación:

![1](https://github.com/jcpicco/pdih/blob/main/P3/capturas/1.png "1")

&nbsp;&nbsp;&nbsp;&nbsp;El led rojo está conectado al puerto 13, el amarillo al 12 y el verde al 11. Se requiere de una resistencia para que no se queme el led. El otro cable del led está conectado a tierra.

&nbsp;&nbsp;&nbsp;&nbsp;El código es el siguiente:

```cpp
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  delay(1500); // Wait for 1500 millisecond(s)
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  delay(1500); // Wait for 1500 millisecond(s)
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  delay(1500); // Wait for 1500 millisecond(s)
}
```

&nbsp;&nbsp;&nbsp;&nbsp;Primero se inicializan los tres led como *OUTPUT*. Luego se usa *digitalWrite()* para alternar entre *HIGH* y *LOW* cada 1500ms (función *delay()*). En cada momento antes del intervalo se enciende uno y se apagan los otros.

&nbsp;&nbsp;&nbsp;&nbsp;Para ver su funcionamiento, en la carpeta P3/pruebas puede encontrarlo con el nombre de *prueba-tres-leds.mp4*. Puedes acceder al circuito haciendo [click aquí](https://www.tinkercad.com/things/eoT6L18xGm3-tres-leds-alternos/).

## **3. Pulsador de LED rojo**

&nbsp;&nbsp;&nbsp;&nbsp;Este consiste en el mismo circuito de antes, solamente que como estado inicial los leds amarillos y verdes están encendidos, y cuando toquemos el pulsador se apagarán y se encenderá el rojo. El circuito es el siguiente:

![2](https://github.com/jcpicco/pdih/blob/main/P3/capturas/2.png "2")

&nbsp;&nbsp;&nbsp;&nbsp;Lo único que hay que explicar nuevo es que el pulsador está conectado a la entrada 7 y requiere de una corriente constante de 5V. También está conectado a tierra.

&nbsp;&nbsp;&nbsp;&nbsp;El código Lo divido en dos partes:

```cpp
int val;

void initialState(){
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
}

void finalState(){
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
}
```

&nbsp;&nbsp;&nbsp;&nbsp;Declaramos la variable *val* para después. Las funciones son *initialState()*, que enciende los leds amarillo y verde, y *finalState()*, que enciende el rojo y apaga los demás.

```cpp
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(7, INPUT);
}

void loop()
{
  val=digitalRead(7);
  
  if(val==LOW){
    initialState();
  }else{
    finalState();
  }
}
```

&nbsp;&nbsp;&nbsp;&nbsp;En *setup()* se inicializan los leds en *OUTPUT* y el pulsador en *INPUT*. En *loop()* leemos con *digitalRead()* el estado del pulsador, y lo almacenamos en *val*. Si *val* está sin pulsar se queda en *initialState()*, y si no se pasa a *finalState()*.

&nbsp;&nbsp;&nbsp;&nbsp;Para ver su funcionamiento, en la carpeta P3/pruebas puede encontrarlo con el nombre de *prueba-pulsador-leds.mp4*. Puedes acceder al circuito haciendo [click aquí](https://www.tinkercad.com/things/bCIVbMnbCZH-led-rojo-boton/).

## **4. Luces del coche fantástico**

&nbsp;&nbsp;&nbsp;&nbsp;El circuito siguiente consiste en 4 leds que hagan la animación de las luces del coche fantástico. Para cambiar un poco he usado una tira de LEDs y no uno por uno. Utilizo la librería NeoPixel para controlarlos. El circuito es el siguiente:

![3](https://github.com/jcpicco/pdih/blob/main/P3/capturas/3.png "3")

&nbsp;&nbsp;&nbsp;&nbsp;La tira se conecta a la entrada 13. Está a su vez conectada a la corriente de 5V y a tierra. No requiere de resistencias para su correcto funcionamiento.

&nbsp;&nbsp;&nbsp;&nbsp;El código Lo divido en dos partes:

```cpp
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel NEOPIXEL = Adafruit_NeoPixel( 4, 13, NEO_GRB );


void set_pixel_color( Adafruit_NeoPixel &strip, int index, unsigned char red, unsigned char green, unsigned char blue, int brightness = 256 )
{
	strip.setPixelColor( index, ( ( (int) red ) * brightness ) >> 8, ( ( (int) green ) * brightness ) >> 8, ( ( (int) blue ) * brightness ) >> 8 );
}

void start(){
	set_pixel_color( NEOPIXEL, 0, 255, 0, 0, 256 );
	set_pixel_color( NEOPIXEL, 1, 255, 0, 0, 256 );
	set_pixel_color( NEOPIXEL, 2, 255, 0, 0, 256 );
	set_pixel_color( NEOPIXEL, 3, 255, 0, 0, 256 );
  	NEOPIXEL.show();
  	delay(500);
	set_pixel_color( NEOPIXEL, 0, 255, 0, 0, 0 );
	set_pixel_color( NEOPIXEL, 1, 255, 0, 0, 0 );
	set_pixel_color( NEOPIXEL, 2, 255, 0, 0, 0 );
	set_pixel_color( NEOPIXEL, 3, 255, 0, 0, 0 );
  	NEOPIXEL.show();
  	delay(500);
}
```

&nbsp;&nbsp;&nbsp;&nbsp;Declaramos la librería *Adafruit_NeoPixel.h* para que funcione la tira led, y se declara el objeto *NEOPIXEL* para inicializarlo. Luego he reciclado de una práctica de TinkerCad que había hecho ya (explicada en el Seminario de Arduino) la función *set_pixel_color()* para cambiar de color los leds de la tira. Finalmente he creado la función *start()*, la cual hace una animación de parpadeo en rojo para probar los leds.

```cpp
void setup()
{
	NEOPIXEL.begin();
	start();
  start();
} 

void loop()
{
	for(int i=0 ; i<4 ;i++){
		if(i==0)
			set_pixel_color( NEOPIXEL, 3, 255, 0, 0, 0 );
    if(i!=0)
      set_pixel_color( NEOPIXEL, i-1, 255, 0, 0, 0 );

        set_pixel_color( NEOPIXEL, i, 255, 0, 0, 256 );
        NEOPIXEL.show();
      delay(200);
    }
  	for(int i=3 ; i>=0 ;i--){
		if(i==3)
			set_pixel_color( NEOPIXEL, 0, 255, 0, 0, 0 );
    if(i!=3)
      set_pixel_color( NEOPIXEL, i+1, 255, 0, 0, 0 );

        set_pixel_color( NEOPIXEL, i, 255, 0, 0, 256 );
        NEOPIXEL.show();
      delay(200);
    }
}
```

&nbsp;&nbsp;&nbsp;&nbsp;En *setup()* se inicia la tira de leds con *NEOPIXEL.begin()* y se llama a *start()* dos veces. En *loop()* tengo dos bucles. El primero hace un *for* que primero checkea si *i* es el primer led. Si lo es apaga el tercer led, y si no se apaga el led anterior al actual. Luego enciende el led actual y refresca con *NEOPIXEL.show()*, ejecutando un *delay()* de 200ms. El segundo bucle es como este pero en la dirección contraria, para que se cree un efecto rebote de un lado a otro.

&nbsp;&nbsp;&nbsp;&nbsp;Para ver su funcionamiento, en la carpeta P3/pruebas puede encontrarlo con el nombre de *prueba-coche-fantastico.mp4*. Puedes acceder al circuito haciendo [click aquí](https://www.tinkercad.com/things/dQeU45FUduh-coche-fantastico/).

## **4. Sensor de movimiento**

&nbsp;&nbsp;&nbsp;&nbsp;Este apartado consiste en un detector de movimiento con un sensor PIR. Cuando este detecta movimiento un led rojo enciende y en la consola aparece el mensaje "Sensor activado!". Cuando no hay más movimiento se apaga el led y deja de imprimirse el mensaje. El circuitom es este:

![4](https://github.com/jcpicco/pdih/blob/main/P3/capturas/4.png "4")

&nbsp;&nbsp;&nbsp;&nbsp;El led se conecta de la misma manera que los de los ejercicios anteriores, y en el puerto 13. El sensor está en el puerto 2 y a su vez está conectado a tierra y a la corriente de 5V.

&nbsp;&nbsp;&nbsp;&nbsp;El código es el siguiente:

```cpp
int val;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop()
{
  val = digitalRead(2);
  digitalWrite(13, val);
  
  if(val==HIGH){
  	Serial.println("Sensor activado!");
  }
  
  delay(1000);
}
```

&nbsp;&nbsp;&nbsp;&nbsp;Como véis es muy sencillo. Se declara la variable val y en *setup()* se declara el led como *OUTPUT* y el sensor como *INPUT*. *Serial.begin()* sirve para marcar la velocidad de envío de información en bits por segundo del dispositivo. Lo hemos puesto a 9600. Luego en *loop()* leemos el sensor con *digitalRead()* y lo almacenamos en *val*. Si el sensor se activa se escribe en la consola el mensaje "Sensor activado!" con *Serial.println()*. He añadido un *delay()* de 1000ms para que no se sature el dispositivo.

&nbsp;&nbsp;&nbsp;&nbsp;Para ver su funcionamiento, en la carpeta P3/pruebas puede encontrarlo con el nombre de *prueba-sensor-movimiento.mp4*. Puedes acceder al circuito haciendo [click aquí](https://www.tinkercad.com/things/erDfxjlj25g-sensor-movimiento/).