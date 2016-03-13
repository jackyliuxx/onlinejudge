#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int main(){
	int i,y1,m1,d1,y2,m2,d2,t1,t2;
	int month[12]={0,31,28,31,30,31,30,31,31,30,31,30};
	while(cin>>y1>>m1>>d1>>y2>>m2>>d2){
		t1=t2=0;
		t1+=(y1-1)*365+(y1-1)/4-(y1-1)/100+(y1-1)/400;
		t2+=(y2-1)*365+(y2-1)/4-(y2-1)/100+(y2-1)/400;
		if(((y1%4==0 && y1%100) || y1%400==0 ) && m1>2)
			t1++;
		if(((y2%4==0 && y2%100) || y2%400==0 ) && m2>2)
			t2++;
		for(i=1;i<m1;i++)
			t1+=month[i];
		for(i=0;i<m2;i++)
			t2+=month[i];
		t1+=d1;
		t2+=d2;
		printf("%d\n",abs(t1-t2));
	}
}