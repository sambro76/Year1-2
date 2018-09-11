#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<ctype.h>
#include<stdlib.h>
int ID,i,j,n,x[50];
void Today(),Input(),Output1(),Output2(),Output3();
class data{
public:
char Name[20],ID[20],Sex[10],Na_ty[20];
char DOB[10],MOB[10],YOB[10],POB[10],From[10];
char DOBox[20][20],NOM[20][20],POM[20][20];
char result[1][20],KO[10][20];
int Score[20],loss;
}inf[40];
void Today(){
struct date d;
getdate(&d);
cprintf("Today is:%d-%d-%d",d.da_mon,d.da_day,d.da_year);
}
/*The main processing*/
void main(){
char ch;
short item;
Input();
kk:
clrscr();
cout<<"Choose one of the following items...\n";
cout<<"\n\t\t\t\t0.Press 0 to exit now.";
cout<<"\n\t\t\t\t1.Display some information.";
cout<<"\n\t\t\t\t2.Display in detail.";
cout<<"\n\t\t\t\t3.Report the winner and losser...";
cout<<"\n\t\t\tItem:";cin>>item;
if(item==0){exit(1);}
else if(item==1){Output1();getch();}
else if(item==2){Output2();getch();}
else if(item==3){Output3();}
else {cout<<"Nothing to display...";getch();goto kk;}
do{
cout<<"\n\n\t\tDo you want to display more(Y\\N):";
ch=toupper(getch());}
while(ch!='Y'&&ch!='N');
if(ch=='Y') goto kk;
}
/*The main input*/
void Input(){
jj:
clrscr();
Today();
gotoxy(25,2);
cout<<"THIS IS KHMER MARTIAL ART FEDERATION";
cout<<"\n\nInput number of boxers:";cin>>n;
if(n<=0){cout<<"\t\t\tInvalid Number, NO DATA TO RECORD!!!";getch();goto jj;}
for(int i=0;i<n;i++){
clrscr();
gotoxy(25,2);
cout<<"THIS IS KHMER MARTIAL ART FEDERATION";
	cout<<"\n\nCANDIDATE["<<i+1<<"]:";
	cout<<"\n\tName:";cin>>inf[i].Name;
	cout<<"\tID:";cin>>inf[i].ID;
	cout<<"\tSex:";cin>>inf[i].Sex;
	cout<<"\tNationality:";cin>>inf[i].Na_ty;
	cout<<"\tDate of Birth:";
	cout<<"\n\t\tMonth(MM): ";cin>>inf[i].MOB;
	cout<<"\t\tDate(DD):  ";cin>>inf[i].DOB;
	cout<<"\t\tYear(YYYY):";cin>>inf[i].YOB;
	cout<<"\tPlace of Birth:";cin>>inf[i].POB;
	cout<<"\tComing From:";cin>>inf[i].From;
kk:
cout<<"\tHow many times of Matches:";cin>>x[i];
if(x[i]<1){cout<<"Nothing to record!!!\nPlease reinput";goto kk;}
else{
 for(j=0;j<x[i];j++){
	cout<<"\t\tTime["<<j+1<<"]:";
	cout<<"\tDated on:";cin>>inf[i].DOBox[j];
	cout<<"\t\tV.S.:";cin>>inf[i].NOM[j];
	cout<<"\t\tPlace of match:";cin>>inf[i].POM[j];
  ll:
	cout<<"\t\tWin or Lose:";cin>>inf[i].result[j];
  if(stricmp(inf[i].result[j],"w")==0){
	cout<<"\n\t\t\t\tWin: YES"<<endl;
	mm:
	cout<<"\t\t\t\tK.O.(Y\\N):";cin>>inf[i].KO[j];
	if(stricmp(inf[i].KO[j],"y")==0){;}
	else if(stricmp(inf[i].KO[j],"n")==0){
	cout<<"\t\t\t\tLast Score:";cin>>inf[i].Score[j];}
	else {cout<<"\n\t\t\t\t\tPlease retype...";goto mm;}
	}
  else if(stricmp(inf[i].result[j],"l")==0){
	inf[i].loss=inf[i].loss+1;
	cout<<"\n\t\t\t\tWin: NO"<<endl;
	nn:
	cout<<"\t\t\t\tBeen K.O.(Y\\N):";cin>>inf[i].KO[j];
	if(stricmp(inf[i].KO[j],"y")==0){;}
	else if(stricmp(inf[i].KO[j],"n")==0){
		strcpy(inf[i].KO[j],"Been lost by scores...");}
	else {cout<<"\n\t\t\t\t\tPlease retype...";goto nn;}
	}
  else {cout<<"\n\tPlease reinput the result!!";goto ll;}
	}
  }
clrscr();
}
}
/*The same output*/
void Same(){
clrscr();
struct date d;
getdate(&d);
cout<<"\n\nPlease input ID to show the report:";cin>>ID;
for(i=0;i<n;i++)
  if(atoi(inf[i].ID)==ID){
	cout<<"\n\tName:          "<<inf[i].Name;
	cout<<"\n\tSex:           "<<inf[i].Sex;
	if(d.da_mon>atoi(inf[i].MOB))
	cout<<"\n\tAge:           "<<(d.da_year-atoi(inf[i].YOB)+1)<<" years old"<<endl;
	else	cout<<"\n\tAge:           "<<(d.da_year-atoi(inf[i].YOB))<<" years old"<<endl;
	cout<<"\tNationality:   "<<inf[i].Na_ty<<endl;
	cout<<"\tFrom CLUB:     "<<inf[i].From<<endl;
  }
}
/*The first output*/
void Output1(){
clrscr();
Same();
for(i=0;i<n;i++){
if(atoi(inf[i].ID)==ID){cout<<"\tTotal Matches: "<<x[i]<<endl;
if(inf[i].loss!=0)cout<<"\n\tLossing Times: "<<inf[i].loss;
else cout<<"\n\tNever lost...";}
}
}
/*The second output*/
void Output2(){
clrscr();
Same();
cout<<"\n\tAll his achievements had been made as the following:";
for(i=0;i<n;i++){
if(atoi(inf[i].ID)==ID){
	for(j=0;j<x[i];j++){
		zz:
		cout<<"\n\n\t\tTime["<<j+1<<"]:";
		cout<<"\tDated on:"<<inf[i].DOBox[j];
		cout<<"\n\t\tV.S.:\t"<<inf[i].NOM[j];
		cout<<"\n\t\tPlace of match:\t\t"<<inf[i].POM[j];
	  if(stricmp(inf[i].result[j],"w")==0){
		cout<<"\n\t\tWin:\t\t\tYES";
		if(stricmp(inf[i].KO[j],"y")){
		cout<<"\n\t\tK.O.:\t\t\tNO";
		cout<<"\n\t\tThe Last Score:\t"<<inf[i].Score[j];
		}
		else	cout<<"\n\t\tK.O.:\t\t\tYES";
		}
	  else{
		cout<<"\n\t\tWin:\t\t\tNO";
		if(stricmp(inf[i].KO[j],"y")){cout<<"\n\t\tBeen K.O.:\t\tYES";}
		else cout<<"\n\t\tBeen K.O.:\t\tNO, by score";
		}
	if(j%2==1){cout<<"\nPress any key to see more...";getch();clrscr();}
	}
  }
}
}
/*The third output*/
void Output3(){
float a,temp,LPercent[50],MAXLOSS,MAXWIN,WPercent[50];
int LCOUNT=0,WCOUNT=0;
//char tmpName[50],tmpID[50];
clrscr();
/*Request the Loss(%)of Boxer*/
	cout<<"The lossing percentages of the Boxer shown as the following:\n\n";
	for(i=0;i<n;i++){
		a=inf[i].loss;
		LPercent[i]=(a/x[i])*100;
		cout<<"\t\tCANDIDATE["<<i+1<<"]: "<<a<<"/"<<x[i]<<" = "
		<<LPercent[i]<<"%\n";
		}
/*Find the most Lossing times of Boxer*/
	MAXLOSS=LPercent[0];
	for(i=0;i<n;i++){
		if(MAXLOSS<=LPercent[i+1]) MAXLOSS=LPercent[i+1];
		else MAXLOSS=MAXLOSS;
		}
	/*Request if there's the same times of lossing*/
	for(i=0;i<n;i++){
		if(MAXLOSS==LPercent[i]) LCOUNT=LCOUNT+1;
		}
	if(LCOUNT>1){
		cout<<"\nSo, we have more and the same time of lossing..";
		for(i=0;i<n;i++)
		if(MAXLOSS==LPercent[i]){
		cout<<"\n\t\t\t\t\tName:\t"<<inf[i].Name;
		cout<<"\n\t\t\t\t\tID:\t"<<inf[i].ID;
		}
		}
	else {
		for(i=0;i<n;i++)
		if(MAXLOSS==LPercent[i]){
		cout<<"\nSo,the Boxer who has the most lossing time is:";
		cout<<"\n\t\t\t\t\tName:\t"<<inf[i].Name;
		cout<<"\n\t\t\t\t\tID:\t"<<inf[i].ID;
		}
		}
cout<<"\n\nPress any key to Continue...\n";
getch();
/*Find the most winning times of Boxer*/
	for(i=0;i<n;i++){
		a=x[i]-inf[i].loss;
		WPercent[i]=(a/x[i])*100;
		}
	MAXWIN=WPercent[0];
	for(i=0;i<n;i++){
		if(MAXWIN<=WPercent[i+1]) MAXWIN=WPercent[i+1];
		else MAXWIN=MAXWIN;
		}
/*Request if there's the same times of winning*/
	for(i=0;i<n;i++){
		if(MAXWIN==WPercent[i]) WCOUNT=WCOUNT+1;
		}
	if(WCOUNT>1){
		cout<<"\nSo, we have more and the same times of winning...";
		for(i=0;i<n;i++)
		if(MAXWIN==WPercent[i]){
		cout<<"\n\t\t\t\t\tName:\t"<<inf[i].Name;
		cout<<"\n\t\t\t\t\tID:\t"<<inf[i].ID;
		}
		}
	else {
		for(i=0;i<n;i++)
		if(MAXWIN==WPercent[i]){
		cout<<"\nSo,the Boxer who has the most winning time is:";
		cout<<"\n\t\t\t\t\tName:\t"<<inf[i].Name;
		cout<<"\n\t\t\t\t\tID:\t"<<inf[i].ID;
		}
		}
}
