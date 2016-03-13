#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct student{
	char name;
	int number,tall;
};
bool number(student a,student b){
	if(a.number < b.number)
		return true;
	return false;
}
bool tall(student a,student b){
	if(a.tall<b.tall)
		return true;
	else if(a.tall==b.tall && a.number<b.number)
		return true;
	return false;
}
int main(){
	int i,m,n;
	student stu[6];
	scanf("%d%d",&m,&n);
	for(i=0;i<6;i++)
		scanf(" %c%d%d",&stu[i].name,&stu[i].number,&stu[i].tall);
	if(m%2)
		sort(stu,stu+6,number);
	else
		sort(stu,stu+6,tall);
	printf("%c\n",stu[(8-n)%6].name);
}