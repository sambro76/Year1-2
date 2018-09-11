//Memory area...
#include<conio.h>
#include<stdio.h>
void main(){
clrscr();
int a,b,Res;
printf("Input a value: " );
scanf("%x", &a);
printf("Input an address: " );
scanf("%x", &b);
asm{
	MOV CX,a;
	MOV BX,b;
	MOV [BX],CX;
	MOV DX,[BX];
	MOV Res,DX;
	}
printf("\n\nIn address memory: %x, there is a value '%x' located",b,Res);
getch();
}

