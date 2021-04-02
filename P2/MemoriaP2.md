<h1><b><p align=center> PDIH: Práctica 2</p></b></h1>

## **1. Introducción y configuración de ncurses**

&nbsp;&nbsp;&nbsp;&nbsp;En esta práctica se nos propone programar en C, a raíz del ejemplo de movimiento de una pelota que el profesor nos ha dado, el juego "pong". Tiene que incluir mínimo una pantalla introductoria con el título y los controles de usuario, y una pantalla de pausa.

&nbsp;&nbsp;&nbsp;&nbsp;Para llevar a cabo esta práctica nos valdremos de la librería ncurses, la cual nos da una API que nos permite escribir interfaces basadas en texto. Para instalar la librería solamente necesité el comando *sudo apt-get install libncurses5-dev libncursesw5-dev*. para poder utilizar la librería nos basta con escribir al principio del código en C *#include <ncurses.h>*. En mi código he puesto una variable global que marca el delay entre pantallas (*#define DELAY 50000*)

## **2. Funciones útiles**

&nbsp;&nbsp;&nbsp;&nbsp;Para la realización del programa he decidido encapsular 3 cosas distintas en 3 funciones distintas: la pantalla del comienzo, la pantalla de pausa, y la pantalla de fin de juego. Ahora paso a explicarlas:

```cpp
[autoexec]
void start_screen(){
	initscr();
	noecho();
	curs_set(FALSE);
	mvprintw(0,0,	"\n\n\n\n\n\n\n"
					"\t\t   8888888b.  .d88888b. 888b    888 .d8888b.\n"
					"\t\t   888   Y88bd88P   Y88b8888b   888d88P  Y88b\n"
					"\t\t   888    888888     88888888b  888888    888\n"
					"\t\t   888   d88P888     888888Y88b 888888\n"
					"\t\t   888       888     888888  Y88888888    888 \n"
					"\t\t   888       Y88b. .d88P888   Y8888Y88b  d88P \n"
					"\t\t   888         Y88888P  888    Y888  Y8888P88 \n"
					"\n\n"
					"\t\t\tJugador 1: W(Arriba) | S(Abajo) \n"
					"\t\t\tJugador 2: I(Arriba) | J(Abajo)\n"
					"\t\t\t   PULSA P PARA PAUSAR JUEGO\n");
	box(stdscr, '|', '-');
	getch();
	nodelay(stdscr,1);
	clear();
}
```

**void start_screen():** Aquí inicializamos la ventana de ncurses con *initscr()*, luego para que no haya eco se utiliza *noecho()*, y para no mostrar el cursos ponemos curs_set(FALSE). Después escribimos con *mvprintv()* la pantalla de título con los controles, y dibujamos una caja alrededor. Finalmente esperamos a la pulsación de cualquier tecla y activamos *nodelay()*, lo cual hace que no se esperen a las entradas a partir de ese punto. *clear()* Limpia la pantalla al completo.

```cpp
void pause_screen(){
	clear();
	mvprintw(1,0,	"\n\n\n\n\n\n"
					"\t\t   8888888b.  .d88888b. 888b    888 .d8888b.\n"
					"\t\t   888   Y88bd88P   Y88b8888b   888d88P  Y88b\n"
					"\t\t   888    888888     88888888b  888888    888\n"
					"\t\t   888   d88P888     888888Y88b 888888\n"
					"\t\t   888       888     888888  Y88888888    888 \n"
					"\t\t   888       Y88b. .d88P888   Y8888Y88b  d88P \n"
					"\t\t   888         Y88888P  888    Y888  Y8888P88 \n"
					"\n\n"
					"\t\t\t\t JUEGO EN PAUSA \n"
					"\t\t\t     PULSA P PARA CONTINUAR\n");
	nodelay(stdscr,0);
}
```

**void pause_screen():** Aquí primero limpiamos la pantalla, luego imprimimos el mensaje y finalmente desactivamos el *nodelay()*. Esta función no hace gran cosa, ya que dentro del código se hace casi todo.

```cpp
void end_screen(int p1, int p2){
	nodelay(stdscr,0);
	clear();
	mvprintw(1,0,	"\n\n\n\n\n\n"
					"\t\t   8888888b.  .d88888b. 888b    888 .d8888b.\n"
					"\t\t   888   Y88bd88P   Y88b8888b   888d88P  Y88b\n"
					"\t\t   888    888888     88888888b  888888    888\n"
					"\t\t   888   d88P888     888888Y88b 888888\n"
					"\t\t   888       888     888888  Y88888888    888 \n"
					"\t\t   888       Y88b. .d88P888   Y8888Y88b  d88P \n"
					"\t\t   888         Y88888P  888    Y888  Y8888P88 \n"
					"\n\n"
					"\t\t\t\t Resultado: %i||%i",p1,p2);
	if(p1 > p2)
		mvprintw(17,0,"\t\t\t       ¡Gana el jugador 1!");
	else
		mvprintw(17,0,"\t\t\t       ¡Gana el jugador 2!");
	
	getch();
}
```

**void end_screen(int p1, int p2):** Esta desactiva el nodelay, limpia la pantalla, imprime el mensaje y realiza una comparación de puntuaciones para decidir quién es el ganador de la partida.

## **3. El código del main**

&nbsp;&nbsp;&nbsp;&nbsp;Ahora paso a explicar las variables utilizadas:
+ **int i** Simplemente sirve para inicializar los bucles for.
+ **int x, y** La coordenada inicial x e y desde donde sale la pelota. Son 39 y 12 respectivamente.
+ **int p1_y, p2_y** Posición y superior de la barra que va a golpear a la pelota. Se inicializan en la posición 10 las dos.
+ **int max_y, max_x** Las coordenadas máximas. Los límites de la pantalla, que corresponden con la esquina inferior derecha de esta. Son 25 y 80 respectivamente.
+ **int next_x, next_y** Marca la dirección siguiente a la que se va a mover la pelota. Se inicializan a 0.
+ **int directionx, directiony** Marca el sentido a la que se va a mover la pelota. Se inicializan a 1.
+ **int p1_puntos, p2_puntos** Puntuación de los jugadores. Naturalmente se inicializan a 0.
+ **int pause** Marca si el juego está en pausa o no. Se inicializa a 0 y solamente puede ser 0 o 1.
+ **int fin** Marca si el juego ha terminado o no. Se inicializa a 0 y solamente puede ser 0 o 1.

&nbsp;&nbsp;&nbsp;&nbsp; Ahora paso a explicar el código. Todo se encuentra dentro de un bucle *while(fin == 0)*. Personalmente me gusta dividirlo en varias partes distintas:

```cpp
    start_screen();

    mvprintw(y, x, "o");
    mvprintw(0,38,"%i||%i",p1_puntos,p2_puntos);

    for(i = p1_y ; i < p1_y+5 ; i++)
        mvprintw(i, 10, "|");

    for(i = p2_y ; i < p2_y+5 ; i++)
        mvprintw(i, 69, "|");

    refresh();
	usleep(DELAY);
```

**Refresco de la pantalla:** Se llama a *start_screen()*, se dibuja la tabla de puntuaciones y la pelota en la posición 39,12 y se dibujan las dos barras con un bucle que recorre desde la posición inciial 10 a 5 puntos del eje y por debajo. Los puntos x de inicio son 10 y 69 respectivamente. Finalmente se llama a la función *refresh()* para mostrar los cambios en pantalla, y se marca el delay de espera entre movimiento, llamando a la variable global *DELAY*.

```cpp
while(pause == 1){
    mvprintw(0,38,"%i||%i",p1_puntos,p2_puntos);
    pause_screen();

    switch(getch()){
        case 'p':
            pause = 0;
            nodelay(stdscr,1);
            break;
    }
}
```

**Detección de pausa:** Si la variable *pause* se encuentra en 1, se imprime la puntuación de ese momento, se llama a *pause_screen()* y se llama a *getch()*: si se pulsa la p, *pause* pasa a ser 0 otra vez, *nodelay()* se activa y nos salimos del bucle while.

```cpp
switch(getch()){
    case 'w':
        if(p1_y != 0) p1_y--;
        break;
    case 's':
        if(p1_y != 19) p1_y++;
        break;
    case 'i':
        if(p2_y != 0) p2_y--;
        break;
    case 'k':
        if(p2_y != 19) p2_y++;
        break;
    case 'p':
        pause = 1;
        break;
    case 'q':
        fin = 1;
        break;
}
```

**Entrada de teclado:** Hacemos *getch()* y dependiendo de la opción aumentamos los ejes y de cada jugador, en los cuales hay restricciones por las dimensiones de la pantalla, naturalmente. Tengo también la opción de pulsar p, para que la variable *pause* se ponga a 1 y en la siguiente iteración del while principal se ponga en pausa. Finalmente si queremos terminar el juego en algún momento solamente tenemos que pulsar q y *fin* se pone a 1 para salir del bucle.

```cpp
next_x = x + directionx;
next_y = y + directiony;

if( next_x < max_x || next_x > 0) {
    x+= directionx;
} 

if(next_x == 10){
    if(next_y == p1_y   || next_y == p1_y+1
    || next_y == p1_y+2 || next_y == p1_y+3
    || next_y == p1_y+4){
        directionx*= -1;
    }
} else if(next_x == 69){
    if(next_y == p2_y  || next_y == p2_y+1 
    || next_y == p2_y+2 || next_y == p2_y+3 
    || next_y == p2_y+4){
        directionx*= -1;
    }
}

if( next_y >= max_y || next_y < 0) {
    directiony*= -1;
} else {
    y+= directiony;
}
```

**Cálculo de dirección y de próximo movimiento:** Se suma a *x* e *y* las direcciones (*next_x*, *next_y*) y se comprueba si no exceden los límites de la pantalla. Si el eje x se encuentra dentro de los límites entonces la variable *x* se actualiza también. Luego se comprueba si la siguiente posición del eje x se encuentra en el eje y de las barras y si coincide con la barra. Si es así *directionx* cambia de sentido. Finalmente si el eje y se encuentra fuera de los límites entonces la variable *directiony* cambia de sentido. De lo contrario solamente se actualiza la variable *y*.

```cpp
if(next_x == 79){
    p1_puntos++;
    x = 39;
    y = 12;
} else if(next_x == 0){
    p2_puntos++;
    x = 39;
    y = 12;
}

if(p1_puntos == 7 || p2_puntos == 7){
    end_screen(p1_puntos, p2_puntos);
    fin = 1;
}
```

**Conteo de puntos:** Si *next_x* se encuentra en alguno de los extremos, se aumenta la puntuación del respectivo jugador, y siempre se resetea la posición de *x* e *y*. Finalmente si alguno de los jugadores alcanza la puntuación de 7, se llama a *end_screen()* y *fin* pasa a ser 1, por lo que el juego termina.

## **4. Capturas de funcionamiento**

&nbsp;&nbsp;&nbsp;&nbsp;Se me ha hecho un poco complicado reflejar el correcto funcionamiento con capturas, y al estar trabajando desde una VM no pude hacer una grabación, así que le animo a que lo compile y ejecute usted mismo y compruebe que funciona perfectamente. Aún así considero que las capturas son bastante concisas, y si pone el cursor encima de cada captura te dice lo que estás viendo.

![1](https://github.com/jcpicco/pdih/blob/main/P2/capturas/1.png "Pantalla de inicio con controles")

![2](https://github.com/jcpicco/pdih/blob/main/P2/capturas/2.png "Ejemplo de lado de jugador 2")

![3](https://github.com/jcpicco/pdih/blob/main/P2/capturas/3.png "Pantalla de inicio con controles")

![4](https://github.com/jcpicco/pdih/blob/main/P2/capturas/4.png "Pantalla de pausa")

![5](https://github.com/jcpicco/pdih/blob/main/P2/capturas/5.png "Ejemplo de victoria de jugador 1")

![6](https://github.com/jcpicco/pdih/blob/main/P2/capturas/6.png "Ejemplo de victoria de jugador 2")

![7](https://github.com/jcpicco/pdih/blob/main/P2/capturas/7.png "Ejemplo de partida igualada")