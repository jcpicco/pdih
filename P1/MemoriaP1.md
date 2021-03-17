<h1><b><p align=center> PDIH: Práctica 1</p></b></h1>

## **1. Introducción**

&nbsp;&nbsp;&nbsp;&nbsp;En esta práctica se nos pide implementar en C un conjunto de funciones similares a la de la biblioteca *conio.lib*.

&nbsp;&nbsp;&nbsp;&nbsp;Al principio de la práctica la enfoqué de manera que fuera todo como una librería más, pero dado que no he encontrado la manera de hacerla funcionar en Borland C, decidí meter todo en el fichero de test *P1.C*. Aún así he creado la librería y he documentado con la nomenclatura de Doxygen cada una de las funciones, y lo puedes encontrar en los ficheros *funciones.c* y *funciones.h*.

## **2. Funciones y consideraciones**

&nbsp;&nbsp;&nbsp;&nbsp;El comienzo del programa es la declaración de las librerías que vamos a utilizar (*stdio.h* y *dos.h*), y las dos variables globales necesarias:

```C
#include <stdio.h>
#include <dos.h>

unsigned char TEXTCOLOR = 7;
unsigned char BGCOLOR = 0;
```

&nbsp;&nbsp;&nbsp;&nbsp;La variable TEXTCOLOR marca el color original de texto de la ventana de DOSBox (gris claro), y la variable BGCOLOR es el color de fondo de la ventana (negro).

&nbsp;&nbsp;&nbsp;&nbsp;Cada interrupción se realiza con la función *int86*, y el modo es especificado en *inregs.h.ah*. Ahora procederé a explicar cada una de las funciones:

1. **void mi_pausa():** Realiza una pausa. Usa la interrupción 0x21 en modo 0x08.

2. **void gotoxy(int fil, int col):** Mueve el puntero a la zona de la pantalla que uno quiera. Usa la interrupción 0x10 en modo 0x02. Tiene los siguientes argumentos:
   + **int fil:** Indica la fila en la que colocamos el cursor.
   + **int col:** Indica la columna en la que colocamos el cursor.

3. **void setcursortype(int tipo_cursor):** Cambia el tipo de cursor entre tres tipos distintos: invisible(0), normal(1) o grueso(2). Usa la interrupción 0x10 en modo 0x01.

4. **void setvideomode(unsigned char modo):** Cambia el modo de video. Usa la interrupción 0x10 en modo 0x00. Tiene los siguientes argumentos:
   + **unsigned char modo:** Indica el modo de video. La lista de modos de video se encuentra en el siguiente enlace: https://es.wikipedia.org/wiki/Int_10h

5. **int getvideomode():** Devuelve el modo de video actual en formato int. Usa la interrupción 0x10 en modo 0x0F.

6. **revertcolor():** Revierte a los colores por defecto para los caracteres. Esta función es complementaria, ya que no la pide en ningún sitio. Devuelve los valores de TEXTCOLOR y BGCOLOR a su estado original (7 y 0, respectivamente).

7. **void textcolor(unsigned char color):** Cambia el color de primer plano en el que se mostrarán los caracteres. Se altera la variable global TEXTCOLOR. Tiene los siguientes argumentos:
   + **unsigned char color:** Indica el color al que queremos cambiar. En el enlace adjunto está la lista de colores: https://en.wikipedia.org/wiki/BIOS_color_attributes

8. **void textbackground(unsigned char color):** Cambia el color de fondo en el que se mostrarán los caracteres. Se altera la variable global BGCOLOR. Tiene los siguientes argumentos:
   + **unsigned char color:** Indica el color al que queremos cambiar. En el enlace adjunto está la lista de colores: https://en.wikipedia.org/wiki/BIOS_color_attributes

9. **void clrscr():** Limpia la pantalla. Utilizo gotoxy() para situar el cursor al principio de la pantalla. El número de filas es de 25 siempre, pero el número de columnas es o 40 u 80. Esto lo soluciono con una condición que saca el modo de vídeo con getvideomode() y si el modo es 0 o 1 el tamaño es 40, y de lo contrario es 80. Usa la interrupción 0x10 en modo 0x06.

10. **void cputchar(char c):** Escribe la letra que escojamos en la pantalla. El color de la letra está marcado por las funciones textcolor() y textbackground(). Usa la interrupción 0x10 en modo 0x09. Tiene los siguientes argumentos:
      + **char c:** Es el carácter que se escribirá.

11. **void getche():** Lee un carácter de teclado y lo muestra. El funcionamiento es simple. Se le pide una tecla al usuario (interrupción 0x21 modo 0x01), el usuario toca una tecla, y con la misma interrupción en modo 0x02 se imprime en pantalla el carácter leido desde teclado.

12. **void draw(unsigned char bgc, unsigned char tc, int csi, int fsi, int cid, int fid):** Dibuja un recuadro en la pantalla en modo texto. Usa la interrupción 0x10 en modo 0x06. Si pones las coordenadas al revés, es decir, la inferior derecha encima de la superior izquierda, no habrá recuadro. Tiene los siguientes argumentos:
      + **unsigned char bgc:** Indica el color del fondo del recuadro.
      + **unsigned char tc:** Indica el color de primer plano dentro del recuadro.
      + **int csi:** Coordenada X de la superior izquierda.
      + **int fsi:** Coordenada Y de la superior izquierda.
      + **int cid:** Coordenada X de la inferior derecha.
      + **int fid:** Coordenada Y de la inferior derecha.

13. **void modotexto():** Pone el modo de video a 3 (80x25). Llama a setvideomode().

14. **void modografico():** Pone el modo de video a 4 (320x200). Llama a setvideomode().

15. **void pixel(BYTE color, int x, int y):** Pone un pixel en una posición específica. Usa la interrupción 0x10 en modo 0x0C. Los parámetros son los siguientes:
      + unsigned char color: Especifica el color del pixel.
      + int x: Posición en el eje X del pixel.
      + int y: Posición en el eje Y del pixel.

## **3. Pruebas de funcionamiento**

&nbsp;&nbsp;&nbsp;&nbsp; A continuación voy a poner capturas del test de funcionamiento:

+ **Ejecución de P1.C:**

![1](https://github.com/jcpicco/pdih/blob/main/P1/capturas/1.png "1")

![2](https://github.com/jcpicco/pdih/blob/main/P1/capturas/2.png "2")

![3](https://github.com/jcpicco/pdih/blob/main/P1/capturas/3.png "3")

![4](https://github.com/jcpicco/pdih/blob/main/P1/capturas/4.png "4")

![5](https://github.com/jcpicco/pdih/blob/main/P1/capturas/5.png "5")

![6](https://github.com/jcpicco/pdih/blob/main/P1/capturas/6.png "6")

![7](https://github.com/jcpicco/pdih/blob/main/P1/capturas/7.png "7")

![8](https://github.com/jcpicco/pdih/blob/main/P1/capturas/8.png "8")

+ **Ejecución de P1VGA.C:**

![9](https://github.com/jcpicco/pdih/blob/main/P1/capturas/9.png "9")
