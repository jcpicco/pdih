<h1><b><p align=center> PDIH: Práctica 5</p></b></h1>

## **1. Introducción a R Studio**

&nbsp;&nbsp;&nbsp;&nbsp;Esta práctica está enfocada a visualizar las señales de sonido, conocer la información que nos aporta un archivo de sonido, y ajustar parámetros de los archivos con R Studio.

&nbsp;&nbsp;&nbsp;&nbsp;Usaremos las librerías TuneR y SeeWave para la modificación de los archivos de sonido y la creación de nuevos. Para instalarlos se usan las siguientes funciones:

```R
install.packages('tuneR', dep=TRUE)
install.packages('seewave', dep=TRUE)
```

&nbsp;&nbsp;&nbsp;&nbsp;A continuación explicaré los ejercicios hechos y mostraré el código:

## **2. Ejercicios propuestos**

&nbsp;&nbsp;&nbsp;&nbsp;Antes de empezar con los ejercicios he incluido las librerías necesarias y he cambiado el directorio de trabajo:

```R
library(tuneR)
library(seewave)
library(audio)
setwd("~/pdih-temp/entrega")
```

1. **Leer dos ficheros de sonido (WAV o MP3) de unos pocos segundos de duración cada uno**

```R
#Ejercicio 1
perro <- readWave('perro.wav')
oveja <- readWave('oveja.wav')
#listen(perro)
#listen(oveja)
```

&nbsp;&nbsp;&nbsp;&nbsp;Se leen los archivos .wav y se almacenan en una variable. He añadido la función *listen()* para comprobar que se han almacenado. Aquí se visualizan las variables:

![1](https://github.com/jcpicco/pdih/blob/main/P5/capturas/ejer1.png "1")

2. **Dibujar la forma de onda de ambos sonidos**

```R
#Ejercicio 2
plot(perro)
plot(oveja)
```

![2](https://github.com/jcpicco/pdih/blob/main/P5/capturas/plot-perro.png "2")

![3](https://github.com/jcpicco/pdih/blob/main/P5/capturas/plot-oveja.png "3")

3. **Obtener la información de las cabeceras de ambos sonidos**

&nbsp;&nbsp;&nbsp;&nbsp;Para esto he utilizado el programa HxD para Windows, el cual me permite inspeccionar el código hexadecimal del archivo.

![4](https://github.com/jcpicco/pdih/blob/main/P5/capturas/hex-perro.png "4")

![5](https://github.com/jcpicco/pdih/blob/main/P5/capturas/hex-oveja.png "5")

&nbsp;&nbsp;&nbsp;&nbsp;Tras las instrucciones que saqué del propio PDF del Seminario, saqué las siguientes tablas con la información de las cabeceras:

![6](https://github.com/jcpicco/pdih/blob/main/P5/capturas/cabecera-perro.png "6")

![7](https://github.com/jcpicco/pdih/blob/main/P5/capturas/cabecera-oveja.png "7")

4. **Unir ambos sonidos en uno nuevo**

```R
#Ejercicio 4
oveja44100 <- resamp(oveja, f=8000, g=44100, output="Wave")
nuevo <- pastew(perro, oveja44100, output="Wave")
#listen(nuevo)
```

&nbsp;&nbsp;&nbsp;&nbsp;Para unir los dos sonidos he tenido que igualar la frecuencia de los dos audios, y decidí aumentarsela a *oveja.wav* con la función *resamp()* (de 8000 Hz a 44100 Hz). Finalmente he hecho la función *pastew()* para juntar los dos audios, adjuntando *oveja44100* al final de *perro*.

5. **Dibujar la forma de onda de la señal resultante**

```R
#Ejercicio 5
plot(nuevo)
```

![8](https://github.com/jcpicco/pdih/blob/main/P5/capturas/plot-ejer5.png "8")

6. **Pasarle un filtro de frecuencia para eliminar las frecuencias entre 10000Hz y 20000Hz**

```R
#Ejercicio 6
mezcla <- bwfilter(nuevo, channel=1, n=1, from=10000,
         to=20000, bandpass=TRUE, listen = FALSE, output = "Wave")
#listen(mezcla)
```

&nbsp;&nbsp;&nbsp;&nbsp;He usado la función *bwfilter()* para filtrar las frecuencias entre 10000 Hz y 20000 Hz. Se especifica la variable *nuevo*, que es la resultante del ejercicio 4 (la frecuencia no hace falta especificarla, ya que viene interna en el archivo), el mínimo y máximo de frecuencia, y el canal 1 (left), además de otros parámetros que no tocaremos. Todo esto se le asigna a la variable mezcla.

7. **Almacenar la señal obtenida como un fichero WAV denominado “mezcla.wav”**

```R
#Ejercicio 7
writeWave(mezcla, file.path("output/mezcla.wav"), extensible = TRUE)
```

![9](https://github.com/jcpicco/pdih/blob/main/P5/capturas/ejer7.png "9")

8. **Cargar un nuevo archivo de sonido, aplicarle eco y a continuación darle la vuelta al sonido. Almacenar la señal obtenida como un fichero WAV denominado “alreves.wav”.**

```R
#Ejercicio 8
guitar <- readWave('guitar.wav')
guitarCUT <- cutw(guitar, from=0.0,to=2.0, output="Wave")
guitarECO <- echo(guitarCUT,amp=c(0.8,0.4,0.2),delay=c(1,2,3), output="Wave")
guitarECO@left <- 10000 * guitarECO@left
alreves <- revw(guitarECO, output="Wave")
plot(alreves)
#listen(alreves)
writeWave(alreves, file.path("output/alreves.wav"), extensible = TRUE)
```

&nbsp;&nbsp;&nbsp;&nbsp;Descargué un sonido de guitarra .wav en una página de sonidos libre de Copyright. La leo con *readWave()* y lo recorto con *cutw()* desde el segundo 0 al segundo 2. Le añadí eco con la función *echo()* a la cual se le especifica la variable, la amplitud (decreciente), y en qué segundos comienza el eco.

&nbsp;&nbsp;&nbsp;&nbsp;He ampliado las muestras a la fuerza multiplicando *guitarECO@left* por 10000, ya que si no por alguna razón no sonaba absolutamente nada. Finalmente con *revw()* le he dado la vuelta y almacenado la variable *alreves*. Finalmente muestro el plot con *plot()* y con *writewave()* he guardado el archivo en la carpeta *output*.

![10](https://github.com/jcpicco/pdih/blob/main/P5/capturas/plot-alreves.png "10")