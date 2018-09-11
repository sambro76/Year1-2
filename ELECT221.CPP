#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
void NOT(short x,short y);
void NAND(short x,short y);
void LINES(short x,short y);
void NOT_CONV(short A,short B,short C,short D);
void Start_NAND();
void Result();
void Logo(){
int gd=DETECT,gm;
initgraph(&gd,&gm,"D:\\TC\\BGI");
setcolor(15);
for(int i=0;i<10;i++){
cleardevice();
settextjustify(1,1);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,i);
outtextxy(getmaxx()/2,getmaxy()/2,"Norton University");
delay(100);
}
delay(1000);
setcolor(14);
cleardevice();
for(i=0;i<141;i++){
	cleardevice();
	setcolor(15);
	ellipse(getmaxx()/2,getmaxy()/2,0,360,250,500);
	settextjustify(1,1);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	outtextxy(getmaxx()/2,getmaxy()/2-i,"Department of Computer Science");
	delay(5);
	i+=5;
}
for(i=10;i<getmaxx()/2;i++){
	cleardevice();
	setcolor(15);
	ellipse(getmaxx()/2,getmaxy()/2,0,360,250,500);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	outtextxy(getmaxx()/2,getmaxy()/2-140,"Department of Computer Science");
	settextstyle(3,HORIZ_DIR,1);
	setcolor(12);
	outtextxy(i,getmaxy()/2-105,"Evening Session");
	setcolor(11);
	outtextxy(i,getmaxy()/2-70,"Year II");
	setcolor(10);
	outtextxy(i,getmaxy()/2-35,"Semester I");
	delay(1);
	i+=5;
}
delay(100);
for(i=470;i>getmaxy()/2;i--){
	cleardevice();
	setcolor(15);
	ellipse(getmaxx()/2,getmaxy()/2,0,360,250,500);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	setcolor(14);
	outtextxy(getmaxx()/2,getmaxy()/2-140,"Department of Computer Science");
	settextstyle(3,HORIZ_DIR,1);
	setcolor(12);
	outtextxy(getmaxx()/2,getmaxy()/2-105,"Evening Session");
	setcolor(11);
	outtextxy(getmaxx()/2,getmaxy()/2-70,"Year II");
	setcolor(10);
	outtextxy(getmaxx()/2,getmaxy()/2-35,"Semester I");
	setcolor(6);
	settextstyle(4,HORIZ_DIR,1);
	outtextxy(getmaxx()/2,i+5,"BCD to Decimal Decorder");
	outtextxy(getmaxx()/2,i+40,"Instructur by: Mr Long Chantirith");
	outtextxy(getmaxx()/2,i+75,"Programmed by: Chay Samnang");
	outtextxy(getmaxx()/2,i+105,"ID: 3947");
	outtextxy(getmaxx()/2,i+140,"Academic Year: 2001-2002");
	delay(5);
	i-=5;
}
getch();
closegraph();
initgraph(&gd,&gm,"D:\\TC\\BGI");
setcolor(15);
setcolor(5);
outtextxy(400,15,"Please input a number(0-9),");
outtextxy(400,30,"in Binary code from 0000-1001.");
outtextxy(400,45,"i.e., 7 -> 0111 (4 digits),");
outtextxy(400,60,"from left to right 0 1 1 1");
outtextxy(400,75,"Seperated by Space or Enter.");
settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
settextjustify(1,1);
outtextxy(getmaxx()/2,getmaxy()/2,"Before you continue, please read the instruction here...");
for(i=0;i<30;i++){
	setcolor(i);
	line(getmaxx()/2,getmaxy()/2-10,440,97);
	ellipse(500,50,0,360,150,50);
	delay(300);
}
closegraph();
}
int a,b,c,d,f[10];

//initialized program
void main(){
clrscr();
Logo();
input:
int gd=DETECT,gm;
initgraph(&gd,&gm,"D:\\TC\\BGI");
for(int i=0;i<4;i++){
	NOT(100,120+i*55);
	}
for(i=0;i<10;i++){
	NAND(300,27.5+i*45);
	}
LINES(100+64,120);
setcolor(5);
outtextxy(400,15,"Please input a number(0-9),");
outtextxy(400,30,"in Binary code from 0000-1001.");
outtextxy(400,45,"i.e., 7 -> 0111 (4 digits),");
outtextxy(400,60,"from left to right 0 1 1 1");
outtextxy(400,75,"Seperated by Space or Enter...");
setcolor(4);
cout<<"\n                    ";
for(i=1;i<20;i++){
	setcolor(i);
	outtextxy(10,20,"Number input here: ");
	delay(150);
	}
cin>>d;cin>>c;cin>>b;cin>>a;
if(d+c>1||d+b>1||a<0||b<0||c<0||d<0||a>1||b>1||c>1||d>1){
	for(i=0;i<15;i++){
	setcolor(RED+i*20);
	outtextxy(10,50,"Warning...");
	delay(150);
	}
	setcolor(RED);
	outtextxy(10,60,"Number greater than 9");
	outtextxy(10,75,"or not valid BCD code");
	setcolor(19);
	outtextxy(10,100,"Reinput now...");
	getch();
	goto input;
}

NOT_CONV(a,b,c,d);
Start_NAND();
delay(200);
Result();
settextstyle(2,HORIZ_DIR,5);
for(i=0;i<60;i++){
	setcolor(i);
	outtextxy(400,360,"Programmed by Chay Samnang");
	delay(20);
	}
getch();
closegraph();
}//end program

void NOT(short x,short y){
line(x,y,(x+20),y);
line((x+20),y,(x+20),(y-10));
line((x+20),(y-10),(x+40),y);
line((x+40),y,(x+20),(y+10));
line(x+20,y+10,x+20,y);
arc(x+43,y,0,360,2);
line(x+45,y,x+64,y);
//normal switch
line(x+10,y,x+10,y+30);
line(x+10,y+30,x+64,y+30);
}
void NAND(short x,short y){
for(int i=0;i<4;i++){
line(x-10,y+3+i*10,x,y+3+i*10);
}
line(x,y,x,y+35);
line(x,y,x+25,y);
arc(x+25,y+17.5,-90,90,17.5);
line(x,y+35,x+25,y+35);
circle(x+42.5+3,y+17.5,3);
line(x+48.5,y+17.5,x+63.5,y+17.5);
outtextxy(370,40,"0");
outtextxy(370,85,"1");
outtextxy(370,130,"2");
outtextxy(370,175,"3");
outtextxy(370,220,"4");
outtextxy(370,265,"5");
outtextxy(370,310,"6");
outtextxy(370,355,"7");
outtextxy(370,400,"8");
outtextxy(370,445,"9");
}
void LINES(short x,short y){
short const r=2;//value common radius intersection point
//Not A;
line(x,y,x+110,y);
line(x+110,y,x+110,y-90);
line(x+110,y-90,x+125,y-90);
line(x+110,y,x+125,y);
for(int i=0;i<3;i++){
line(x+110,y+90*i,x+110,y+90+90*i);
line(x+110,y+90+90*i,x+125,y+90+90*i);
fillellipse(x+110,y+90*i,r,r);
}
//A;
line(x,y+30,x,y+45);
line(x,y+45,x+125,y+45);

line(x+125,y+30,x+125,y-45);
line(x+125,y+30,x+125,y+45);
for(i=0;i<3;i++){
line(x+125,y+45+90*i,x+125,y+135+90*i);
line(x+125,y+135+90*i,x+125,y+135+90*i);
fillellipse(x+125,y+45+90*i,r,r);
}
//Not B;
short const k=80;
line(x,y+55,x+k,y+55);
line(x+k,y-80,x+k,y+325);
for(i=0;i<3;i++){
line(x+k,y-80+180*i,x+125,y-80+180*i);
line(x+k,y-35+180*i,x+125,y-35+180*i);
}
fillellipse(x+k,y+55,r,r);
fillellipse(x+k,y-35,r,r);
fillellipse(x+k,y+100,r,r);
fillellipse(x+k,y+145,r,r);
fillellipse(x+k,y+280,r,r);
//B;
short const l=95;
line(x,y+85,x+l,y+85);
fillellipse(x+l,y+85,r,r);
line(x+l,y+235,x+l,y+10);
line(x+l,y+10,x+125,y+10);
line(x+l,y+55,x+125,y+55);
fillellipse(x+l,y+55,r,r);
line(x+l,y+190,x+125,y+190);
fillellipse(x+l,y+190,r,r);
line(x+l,y+235,x+125,y+235);
//C;
short const m=65;
line(x,y+140,x+m,y+140);
fillellipse(x+m,y+140,r,r);
line(x+m,y+245,x+m,y+110);
for(i=0;i<4;i++){
line(x+m,y+110+45*i,x+125,y+110+45*i);
}
fillellipse(x+m,y+155,r,r);
fillellipse(x+m,y+200,r,r);
//Not C;
short const n=50;
line(x,y+110,x+n,y+110);
fillellipse(x+n,y+110,r,r);
line(x+n,y+335,x+n,y-70);
line(x+n,y-70,x+125,y-70);
for(i=0;i<3;i++){
line(x+n,y-25+i*45,x+125,y-25+i*45);
}
fillellipse(x+n,y-25,r,r);
fillellipse(x+n,y+20,r,r);
fillellipse(x+n,y+65,r,r);
fillellipse(x+n,y+290,r,r);
line(x+n,y+290,x+125,y+290);
line(x+n,y+335,x+125,y+335);
//D;
short const o=10;
line(x,y+195,x+o,y+195);
fillellipse(x+o,y+195,r,r);
line(x+o,y+195,x+o,y+345);
for(i=0;i<2;i++){
line(x+o,y+300+45*i,x+125,y+300+45*i);
}
fillellipse(x+o,y+300,r,r);
//Not D;
short const p=25;
line(x,y+165,x+p,y+165);
line(x+p,y+255,x+p,y-60);
line(x+p,y-60,x+125,y-60);
for(i=0;i<7;i++){
line(x+p,y-15+i*45,x+125,y-15+i*45);
fillellipse(x+p,y-15+i*45,r,r);
}
}
void NOT_CONV(short a,short b,short c,short d){
if(a==0){
	outtextxy(105,110,"0");
	outtextxy(150,110,"1");
	}
	else {
	outtextxy(105,110,"1");
	outtextxy(150,110,"0");
	}
if(b==0){
	outtextxy(105,165,"0");
	outtextxy(150,165,"1");
	}
	else {
	outtextxy(105,165,"1");
	outtextxy(150,165,"0");
	}
if(c==0){
	outtextxy(105,220,"0");
	outtextxy(150,220,"1");
	}
	else {
	outtextxy(105,220,"1");
	outtextxy(150,220,"0");
	}
if(d==0){
	outtextxy(105,275,"0");
	outtextxy(150,275,"1");
	}
	else {
	outtextxy(105,275,"1");
	outtextxy(150,275,"0");
	}
f[0]=!((!a)*(!b)*(!c)*(!d));
f[1]=!((a)*(!b)*(!c)*(!d));
f[2]=!((!a)*(b)*(!c)*(!d));
f[3]=!((a)*(b)*(!c)*(!d));
f[4]=!((!a)*(!b)*(c)*(!d));
f[5]=!((a)*(!b)*(c)*(!d));
f[6]=!((!a)*(b)*(c)*(!d));
f[7]=!((a)*(b)*(c)*(!d));
f[8]=!((!a)*(!b)*(!c)*(d));
f[9]=!((a)*(!b)*(!c)*(d));
setcolor(13);
LINES(100+64,120);
}
void Start_NAND(){
setcolor(12);
LINES(100+64,120);
for(int i=0;i<10;i++){
	int	x=300,
			y=27.5+i*45;
	for(int j=0;j<4;j++) line(x-10,y+3+j*10,x,y+3+j*10);
	}
if(a==0){outtextxy(305,28,"1");delay(200);
				outtextxy(305,28+90,"1");delay(200);
				outtextxy(305,28+90+90,"1");delay(200);
				outtextxy(305,28+90+90+90,"1");delay(200);
				outtextxy(305,28+90+90+90+90,"1");
				outtextxy(305,28+45,"0");delay(200);
				outtextxy(305,28+45+90,"0");delay(200);
				outtextxy(305,28+45+90+90,"0");delay(200);
				outtextxy(305,28+45+90+90+90,"0");delay(200);
				outtextxy(305,28+45+90+90+90+90,"0");delay(200);
				}
	else {outtextxy(305,28,"0");delay(200);
				outtextxy(305,28+90,"0");delay(200);
				outtextxy(305,28+90+90,"0");delay(200);
				outtextxy(305,28+90+90+90,"0");delay(200);
				outtextxy(305,28+90+90+90+90,"0");
				outtextxy(305,28+45,"1");delay(200);
				outtextxy(305,28+45+90,"1");delay(200);
				outtextxy(305,28+45+90+90,"1");delay(200);
				outtextxy(305,28+45+90+90+90,"1");delay(200);
				outtextxy(305,28+45+90+90+90+90,"1");delay(200);
				}
if(b==0){outtextxy(305,37.5,"1");delay(200);
				outtextxy(305,37.5+45,"1");delay(200);
				outtextxy(305,37.5+45+135,"1");delay(200);
				outtextxy(305,37.5+45+135+45,"1");delay(200);
				outtextxy(305,37.5+45+135+45+135,"1");delay(200);
				outtextxy(305,37.5+45+135+45+135+45,"1");delay(200);
				outtextxy(305,37.5+90,"0");delay(200);
				outtextxy(305,37.5+90+45,"0");delay(200);
				outtextxy(305,37.5+90+45+135,"0");delay(200);
				outtextxy(305,37.5+90+45+135+45,"0");delay(200);
				}
	else {outtextxy(305,37.5,"0");delay(200);
				outtextxy(305,37.5+45,"0");delay(200);
				outtextxy(305,37.5+45+135,"0");delay(200);
				outtextxy(305,37.5+45+135+45,"0");delay(200);
				outtextxy(305,37.5+45+135+45+135,"0");delay(200);
				outtextxy(305,37.5+45+135+45+135+45,"0");delay(200);
				outtextxy(305,37.5+90,"1");delay(200);
				outtextxy(305,37.5+90+45,"1");delay(200);
				outtextxy(305,37.5+90+45+135,"1");delay(200);
				outtextxy(305,37.5+90+45+135+45,"1");delay(200);
				}
if(c==0){outtextxy(305,47.5,"1");delay(200);
				outtextxy(305,47.5+45,"1");delay(200);
				outtextxy(305,47.5+90,"1");delay(200);
				outtextxy(305,47.5+90+45,"1");delay(200);
				outtextxy(305,47.5+90+90+90+90,"1");delay(200);
				outtextxy(305,47.5+90+90+90+90+45,"1");delay(200);
				outtextxy(305,47.5+90+90,"0");delay(200);
				outtextxy(305,47.5+90+90+45,"0");delay(200);
				outtextxy(305,47.5+90+90+90,"0");delay(200);
				outtextxy(305,47.5+90+90+90+45,"0");delay(200);
				}
	else {outtextxy(305,47.5,"0");delay(200);
				outtextxy(305,47.5+45,"0");delay(200);
				outtextxy(305,47.5+90,"0");delay(200);
				outtextxy(305,47.5+90+45,"0");delay(200);
				outtextxy(305,47.5+90+90+90+90,"0");delay(200);
				outtextxy(305,47.5+90+90+90+90+45,"0");delay(200);
				outtextxy(305,47.5+90+90,"1");delay(200);
				outtextxy(305,47.5+90+90+45,"1");delay(200);
				outtextxy(305,47.5+90+90+90,"1");delay(200);
				outtextxy(305,47.5+90+90+90+45,"1");delay(200);
				}
if(d==0){outtextxy(305,56,"1");delay(200);
				outtextxy(305,56+45,"1");delay(200);
				outtextxy(305,56+90,"1");delay(200);
				outtextxy(305,56+90+45,"1");delay(200);
				outtextxy(305,56+90+90,"1");delay(200);
				outtextxy(305,56+90+90+45,"1");delay(200);
				outtextxy(305,56+90+90+90,"1");delay(200);
				outtextxy(305,56+90+90+90+45,"1");delay(200);
				outtextxy(305,56+90+90+90+90,"0");delay(200);
				outtextxy(305,56+90+90+90+90+45,"0");delay(200);
				}
else 	 {outtextxy(305,56,"0");delay(200);
				outtextxy(305,56+45,"0");delay(200);
				outtextxy(305,56+90,"0");delay(200);
				outtextxy(305,56+90+45,"0");delay(200);
				outtextxy(305,56+90+90,"0");delay(200);
				outtextxy(305,56+90+90+45,"0");delay(200);
				outtextxy(305,56+90+90+90,"0");delay(200);
				outtextxy(305,56+90+90+90+45,"0");delay(200);
				outtextxy(305,56+90+90+90+90,"1");delay(200);
				outtextxy(305,56+90+90+90+90+45,"1");delay(200);
				}
}
//Result;
void Result(){
delay(200);
for(int i=0;i<10;i++){
	if(f[i]==0)
		outtextxy(350,30+45*i,"0");
	else outtextxy(350,30+45*i,"1");
	}
delay(150);
char *output[]={"0","1","2","3","4","5","6","7","8","9"};
settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
setcolor(2);
outtextxy(400,200,"Your output is: ");
for(i=0;i<10;i++){
	if(f[i]==0)
		outtextxy(555,200,output[i]);
	}
}