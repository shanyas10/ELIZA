#if !defined (GRAPHICS_H)
#define GRAPHICS_H
#include <windows.h>
#include <conio.h>
#include <cstdio>
#include<stdlib.h>
#include<time.h>
#define DARK_BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define DARK_PURPLE 5
#define BROWN 6
#define GRAY 7
#define DARK_GRAY 8
#define BLUE 9
#define NEON_GREEN 10
#define LIGHT_BLUE 11
#define LIGHT_RED 12
#define PURPLE 13
#define YELLOW 14
#define WHITE 15


void GetHandle( HANDLE &hStdout )
{
	DWORD dw;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	if(hStdout == INVALID_HANDLE_VALUE)
	{
		dw = GetLastError();
		fprintf( stderr, "Invalid Handle : GetLastError has return %d\n", dw );
	}
}
void settextcolor( WORD color )
{
	HANDLE hStdout;
	GetHandle( hStdout );
	SetConsoleTextAttribute( hStdout, color );
	//return rt;
}
void gotoxy( short x, short y )
{
	HANDLE hStdout;
	COORD coord;
	BOOL rt;
	coord.X = x;
	coord.Y = y;
	GetHandle( hStdout );
	SetConsoleCursorPosition( hStdout, coord );
	//return rt;
}
void setbgcolor( WORD color )
{
	HANDLE hStdout;
	GetHandle( hStdout );
	DWORD nLength, nAttWriten;
	COORD coord;
	coord.X = 0;
	coord.Y = 0;
	nLength = 80 * 50; //80*50
	FillConsoleOutputAttribute( hStdout, color, nLength, coord, &nAttWriten ); 
	//return rt;
}

void load(){
    int r,q;
    gotoxy(36,14);
    printf("LOADING...");
    gotoxy(30,15);
    for(r=1;r<=20;r++){
    for(q=0;q<=90000000;q++);//to display the character slowly
    printf("%c",177);}
   
}
void load1()
{
	int i,j,k;
	for(i=0;i<1;i++)
	{
		for(j=0;j<4;j++)
		{
			gotoxy(36+j,14+j);
			printf("o");
		}
		for(k=4;k>0;k--)
		{
			gotoxy(35+j+k,12+k);
			printf("o");	
		}
		
	}
}

#endif
