/**
 * @file p1.c
 * @author Juan Manuel Consigliere Picco
 * @date 14/03/2021
 * @brief Archivo de pruebas de la biblioteca funciones.h
 */

#include <stdio.h>
#include <dos.h>

unsigned char TEXTCOLOR = 7;
unsigned char BGCOLOR = 0;

void mi_pausa(){
	 union REGS inregs, outregs;

	 inregs.h.ah = 8;

	 int86(0x21, &inregs, &outregs);
}

void gotoxy(int fil, int col){
	union REGS inregs, outregs;
    
	inregs.h.ah = 2;
    inregs.h.dh = fil;
	inregs.h.dl = col;
	inregs.h.bh = 0;

	int86(0x10, &inregs, &outregs);
}

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

void setvideomode(unsigned char modo){
	 union REGS inregs, outregs;

	 inregs.h.al = modo;
	 inregs.h.ah = 0x00;

	 int86(0x10, &inregs, &outregs);
}

int getvideomode(){
	int caracter;
	union REGS inregs, outregs;

	inregs.h.ah = 0x0F;

	int86(0x10, &inregs, &outregs);

	caracter = outregs.h.al;

	return caracter;
}

void revertcolor(){
	TEXTCOLOR = 7;
	BGCOLOR = 0;
}

void textcolor(unsigned char color){
	TEXTCOLOR = color;
}

void textbackground(unsigned char color){
	BGCOLOR = color;
}

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

void cputchar(char c){
	union REGS inregs, outregs;

	inregs.h.ah = 0x09;
	inregs.h.al = c;
	inregs.h.bl = BGCOLOR << 4 | TEXTCOLOR;
	inregs.h.bh = 0x00;
	inregs.x.cx = 1;

	int86(0x10,&inregs,&outregs);
}

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

void draw(unsigned char bgc, unsigned char tc, int csi, int fsi, int cid, int fid){
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

int main(){
	int tmp;
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
	setvideomode(3);
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