//Register Test...
#include<conio.h>
#include<stdio.h>
void main(){
clrscr();
unsigned int x,Res;
cprintf("Enter a value in hexa mode: " );
scanf("%x", &x);
asm {
	MOV AX,x;
	MOV DX,AX;
	MOV CX,DX;
	MOV DI,CX;
	MOV Res,DI;
}
printf("Value=%.4x",Res);
getch();
}

