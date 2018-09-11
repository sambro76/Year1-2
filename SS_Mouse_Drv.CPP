#include <stdio.h>
#include <dos.h>
#include <conio.h>
union REGS inreg,outreg;
int status,button,bs,cxx,dxx;
void Reset_Driver_Get_Status(){
inreg.x.ax=0X0000;
int86(0x33,&inreg,&outreg);
status=outreg.x.ax;
button=outreg.x.bx;
if ((status&&0XFFFF)==1) printf("Mouse Driver/Hardware is installed\n");
if (status==0x0000) printf("Mouse Driver/Hardware not installed\n");
if ((button&&0xFFFF)==1) printf("Two button mouse...\n");
if (button==0x0000) printf("More or less than two button\n");
if (button==0x0003) printf("Mouse system /Logitect Mouse\n");
getchar();
}
void Show_Hide_Show_Mouse_Cursor(){
inreg.x.ax=0x0001;
int86(0x33,&inreg,&outreg);
printf("Mouse Cursor is shown...");
getchar();
clrscr();
inreg.x.ax=0x0002;
int86(0x33,&inreg,&outreg);
printf("Mouse Cursor is hidden...");
getchar();
clrscr();
inreg.x.ax=0x0001;
int86(0x33,&inreg,&outreg);
printf("Mouse Cursor is shown...");
getchar();
}
void Get_Mouse_Position_Button_Status(){
inreg.x.ax=0x0003;
int86(0x33,&inreg,&outreg);
int bs= outreg.x.bx;
int cxx=outreg.x.cx;
int dxx=outreg.x.dx;
if(bs==1) printf("Left button is pressed\n");
if(bs==2) printf("Right button is pressed\n");
if(bs==4) printf("Midle button is pressed\n");
printf("CXX=%d\n",cxx);
printf("DXX=%d\n",dxx);
getchar();
}
void Set_Mouse_Pointer_Position(){
inreg.x.ax=0x0004;
inreg.x.cx=0x50;
inreg.x.dx=0x50;
int86(0x33,&inreg,&outreg);
printf("Set mouse pointer position.");
getchar();
}
void Get_Button_Pressed(){
int a=0,b=0;
while(!kbhit()){
inreg.x.ax=0x0005;
inreg.x.bx=0x0000;
int86(0x33,&inreg,&outreg);
bs=outreg.x.bx;
if((bs&&0x0001)==1){clrscr();
	gotoxy(0,0);
	printf("Left Button has been pressed...");
	cxx=outreg.x.cx;
	dxx=outreg.x.dx;
	a+=outreg.x.bx;
	}
inreg.x.ax=0x0005;
inreg.x.bx=0x0001;
int86(0x33,&inreg,&outreg);
bs=outreg.x.bx;
if((bs&&0x0002)==1){clrscr();
	gotoxy(0,0);
	printf("Right button has been pressed...");
	cxx=outreg.x.cx;
	dxx=outreg.x.dx;
	b+=outreg.x.bx;
	}
inreg.x.ax=0x0005;
inreg.x.bx=0x0002;
int86(0x33,&inreg,&outreg);
bs=outreg.x.bx;
if((bs&&0x0004)==1){clrscr();
	gotoxy(0,0);
	printf("Middle button has been pressed (Mouse system/ Logitech)");
	cxx=outreg.x.cx;
	dxx=outreg.x.dx;
	}
gotoxy(10,12);printf("Number of Left button pressed =%d",a);
gotoxy(10,13);printf("Number of Right button pressed =%d",b);
gotoxy(10,14);printf("Total Button pressed =%d",a+b);
gotoxy(10,15);printf("Horizontal co-ordinate(X) of last button pressed %d",cxx);
gotoxy(10,16);printf("Veritcal co-ordinate(X) of last button pressed %d",dxx);
gotoxy(10,17);printf("Click now...\n");
}
getchar();
}
void Get_Button_Released(){
int a=0,b=0;
while(!kbhit()){//clrscr();
inreg.x.ax=0x0006;
inreg.x.bx=0x0000;
int86(0x33,&inreg,&outreg);
bs=outreg.x.bx;
if((bs&&0x0001)==1){clrscr();
	gotoxy(0,0);
	printf("Left Button has been released.");
	cxx=outreg.x.cx;
	dxx=outreg.x.dx;
	a+=outreg.x.bx;
	}
inreg.x.ax=0x0006;
inreg.x.bx=0x0001;
int86(0x33,&inreg,&outreg);
bs=outreg.x.bx;
if((bs&&0x0002)==1){clrscr();
	gotoxy(0,0);
	printf("Right button has been released.");
	cxx=outreg.x.cx;
	dxx=outreg.x.dx;
	b+=outreg.x.bx;
	}
inreg.x.ax=0x0006;
inreg.x.bx=0x0002;
int86(0x33,&inreg,&outreg);
bs=outreg.x.bx;
if((bs&&0x0004)==1){clrscr();
	gotoxy(0,0);
	printf("Middle button has been released (Mouse system/ Logitech)");
	cxx=outreg.x.cx;
	dxx=outreg.x.dx;
	}
delay(100);
gotoxy(10,12);printf("Number of Left button has been released =%d",a);
gotoxy(10,13);printf("Number of Right button has been released =%d",b);
gotoxy(10,14);printf("Total Button released =%d",a+b);
gotoxy(10,15);printf("Horizontal co-ordinate(X) of last button pressed %d",cxx);
gotoxy(10,16);printf("Veritcal co-ordinate(X) of last button pressed %d",dxx);
gotoxy(10,17);printf("Click to test released button...");
}
getchar();
}

void main(){clrscr();
Reset_Driver_Get_Status();
Show_Hide_Show_Mouse_Cursor();
clrscr();
Get_Mouse_Position_Button_Status();
clrscr();
Set_Mouse_Pointer_Position();
clrscr();
Get_Button_Pressed();
clrscr();
Get_Button_Released();
}