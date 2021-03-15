/**
 * @file funciones.c
 * @author Juan Manuel Consigliere Picco
 * @date 14/03/2021
 * @brief Implementación de las funciones de la biblioteca funciones.h.
 */

#include <stdio.h>
#include <dos.h>
#include "funciones.h"

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

/**
 * @brief Pone el modo de video a 4 (320x200).
 */
void modografico(){
	setvideomode(4);
}

/**
 * @brief Pone un pixel en una posición específica.
 * 
 * @param color Especifica el color del pixel.
 * @param x Posición en el eje X del pixel.
 * @param y Posición en el eje Y del pixel.
 */
void pixel(BYTE color, int x, int y){
   union REGS inregs, outregs;

   inregs.x.cx = x;
   inregs.x.dx = y;
   inregs.h.al = color;
   inregs.h.ah = 0x0C;

   int86(0x10, &inregs, &outregs);
}