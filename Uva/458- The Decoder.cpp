#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
	char c;
	while(cin.get(c))
		printf("%c",(c=='\n' ? c : c-7));
}