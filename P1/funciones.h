void mi_pausa();

void gotoxy(int fil, int col);

void setcursortype(int tipo_cursor);

void setvideomode(unsigned char modo);

int getvideomode();

void revertcolor();

void textcolor(unsigned char color);

void textbackground(unsigned char color);

void clrscr();

void cputchar(char c);

void getche();

void draw(unsigned char bgc, unsigned char tc, int csi, int fsi, int cid, int fid);