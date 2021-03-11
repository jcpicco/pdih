#include <stdio.h>
#include <dos.h>
#define BYTE unsigned char

int mi_getchar(){
    union REGS inregs, outregs;
    int caracter;
    
    inregs.h.ah = 1;
    
    int86(0x21, &inregs, &outregs);
    
    caracter = outregs.h.al;
    
    return caracter;
}

void mi_pausa(){
	 union REGS inregs, outregs;
	 inregs.h.ah = 8;
	 int86(0x21, &inregs, &outregs);
}

void mi_putchar(char c){
	 union REGS inregs, outregs;

	 inregs.h.ah = 2;
	 inregs.h.dl = c;
	 int86(0x21, &inregs, &outregs);
}

int main(){
    int tmp;
    
    printf("\nPulsa una tecla: ");
    
    tmp = mi_getchar();
    
    printf("\nHas pulsado: ");

		mi_putchar(tmp);

		mi_pausa();
    
    return 0;
}