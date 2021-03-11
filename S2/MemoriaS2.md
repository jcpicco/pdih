<h1><b><p align=center> PDIH: Seminario 2</p></b></h1>

## **1. Configuración de DOSBox**

&nbsp;&nbsp;&nbsp;&nbsp;Para la correcta configuración he añadido en el archivo *dosbox-0.74-3.conf*, el cual se encuentra en mi carpeta */home/juan/.dosbox/*, el siguiente código en el apartado *[autoexec]*:
```
[autoexec]
# Lines in this section will be run at startup.
# You can put your MOUNT lines here.
mount C /home/juan/Documentos/pdih/S1
keyb sp
path c:/home/juan/Documentos/pdih/bc/BIN/
c:
```
&nbsp;&nbsp;&nbsp;&nbsp;Ahora cuando abro DOSBox se monta automáticamente la carpeta S1, que es de donde trabajaré, se carga el teclado en español, y he especificado la ruta de BC, que es con lo que compilaré los programas. En esta práctica la he movido la carpeta BC y la he sacado de S1, ya que la usaremos en otras prácticas.

![1](https://github.com/jcpicco/pdih/blob/main/S2/capturas/1.png "Ventana DOSBox configurada")

## **2. Primer programa en C**

&nbsp;&nbsp;&nbsp;&nbsp;En este ejercicio se pide hacer un programa sencillo utilizando las interrupciones en C. El programa lo que hará es cambiar la configuración gráfica a 1h (texto | 40x25 | 16 colores), se realiza una pausa, y luego se revierte a la configuración anterior 3h (texto | 80x25 | 16 colores). A continuación le adjunto tanto el código como la ejecución:

![2](https://github.com/jcpicco/pdih/blob/main/S2/capturas/2.png "Código CAMBIO~1.C")

![3](https://github.com/jcpicco/pdih/blob/main/S2/capturas/3.png "ejecución CAMBIO~1.C")

## **2. Segundo programa en C**

&nbsp;&nbsp;&nbsp;&nbsp;En este ejercicio se pide hacer un programa sencillo utilizando las interrupciones en C. El programa lo que hará es leer un carácter de teclado que hayamos tecleado, y este se mostrará a continuación en la pantalla. A continuación le adjunto tanto el código como la ejecución:

![4](https://github.com/jcpicco/pdih/blob/main/S2/capturas/4.png "Código ESCRIB~1.C")

![5](https://github.com/jcpicco/pdih/blob/main/S2/capturas/5.png "ejecución ESCRIB~1.C")

