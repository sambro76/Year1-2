//PUSH and POP instruction
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<ctype.h>
int z=270;
void memory_location(int i){
	int m=75;
	setcolor(15);
	line(60+i*m,z,60+i*m,z+160);
	line(100+i*m,z,100+i*m,z+160);
	for(int j=0;j<7;j++){
		setcolor(j+1);
		line(60+m*i,z+20+j*20,100+m*i,z+20+j*20);
	}
}

void PUSH(char *a,int b,int c,int ab){
setcolor(155);
outtextxy(160,140+ab,a);
delay(500);
for(int i=1;i<33;i++){
setcolor(i+10);
line(65+c,z+129.5-b,85+c,z+129.5-b);
line(85+c,z+128-b,85+c,z+131-b);
line(85+c,z+128-b,89+c,z+129.5-b);
line(85+c,z+131-b,89+c,z+129.5-b);//#1
line(65+c,z+109.5-b,85+c,z+109.5-b);
line(85+c,z+108-b,85+c,z+111-b);
line(85+c,z+108-b,89+c,z+109.5-b);
line(85+c,z+111-b,89+c,z+109.5-b);//#2
delay(50);
}
setcolor(0);
line(65+c,z+129.5-b,85+c,z+129.5-b);
line(85+c,z+128-b,85+c,z+131-b);
line(85+c,z+128-b,89+c,z+129.5-b);
line(85+c,z+131-b,89+c,z+129.5-b);//#1
line(65+c,z+109.5-b,85+c,z+109.5-b);
line(85+c,z+108-b,85+c,z+111-b);
line(85+c,z+108-b,89+c,z+109.5-b);
line(85+c,z+111-b,89+c,z+109.5-b);//#2
}

void After_PUSH(char *a,char *b,int c){
setcolor(25);
outtextxy(60+75*c,z+157,"After");
outtextxy(53+75*c,z+167,a);
outtextxy(53+75*c,z+177,b);
}

void main(){aa:
clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"D:\\TC\\BGI");
int x=10,y=10;
for(int i=0;i<48;i++){
setcolor(i);
settextstyle(0,0,1);
outtextxy(x+i/10,y+i/10,"This program will show the instruction of PUSH and POP");
outtextxy(x+i/10,y+20+i/10,"By Using The LIFO Method...");
delay(30);
}
setcolor(15);
outtextxy(x,y+70,"Example: ");

for(i=0;i<9;i++){
setcolor(i+1);
outtextxy(x+150,y+85,"SP=2002H   AX=18DCH   DI=F0EAH   CX=199AH");
setcolor(15);
outtextxy(x,y+105,"The stack value of each instruction will display as the following execution:");
delay(40);
}
outtextxy(0,z+27,"SS:1FFD");
outtextxy(0,z+47,"SS:1FFE");
outtextxy(0,z+67,"SS:1FFF");
outtextxy(0,z+87,"SS:2000");
outtextxy(0,z+107,"SS:2001");
outtextxy(0,z+127,"SS:2002");

memory_location(0);
setcolor(25);
outtextxy(61,z+157,"Start");
for(i=1;i<26;i++){
setcolor(i);
outtextxy(x+150,y+85,"SP=2002H");
delay(50);
}
outtextxy(53,z+167,"SP=2002");

PUSH("PUSH AX",0,0,0);
setcolor(15);
memory_location(1);
outtextxy(73+75,z+127,"18");
outtextxy(73+75,z+107,"DC");
After_PUSH("PUSH AX","SP=2000",1);

PUSH("PUSH CX",40,75,15);
memory_location(2);
outtextxy(73+75*2,z+127,"18");
outtextxy(73+75*2,z+107,"DC");
outtextxy(73+75*2,z+87,"19");
outtextxy(73+75*2,z+67,"9A");
After_PUSH("PUSH CX","SP=1FFE",2);

PUSH("PUSH DI",80,75*2,30);
memory_location(3);
outtextxy(73+75*3,z+127,"18");
outtextxy(73+75*3,z+107,"DC");
outtextxy(73+75*3,z+87,"19");
outtextxy(73+75*3,z+67,"9A");
outtextxy(73+75*3,z+47,"F0");
outtextxy(73+75*3,z+27,"EA");
After_PUSH("PUSH DI","SP=1FFC",3);

delay(500);
outtextxy(160,140+35,".");
for(i=0;i<6;i++)outtextxy(110+75*3,z+25+20*i,".");
delay(500);
for(i=0;i<6;i++)outtextxy(110+75*3,z+25+20*i," .");
outtextxy(160,140+45,".");
delay(500);
for(i=0;i<6;i++)outtextxy(110+75*3,z+25+20*i,"  .");
outtextxy(160,140+55,".");

memory_location(4);
outtextxy(73+75*4,z+127,"18");
outtextxy(73+75*4,z+107,"DC");
outtextxy(73+75*4,z+87,"19");
outtextxy(73+75*4,z+67,"9A");
outtextxy(73+75*4,z+47,"F0");
outtextxy(73+75*4,z+27,"EA");
setcolor(25);
outtextxy(61+75*4,z+157,"Start");
outtextxy(53+75*4,z+167,"SP=1FFC");

PUSH("POP DI",80,75*4,70);
memory_location(5);
outtextxy(73+75*5,z+127,"18");
outtextxy(73+75*5,z+107,"DC");
outtextxy(73+75*5,z+87,"19");
outtextxy(73+75*5,z+67,"9A");
After_PUSH(" POP DI","SP=1FFE",5);

PUSH("POP CX",40,75*5,85);
memory_location(6);
outtextxy(73+75*6,z+127,"18");
outtextxy(73+75*6,z+107,"DC");
After_PUSH(" POP CX","SP=2000",6);

PUSH("POP AX",0,75*6,100);
memory_location(7);
After_PUSH(" POP AX","SP=2002",7);

char ch;
setcolor(14);
outtextxy(250,200,"Do you want to see the process again?(Y\\N)");
ch=toupper(getch());
if(ch=='Y')goto aa;
while(ch==kbhit());
cleardevice();
for(i=0;i<48;i++){
setcolor(i);
settextstyle(1,0,2);
outtextxy(188+i/10,200+i/10,"WRITTEN BY CHAY SAMNANG");
settextstyle(0,0,2);
outtextxy(160,250,"Programmed in Oct-2002");
delay(50);
}
delay(450);
closegraph();
}