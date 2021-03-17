/**
 * @file p1vga.c
 * @author Juan Manuel Consigliere Picco
 * @date 14/03/2021
 * @brief Archivo de pruebas de la biblioteca funciones.h
 */

#include <dos.h>

#define BYTE unsigned char

BYTE MODOTEXTO = 3;
BYTE MODOGRAFICO = 4;

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
 * @brief Pone un pixel en una posición específica.
 * 
 * @param x Posición en el eje X del pixel.
 * @param y Posición en el eje Y del pixel.
 * @param color Especifica el color del pixel.
 */
void pixel(int x, int y, BYTE color){
   union REGS inregs, outregs;
   inregs.x.cx = x;
   inregs.x.dx = y;
   inregs.h.al = color;
   inregs.h.ah = 0x0C;
   int86(0x10, &inregs, &outregs);
}

int main(){
   int i;

   setvideomode(MODOGRAFICO);

   for(i=0; i<320; i++){
      
      pixel(i, 150, 0x0F );
      pixel(i,100, 0x02 );
      pixel(i,50, 0x0D );
   }
   
   for(i=0; i<200; i++){
      pixel(240, i, 0x0F );
      pixel(160,i, 0x02 );
      pixel(80, i, 0x0D );
   }

   mi_pausa();
   setvideomode(MODOTEXTO);

	return 0;
}
