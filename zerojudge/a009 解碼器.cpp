#include<iostream>
using namespace std;
int main(){
	char a,b;
	while(cin.get(a)){
		if(a!=10)
			b=a-7;
		else
			b=a;
		cout<<b;
	}
}