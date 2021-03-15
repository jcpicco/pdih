#include <stdio.h>
#include <dos.h>
#define BYTE unsigned char

void mi_pausa(){
	 union REGS inregs, outregs;
	 inregs.h.ah = 8;
	 int86(0x21, &inregs, &outregs);
}

void modovideo(BYTE modo){
	 union REGS inregs, outregs;
	 inregs.h.al = modo;
	 inregs.h.ah = 0x00;
	 int86(0x10, &inregs, &outregs);
}

int main(){

		printf("\nCambiando modo de video a 1h... ");

		modovideo(1);

		printf("\nPulsa una tecla...   ");

		mi_pausa();

		printf("\nRevirtiendo modo de video a 3h...  ");

		modovideo(3);

		return 0;
}