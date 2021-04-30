<h1><b><p align=center> PDIH: Práctica 4</p></b></h1>

## **1. Introducción a Postscript**

&nbsp;&nbsp;&nbsp;&nbsp;El lenguaje PostScript (PS) es el código de programación que se usa para especificarle a una impresora qué y cómo debe imprimir, paso a paso. Fue creado por John Warnock y Charles Gescthke en 1984 en Adobe Systems. Es un lenguaje que comprende mayoritariamente una impresora.

&nbsp;&nbsp;&nbsp;&nbsp;En esta práctica se nos ha pedido hacer dos pequeños proyectos los cuales voy a enseñar y explicar a continuación:

## **2. Dibujo de una casa**

![1](https://github.com/jcpicco/pdih/blob/main/P4/capturas/1.png "1")

&nbsp;&nbsp;&nbsp;&nbsp;Este proyecto era simplemente dibujar una casa con su tejado, ventanas y puerta. Ya que lo he comentado en casi su totalidad voy a explicar algunas partes que considere oportunas:

```postscript
0 0.5 1 setrgbcolor % Color RGB
0.1 setlinewidth    % Tamaño de línea 0.1

newpath             % TEJADO

200 500 moveto      % Origen en (200,500)
100 100 rlineto     % Línea de (200,500) 100 derecha y 100 arriba
100 -100 rlineto    % Línea de (300,600) 100 derecha y 100 abajo
gsave               % Guarda último estado               
0.7 setgray         % Color (0 negro - 1 blanco)
fill                % Rellenar contenido
grestore            % Restaura último estado
closepath           % Cerramos el camino

stroke
```

&nbsp;&nbsp;&nbsp;&nbsp;Comienzo dandole el color azul clarito a las líneas y poniendo el grosor de línea más bajo. Creo un newpath y pongo el orígen en (200,500), y creo una línea que se mueva diagonalmente +100 hacia la derecha y hacia arriba. Luego hago una línea que se sitúe en el eje horizontal del orígen pero de dimensiones iguales, y finalmente con closepath cierro el camino y se genera el triángulo.

&nbsp;&nbsp;&nbsp;&nbsp;Las órdenes gsave y grestore sirven para hacer cambios temporales para ciertas órdenes. Para cambiar el color a gris al relleno lo he usado yo.

```postscript
newpath			

/Arial findfont	    % Buscar fuente Arial
14 scalefont		% Tamaño de letra 14
setfont			    % Aplicar fuente Arial
190 430 moveto		% Origen en (345,460)
gsave               % Guarda último estado
0 setgray           % Color (0 negro - 1 blanco)
90 rotate           % Rotación de origen 90º
(Mi casita) show    % Texto "Mi casita"
grestore            % Restaura último estado

stroke

showpage
```

&nbsp;&nbsp;&nbsp;&nbsp;Ahora he escogido la fuente Arial. cambiado el tamaño de letra. Me he posicionado en el lado izquierdo y he abierto un gsave que cambia el color a negro y la rotación 90º. Seguidamente he impreso el texto y finalmente revertí con grestore.

&nbsp;&nbsp;&nbsp;&nbsp;Los archivos .ps, .pdf y .jpg los puedes encontrar en [GitHub](https://github.com/jcpicco/pdih/tree/main/P4) en sus carpetas respectivas.

## **3. Tarjeta de visita**

![2](https://github.com/jcpicco/pdih/blob/main/P4/capturas/2.png "2")

&nbsp;&nbsp;&nbsp;&nbsp;Este ejercicio es un poco más complejo, pero no he tenido mucho problema a la hora de realizarlo. Es una tarjeta de visita con información muy básica. Voy a explicar algunas partes que considero importantes del código a continuación:

```postscript
%!PS

0.5 setlinewidth                    % Tamaño de línea 0.5

newpath

0.9 setgray                         % Color (0 negro - 1 blanco)
210 410 moveto                      % Origen en (210,410)
240  0 rlineto                      % Línea de (210,410) 240 derecha
0 140 rlineto                       % Línea de (450,410) 140 arriba
-240 0 rlineto                      % Línea de (450,500) 240 izquierda
fill                                % Rellenar contenido
closepath                           % Cerramos el camino

stroke
```

&nbsp;&nbsp;&nbsp;&nbsp;Comienzo definiendo el grosor de línea, ya que es algo que no va a cambiar en ningún momento. Luego procedo a definir el newpath con el color gris más claro y dibujo un rectángulo. Finalmente lo relleno de gris.

&nbsp;&nbsp;&nbsp;&nbsp;No voy a poner el código porque es muy simple, pero le he añadido una pequeña sombra a la tarjeta, que son solamente dos líneas de un gris más oscuro abajo y a la derecha.

```postscript
newpath                             %CIRCUNFERENCIA

0.5 setgray                         % Color (0 negro - 1 blanco)
270 480 30 0 360 arc                % Cirfunferencia en (270,480) de radio 30
gsave                               % Guarda último estado 
0.8 setgray                         % Color gris claro
fill                                % Rellenar contenido          
grestore                            % Restaura último estado

stroke
```

&nbsp;&nbsp;&nbsp;&nbsp;Aquí está la declaración de la circunferencia de radio 30 situada en el centro de la mitad izquierda de la tarjeta. Hago un gsave para poner el interior de un color de relleno más claro que su borde.

```postscript
newpath                             %TEXTO PRINCIPAL

0 setgray                           % Color (0 negro - 1 blanco)
/Arial findfont	                    % Buscar fuente Arial
10 scalefont                        % Tamaño de letra 10
setfont			                    % Aplicar fuente Arial
355 495 moveto                      % Origen en (355,485)
(Drago Kovacevic) show              % Texto "Drago Kovacevic"

stroke
```

&nbsp;&nbsp;&nbsp;&nbsp;Aquí he puesto el nombre, el cual va en negro y en la mitad derecha de la tarjeta. Los demás textos se declaran de forma similar solo que cambiando el color a gris claro y cada uno en una posición del eje Y distinta.

&nbsp;&nbsp;&nbsp;&nbsp;Los archivos .ps, .pdf y .jpg los puedes encontrar en [GitHub](https://github.com/jcpicco/pdih/tree/main/P4) en sus carpetas respectivas.