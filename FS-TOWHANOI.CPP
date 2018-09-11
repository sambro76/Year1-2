// Tower of Hanoi (recursive)
#include <iostream.h>
#include <conio.h>
typedef char column;
int n;
void change(column x,column y){
cout <<"Change disk " <<x<<" to "<<y<<"\n";
}
void change_column(int n,column a,column b,column c){
if (n>0){
			change_column (n-1, a, c, b);
			change (a,c);
			change_column (n-1, b, a, c);
	}
}
void main(){
clrscr ();
cout<<"Input the number of disk N = ";
cin>>n;
cout<<endl;
change_column (n, 'A', 'B', 'C');
getch();
}
