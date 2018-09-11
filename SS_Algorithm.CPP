#include<iostream.h>
#include<conio.h>
void main(){
clrscr();
int CH=500,HL=300,LI=450,CL=300,HM=700,ML=500,MI=800,CI=400;
int edge[]={CH,HL,LI,CL,HM,ML,MI,CI};
cout<<"This program will compute the least connection:";
cout<<"\nFrom laboratories C,H,L,M and I of Norton University.";
cout<<"\n\nThere are 5 nodes in this network and 8 arcs in total:";
cout<<"\n\tCH=500, HL=300, LI=450, CL=300, HM=700, ML=500, MI=800, CI=400";
//choose arc of least weight
int i,key;
cout<<"\nWe sort the number:\n";
for(int j=1;j<8;j++){
	key=edge[j];
	i=j-1;
	while(i>=0&&edge[i]>key){
		edge[i+1]=edge[i];
		i=i-1;
		edge[i+1]=key;
	}
}
int count=0;
for(i=0;i<8;i++){
	cout<<"\t["<<edge[i]<<"]";
	if(edge[0]==edge[i])count+=1;
}
cout<<"\n\t HL,\t CL,\t CI,\t LI,\t CH,\t ML,\t HM,\t MI";
cout<<"\n\nSo,we have a nearest distance among these labs: "<<edge[0];
cout<<" meters";
if(count>1)cout<<"\nWe have "<<count<<" least weight edges.";
textcolor(139);
cout<<"\nWe choose connection from H to L.";cprintf("  [HL]");
cout<<"\nWe choose connection from C to L.";cprintf("  [CL]");
CH=0;
cout<<"\n\t\t\tWe have HL,CL, so we don't need CH (CH=0)";
cout<<"\nThen,";
cout<<"\nWe choose connection from C to I.";cprintf("  [CI]");
LI=0;
cout<<"\n\t\t\tWe have LC,CI, so we don't need LI (LI=0)";
cout<<"\nThen,";
cout<<"\nWe choose connection from M to L.";cprintf("  [ML]");
cout<<"\nAll nodes are connected...";
HM=MI=0;
cout<<"\n\t\t\tAll the rested edges are opted out (HM=MI=0)";
int Sum;
Sum=CH+HL+LI+CL+HM+ML+MI+CI;
cout<<"\n\nFinally, we found the distance of least connection: "<<Sum<<" meters";
getch();
}