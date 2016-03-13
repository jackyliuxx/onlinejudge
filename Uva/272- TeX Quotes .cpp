#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	char c,i=1;
	while(cin.get(c)){
		if(c=='"'){
			if(i)
				printf("``"),i=0;
			else
				printf("''"),i=1;
		}
		else
			printf("%c",c);
	}
}