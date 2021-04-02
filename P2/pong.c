
//  gcc rebota.c -o rebota -lncurses

#include <ncurses.h>
#include <unistd.h>
					
#define DELAY 50000

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

int main(int argc, char *argv[]) {
	int i;
	int x = 39, y = 12;
	int p1_y = 10, p2_y = 10;
	int max_y = 25, max_x = 80;
	int next_x = 0, next_y = 0;
	int directionx = 1, directiony = 1;
	int p1_puntos = 0, p2_puntos = 0;
	int pause = 0;
	int fin = 0;

	while(fin == 0) {
		start_screen();

		mvprintw(y, x, "o");
		mvprintw(0,38,"%i||%i",p1_puntos,p2_puntos);

		for(i = p1_y ; i < p1_y+5 ; i++)
			mvprintw(i, 10, "|");

		for(i = p2_y ; i < p2_y+5 ; i++)
			mvprintw(i, 69, "|");

		refresh();
		usleep(DELAY);

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
	}
	endwin();

	return 0;
}
