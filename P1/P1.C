/**
 * @file p1.c
 * @author Juan Manuel Consigliere Picco
 * @date 14/03/2021
 * @brief Archivo de pruebas de la biblioteca funciones.h
 */

#include <stdio.h>
#include <dos.h>

#define BYTE unsigned char

BYTE TEXTCOLOR = 7;
BYTE BGCOLOR = 0;

/**
 * @brief Realiza una pausa.
 * 
 *  La ejecución reanudará cuando pulsemos cualquier tecla.
 */
void mi_pausa(){
	 union REGS inregs, outregs;

	 inregs.h.ah = 8;

	 int86(0x21, &inregs, &outregs);
}

/**
 * @brief Cambia la posición del cursor.
 * 
 * @param fil Indica la fila en la que colocamos el cursor.
 * @param col Indica la columna en la que colocamos el cursor.
 */
void gotoxy(int fil, int col){
	union REGS inregs, outregs;
    
	inregs.h.ah = 2;
    inregs.h.dh = fil;
	inregs.h.dl = col;
	inregs.h.bh = 0;

	int86(0x10, &inregs, &outregs);
}

/**
 * @brief Cambia el tipo de cursor.
 * 
 * Cambia entre tres tipos de cursor: invisible, normal o grueso.
 * 
 * @param tipo_cursor Indica el tipo de cursor. Valores válidos: 0 (invisible), 1 (normal) o 2 (grueso).
 */
void setcursortype(int tipo_cursor){
	union REGS inregs, outregs;

	inregs.h.ah = 0x01;

	switch(tipo_cursor){
		case 0: //invisible
			inregs.h.ch = 010;
			inregs.h.cl = 000;
			break;

		case 1: //normal
			inregs.h.ch = 010;
			inregs.h.cl = 010;
			break;

		case 2: //grueso
			inregs.h.ch = 000;
			inregs.h.cl = 010;
			break;
	}

	int86(0x10, &inregs, &outregs);
}

/**
 * @brief Cambia el modo de video.
 * 
 * @param modo Cambia el modo de video. La tabla de modos se encuentra en el enlace adjunto.
 * @see https://es.wikipedia.org/wiki/Int_10h
 */
void setvideomode(BYTE modo){
	 union REGS inregs, outregs;

	 inregs.h.al = modo;
	 inregs.h.ah = 0x00;

	 int86(0x10, &inregs, &outregs);
}

/**
 * @brief Devuelve el modo de video actual.
 * 
 * @return Modo de video en formato int.
 */
int getvideomode(){
	int caracter;
	union REGS inregs, outregs;

	inregs.h.ah = 0x0F;

	int86(0x10, &inregs, &outregs);

	caracter = outregs.h.al;

	return caracter;
}

/**
 * @brief Revierte a los colores por defecto para los caracteres.
 */
void revertcolor(){
	TEXTCOLOR = 7;
	BGCOLOR = 0;
}

/**
 * @brief Cambia el color de primer plano en el que se mostrarán los caracteres.
 * 
 * @param color Indica el color al que queremos cambiar. En el enlace adjunto está la lista de colores.
 * @see https://en.wikipedia.org/wiki/BIOS_color_attributes
 */
void textcolor(BYTE color){
	TEXTCOLOR = color;
}

/**
 * @brief Cambia el color de fondo en el que se mostrarán los caracteres.
 * 
 * @param color Indica el color al que queremos cambiar. En el enlace adjunto está la lista de colores.
 * @see https://en.wikipedia.org/wiki/BIOS_color_attributes
 */
void textbackground(BYTE color){
	BGCOLOR = color;
}

/**
 * @brief Limpia la pantalla.
 * 
 * Utilizo gotoxy() para situar el cursor al principio de la pantalla.
 */
void clrscr(){
	union REGS inregs, outregs;
	int vm;

	inregs.h.al = 25;
	inregs.h.ah = 0x06;
	inregs.h.bh = 0 << 4 | 7;
	inregs.h.cl = 0x00;
	inregs.h.ch = 0x00;
	inregs.h.dh = 25;

	vm = getvideomode();

	if(vm == 0x00 || vm == 0x01)
		inregs.h.dl = 40;

	else
		inregs.h.dl = 80;

	int86(0x10, &inregs, &outregs);
	gotoxy(0,0);
}

/**
 * @brief Escribe la letra que escojamos en la pantalla.
 * 
 * El color de la letra está marcado por las funciones textcolor() y textbackground().
 * 
 * @param c Es el carácter que se escribirá.
 */
void cputchar(char c){
	union REGS inregs, outregs;

	inregs.h.ah = 0x09;
	inregs.h.al = c;
	inregs.h.bl = BGCOLOR << 4 | TEXTCOLOR;
	inregs.h.bh = 0x00;
	inregs.x.cx = 1;

	int86(0x10,&inregs,&outregs);
}

/**
 * @brief Lee un carácter de teclado y lo muestra.
 * 
El funcionamiento es simple. Se le pide una tecla al usuario (interrupción 0x21 
 * modo 0x01), el usuario toca una tecla, y con la misma interrupción en modo 0x02 
 * se imprime en pantalla el carácter leido desde teclado. * 
 */
void getche(){
	union REGS inregs, outregs;
    int c;

    inregs.h.ah = 0x01;

	printf("\nPulsa una tecla: ");
    int86(0x21, &inregs, &outregs);

    c = outregs.h.al;
	
	printf("\nTecla pulsada: ");
	inregs.h.ah = 0x02;
	inregs.h.dl = c;
	int86(0x21, &inregs, &outregs);
}

/**
 * @brief Dibuja un recuadro en la pantalla en modo texto.
 * 
 * @param bgc Indica el color del fondo del recuadro.
 * @param tc Indica el color de primer plano dentro del recuadro.
 * @param csi Coordenada X de la superior izquierda.
 * @param fsi Coordenada Y de la superior izquierda.
 * @param cid Coordenada X de la inferior derecha.
 * @param fid Coordenada Y de la inferior derecha.
 * 
 * @warning Si pones las coordenadas al revés, es decir, la inferior derecha encima de la superior izquierda, no habrá recuadro.
 */
void draw(BYTE bgc, BYTE tc, int csi, int fsi, int cid, int fid){
	union REGS inregs, outregs;

	inregs.h.al = 0;
	inregs.h.ah = 0x06;
	inregs.h.bh = bgc << 4 | tc;
	inregs.h.cl = csi;
	inregs.h.ch = fsi;
	inregs.h.dl = cid;
	inregs.h.dh = fid;
	int86(0x10, &inregs, &outregs);
}

/**
 * @brief Pone el modo de video a 3 (80x25).
 */
void modotexto(){
	setvideomode(3);
}

int main(){
	int tmp, i;
	char c;
	
    printf("***********************************");
    printf("\n¡Bienvenido al programa de pruebas!");
    printf("\n***********************************\n");
    printf("\nPresiona cualquier tecla para continuar...");
	mi_pausa();

	//Prueba gotoxy() y clrscr()
	clrscr();
    printf("Pantalla limpia\n");
    printf("\nMoviendo el cursor a la posición (20,30)...");
	gotoxy(20, 30);
	printf("*");
	mi_pausa();

	//Prueba setcursortype()
	clrscr();
	printf("Cursor invisible");
	setcursortype(0);
	mi_pausa();
	printf("\nCursor grueso");
	setcursortype(2);
	mi_pausa();
	printf("\nCursor normal");
	setcursortype(1);
	mi_pausa();

	//Prueba setvideomode() y getvideomode()
	setvideomode(1);
	tmp = getvideomode();
	printf("Has entrado en el modo de video %i", tmp);
	mi_pausa();
	modotexto();
	tmp = getvideomode();
	printf("Has entrado en el modo de video %i", tmp);
	mi_pausa();

	//Prueba textcolor(), textbackground(), revertcolor() y cputchar()
	clrscr();
	textcolor(2);
	textbackground(4);
	c = 'G';
	printf("Escribo la letra %c en verde con fondo rojo: ", c);
	cputchar(c);
	mi_pausa();
	revertcolor();
	c = 'F';
	printf("\nRevierto colores y escribo la letra %c: ", c);
	cputchar(c);
	mi_pausa();

	//Prueba getche() y draw()
	clrscr();
    printf("******************");
    printf("\nPrueba de getche()");
    printf("\n******************\n");
	getche();
	mi_pausa();
	draw(2, 4, 10, 10, 52, 15);
    printf("\n******************");
    printf("\nPrueba de draw()");
    printf("\n******************\n");
	printf("\nRectángulo de fondo verde y texto rojo entre las coordenadas (10,10) y (52,15)");
	mi_pausa();
	clrscr();

	return 0;
}