#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<ctype.h>
int n,x,y,dx,dy,df,dF,midx,midy,d,m;
void Logo(){
midx=getmaxx()/2;
midy=getmaxy()/2;
initgraph(&d,&m,"d:\\TC\\BGI");
settextjustify(CENTER_TEXT,CENTER_TEXT);
for(int i=0;i<10;i++){
cleardevice();
settextstyle(1,HORIZ_DIR,i);
setcolor(8);outtextxy(midx,midy-40,"Norton University");
outtextxy(midx,midy-39,"Norton University");
setcolor(15);outtextxy(midx+1,midy-39,"Norton University");
outtextxy(midx+2,midy-38,"Norton University");
setcolor(7);outtextxy(midx+1,midy-39,"Norton University");
delay(350);
}
}
void Present(){
midx=getmaxx()/2;
midy=getmaxy()/2;
Logo();
for(int j=0;j<=100;j++){
cleardevice();
ellipse(midx,midy,0,360,200,350);
ellipse(midx,midy,0,360,199,349);
settextstyle(2,HORIZ_DIR,5);
setcolor(11);outtextxy(midx,midy-80-j,"Department of Computer Science");
setcolor(11);outtextxy(midx,midy-40-j,"Year I");
outtextxy(midx,midy-j,"Semester II");
outtextxy(midx,midy+40-j,"Session Evening");
setcolor(12);outtextxy(midx,midy+80-j,"Instructor by Mr.Long Chantirith");
outtextxy(midx,midy+120-j,"Prepared by Chay Samnang  ID: 3947");
delay(10);
}
settextstyle(1,0,1);
for(int i=0;i<=45;i++){
setcolor(i+1);
outtextxy(midx,midy+70,"ELECTRONIC ASSIGNMENT");
delay(10);}
setcolor(9);
settextstyle(2,0,4);
outtextxy(midx,midy+110,"Please press any key to see");
delay(50);
settextstyle(2,0,4);
outtextxy(midx-75,midy+150,"The");
settextstyle(10,0,2);
outtextxy(midx,midy+150,"Diagram");
getch();
}

void Transformer(){//line on side
 line(20,165,20,175);
 line(20,165,30,165);
 line(20,175,30,175);
 line(30,165,30,175);
 line(30,170,40,170);
 arc(42,170,360,0,2);
 line(44,170,55,160);
 arc(57,170,360,0,2);
 line(59,170,80,170);
 //line under side
 line(20,285,20,295);
 line(20,285,30,285);
 line(20,295,30,295);
 line(30,285,30,295);
 line (30,290,80,290);
//draw arc
 for(int i=0;i<=110;){
 arc (80,175+i,270,90,5);
 i+=10;}
//line trans.
 line (90,170,90,290);
 line (95,170,95,290);
//draw arc
 for(i=0;i<=110;){
 arc (105,175+i,90,270,5);
 i+=10;}
 line (105,170,160,170);
 line (105,230,350,230);
 line (350,230,350,240);
 line (345,240,355,240);
 line (347,242,353,242);
 line (105,290,160,290);//line after trans.
 }
void diode_drawing(int x,int y,int dx,int dy)
 {
 line(x,y,x,y+dy);
 line(x,y,x,y-dy);
 line(x,y-dy,x+dx,y);
 line(x,y+dy,x+dx,y);
 line(x+dx+2,y,x+dx+2,y+dy);
 line(x+dx+2,y,x+dx+2,y-dy);
 }
void diode_reversed(int x,int y,int dx,int dy)
 {
 line(x,y,x,y+dy);
 line(x,y,x,y-dy);
 line(x+2,y,x+2+dx,y-dy);
 line(x+2,y,x+2+dx,y+dy);
 line(x+2+dx,y,x+2+dx,y+dy);
 line(x+2+dx,y,x+2+dx,y-dy);
 }
void diodeLed_drawing(int x,int y,int dx,int dy)
 {
 line(x,y,x+dx,y);
 line(x,y,x-dx,y);
 line(x+dx,y,x,y+dy);
 line(x-dx,y,x,y+dy);
 line(x,y+dy+2,x+dx,y+dy+2);
 line(x,y+dy+2,x-dx,y+dy+2);
 }
void resistance(int x,int y,int dF,int df)
 {
 line(x,y,x,y+df);
 line(x,y,x+dF,y);
 line(x,y+df,x+dF,y+df);
 line(x+dF,y,x+dF,y+df);
 }
void main(){
initgraph(&d,&m,"d:\\tc\\bgi");
Present();
kk:
cleardevice();
settextstyle(0,0,1);
setcolor(15);
Transformer();
line(150,120,150,265);
//d1
line(150,120,170,120);
diode_drawing(170,120,5,5);
line(177,120,200,120);
outtextxy(167,105,"D1");
//d3
line(160,170,170,170);
diode_drawing(170,170,5,5);
line(177,170,190,170);
outtextxy(167,155,"D3");
//d7
 line(150,265,170,265);
 diode_reversed(170,265,5,5);
 line(177,265,190,265);
 outtextxy(167,250,"D7");
 //d4
 line(190,170,190,200);
 line(190,200,177,200);
 diode_drawing(170,200,5,5);
 line(170,200,160,200);
 outtextxy(167,185,"D4");
 //d9
 line(160,200,160,330);
 line(160,330,170,330);
 diode_drawing(170,330,5,5);
 line(177,330,200,330);
 line(200,120,200,330);
 outtextxy(167,315,"D9");
 //d8
 line(160,290,170,290);
 diode_reversed(170,290,5,5);
 line(177,290,190,290);
 line(190,265,190,290);
 outtextxy(167,275,"D8");
 //end diode
 //R1
 line(200,120,280,120);
 resistance(280,116,30,8);
 line(310,120,350,120);
 outtextxy(290,105,"R1");
 //dc +5v
 line(350,115,360,115);
 line(350,115,350,125);
 line(350,125,360,125);
 line(360,115,360,125);
 outtextxy(340,130,"+5V");
 //R2
 line(260,120,260,130);
 resistance(256,130,8,30);
 line(260,160,260,230);
 settextstyle(0,1,1);
 outtextxy(275,135,"R2");
 //C1
 line(320,120,320,140);
 line(312,140,328,140);
 arc(320,160,60,120,15);
 line(320,145,320,230);
 line(190,170,350,170);
 outtextxy(315,125,"C1");
 //dc +12v
 line(350,165,360,165);
 line(350,165,350,175);
 line(350,175,360,175);
 line(360,165,360,175);
 settextstyle(0,0,1);
 outtextxy(340,180,"+12V");
 //C2
 settextstyle(0,1,1);
 line(220,170,220,195);
 line(212,195,228,195);
 arc(220,215,60,120,15);
 line(220,200,220,230);
 outtextxy(210,190,"C2");
 //R4
 line(245,170,245,185);
 resistance(241,185,8,30);
 line(245,215,245,230);
 outtextxy(240,190,"R4");
 //C5
 line(220,230,220,255);
 line(212,255,228,255);
 arc(220,275,60,120,15);
 line(220,260,220,290);
 outtextxy(210,250,"C5");
 //R3
 line(245,230,245,245);
 resistance(241,245,8,30);
 line(245,275,245,290);
 line(190,290,270,290);
 line(300,290,350,290);
 outtextxy(240,250,"R3");
 //line to +12v
 line(245,290,245,340);
 //R'1
 settextstyle(0,0,1);
// line(200,260,280,260);
 resistance(270,286,30,8);
 line(310,120,350,120);
 outtextxy(275,275,"R'1");
 settextstyle(0,1,1);
 //C
 line(320,210,320,250);
 arc(320,270,60,120,15);
 line(312,250,328,250);
 line(320,255,320,290);
 outtextxy(315,245,"C");
//dc -5V
 line(350,285,360,285);
 line(350,285,350,295);
 line(350,295,360,295);
 line(360,285,360,295);
 settextstyle(0,0,1);
 outtextxy(340,300,"-5V");
 //line
 line(245,340,350,340);
 //dc -12V
 line(350,335,360,335);
 line(350,335,350,345);
 line(350,345,360,345);
 line(360,345,360,335);
 settextstyle(0,0,1);
 outtextxy(340,350,"-12V");
 //d2
 line(340,170,340,150);
 line(340,150,450,150);
 diode_drawing(450,150,5,5);
 line(457,150,495,150);
 line(495,150,495,170);
 outtextxy(450,165,"d2");
 //R7 - R10
 line(420,170,570,170);
 settextstyle(0,1,1);
 //R7
 line(420,170,420,180);
 resistance(416,180,8,30);
 line(420,210,420,250);
 outtextxy(405,190,"R7");
 //R8
 line(470,170,470,180);
 resistance(466,180,8,30);
 line(470,210,470,270);
 outtextxy(455,190,"R8");
 //R9
 line(520,170,520,180);
 resistance(516,180,8,30);
 line(520,210,520,260);
 outtextxy(505,190,"R9");
 //R10
 line(570,170,570,180);
 resistance(566,180,8,30);
 line(570,210,570,250);
 outtextxy(555,190,"R10");
 // line(380,240,490,240);
 line(380,225,490,225);
 //d6
 line(380,225,380,240);
 diodeLed_drawing(380,240,5,5);
 line(380,247,380,260);
 outtextxy(365,240,"d6");
 //R5
 resistance(376,260,8,30);
 line(380,290,380,310);
 outtextxy(370,270,"R5");
 //d5
 line(610,225,610,240);
 diodeLed_drawing(610,240,5,5);
 line(610,247,610,260);
 outtextxy(595,240,"d5");
 //R6
 resistance(606,260,8,30);
 line(610,290,610,310);
 outtextxy(600,270,"R6");
 //transistor1
 arc(425,260,360,0,10);
 line(430,254,430,266);
 line(420,250,430,258);
 line(430,262,420,270);
 line(420,270,420,310);
 line(430,260,470,260);
 outtextxy(410,290,"C1815");
 //transistor2
 arc(565,260,360,0,10);
 line(560,254,560,266);
 line(570,250,560,258);
 line(560,262,570,270);
 line(570,270,570,310);
 line(520,260,560,260);
 outtextxy(555,290,"C1815");
 //C3
 arc(475,225,330,30,15);
 line(495,217,495,233);
 line(495,225,520,225);
 settextstyle(0,0,1);
 outtextxy(485,240,"C3");
 //C4
 line(470,270,490,270);
 arc(510,270,150,210,15);
 line(490,262,490,278);
 line(495,270,540,270);
 line(540,270,540,225);
 line(540,225,610,225);
 outtextxy(485,280,"C4");
 //line mas
 line(380,310,610,310);
 line(495,310,495,320);
 line(490,320,500,320);
 line(492,322,498,322);
 line(349,244,351,244);
 line(494,324,496,324);
setcolor(YELLOW);
settextstyle(1,0,1);
outtextxy(200,50,"Press any key to run program...");
getch();
//line electric
for(n=0;n<=10;n++){
  setcolor(15);
  line(44,170,55,160+n);
  delay(200);
  setcolor(16);
  line(44,170,55,160+n);
  delay(10);
  }
setcolor(RED);
for(n=1;n<52;n++){
  line(30+n,170,30+n,170);
  delay(10);
  }
settextstyle(0,0,1);
setcolor(15);
line(44,170,55,170);
ellipse(110,170,0,180,7,17);
ellipse(124,170,180,0,7,17);
setcolor(13);
outtextxy(110,160,"+");
outtextxy(125,175,"-");
setcolor(RED);
for(n=1;n<=50;n++){
  line(102+n,170,102+n,170);
  delay(10);
  }
for(n=1;n<=40;n++){
  line(150+n,170,150+n,170);//d2
  line(150,170-n,150,170-n);//d1
  line(150,170+n,150,170+n);//d7
  delay(10);
  }
for(n=1;n<=10;n++){
  line(150,200+n,150,200+n);//d7
  line(150,130-n,150,130-n);//d1
  line(190,170+n,190,170+n);//d2
  delay(10);
  }
for(n=1;n<=30;n++){
  line(190+n,170,190+n,170);//C? R3
  line(190,170+n,190,170+n);//d3
  line(150+n,120,150+n,120);//d1
  line(150,200+n,150,200+n);//d7
  delay(10);
  }
for(n=1;n<=10;n++){
  line(190-n,200,190-n,200);//d3
  line(180+n,120,180+n,120);//d1
  line(150,230+n,150,230+n);//d7
  line(210+n,170,210+n,170);//C? R3
  delay(10);
  }
for(n=1;n<=10;n++){
  line(190+n,120,190+n,120);//d9 R1
  line(220+n,170,220+n,170);//R3
  line(220,170+n,220,170+n);//C1
  line(150,240+n,150,240+n);//d7
  delay(10);
  }
for(n=1;n<=15;n++){
  line(200+n,120,200+n,120);//R1
  line(200,120+n,200,135+n);//d9
  line(150,250+n,150,250+n);//d7
  line(230+n,170,230+n,170);//R3
  line(220,180+n,220,180+n);//C1
  delay(10);
  }
for(n=1;n<=20;n++){
  line(215+n,120,215,120);//R1
  line(200,145+n,200,175+n);//d9
  line(150+n,265,150+n,265);//d7
  line(245,170+n,245,170+n);//R3
  line(245+n,170,245+n,170);//out
  delay(10);
  }
for(n=1;n<=25;n++){
  line(235+n,120,235+n,120);//R1 R2
  line(200,170+n,200,195+n);//d9
  delay(10);
  }
for(n=1;n<=60;n++){
  line(260+n,120,260+n,120);//R1
  line(260,120+n,260,170+n);//R2
  line(200,195+n,200,250+n);//d9
  line(245,170+n,245,170+n);//R3
  line(265+n,170,280+n,170);//out
  delay(10);
  }
for(n=1;n<=20;n++){
  line(320+n,120,330+n,120);//out +5
  line(320,120+n,320,120+n);// C3
  line(200,310+n,200,310+n);//d9
  line(340,170-n,340,170-n);//out
  line(330+n,170,330+n,170);//out +12
  delay(10);
  }
for(n=1;n<=23;n++){
  line(200-n,330,200-n,330);
  delay(10);
  }
for(n=1;n<=110;n++){
  line(340+n,150,340+n,150);
  delay(10);
  }
for(n=1;n<=5;n++){
  diode_drawing(450,150,5,n);
  setcolor(n);
  arc(455,150,360,0,10);
  delay(100);
  }
setcolor(RED);
for(n=1;n<=40;n++){
  line(455+n,150,455+n,150);
  delay(10);
  }
for(n=1;n<=20;n++){
  line(495,150+n,495,150+n);
  delay(10);
  }
for(n=1;n<=75;n++){
  line(495+n,170,495+n,170);//line RL
  line(495-n,170,495-n,170);//line RR
  delay(10);
  }
for(n=1;n<=55;n++){
  line(420,170+n,420,170+n);
  line(470,170+n,470,170+n);
  line(520,170+n,520,170+n);
  line(570,170+n,570,170+n);
  delay(10);
  }
for(n=1;n<=70;n++){
  line(415+n,225,420+n,225);//C?
  line(450-n,225,450-n,225);//d Led
  line(420,180+n,420,180+n);//transistor1
  line(470,200+n,470,200+n);//C?
  delay(10);
  }
for(n=1;n<=15;n++){
  line(470-n,260,445-n,260);//transistor1
  line(380,225+n,380,225+n);//dLed1
  line(470+n,270,475+n,270);
  delay(10);
  }
 //dLed1
for(n=1;n<=5;n++){
  diodeLed_drawing(380,240,5,n);
  setcolor(n);
  arc(380,245,360,0,10);
  delay(100);
  }
setcolor(RED);
for(n=1;n<=40;n++){
  line(380,245+n,380,270+n);//line mas
  line(420,270+n,420,270+n);
  delay(10);
  }
for(n=1;n<=115;n++){
  line(380+n,310,380+n,310);
  delay(10);
  }
for(n=1;n<=40;n++){
  line(520,220+n,520,220+n);//C?
  line(570+n,225,570+n,225);//d Led
  line(570,210+n,570,210+n);//transistor2
  delay(10);
  }
for(n=1;n<=15;n++){
  line(610,225+n,610,225+n);//dLed2
  line(519+2*n,260,530+2*n,260);//transistor2
  delay(10);
  }
//Diode Led1
for(n=1;n<=5;n++){
  diodeLed_drawing(610,240,5,n);
  setcolor(n);
  arc(610,245,360,0,10);
  delay(100);
  }
setcolor(RED);
for(n=1;n<=40;n++){
  line(610,245+n,610,270+n);//line mas
  line(570,270+n,570,270+n);
  delay(10);
  }
for(n=1;n<=115;n++){
  line(610-n,310,610-n,310);
  delay(10);
  }
for(n=1;n<=10;n++){
  line(495,310+n,495,310+n);
  delay(10);
  }
for(n=1;n<=10;n++){
  line(350,240-n,350,240-n);
  delay(10);
  }
for(n=1;n<=110;n++){
  line(350-n,230,350-n,230);
  delay(10);
  }
for(n=1;n<=20;n++){
  line(320,230,320,230+n);
  delay(10);
  }
for(n=1;n<=60;n++){
  line(245,230+n,245,230+n);
  delay(10);
  }
for(n=1;n<=130;n++){
  line(245-n,230,235-n,230);
  line(245+n,290,250+n,290);
  line(245-n,290,235-n,290);
  line(245,290,245,210+n);
  delay(10);
  }
for(n=1;n<=105;n++){
  line(245,340,245+n,340);
  delay(10);
  }
char aa;
do{
setcolor(YELLOW);
settextstyle(1,0,1);
outtextxy(200,450,"Do you want to show again (Y\\N):");
aa=toupper(getch());
if(aa=='Y')goto kk;}
while(aa!='N');
closegraph();
}