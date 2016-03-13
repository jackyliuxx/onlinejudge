#include<iostream>
#include<queue>
using namespace std;
int main(){
	int x,y,a[10000]={},p=0;
	char m;
	while(cin>>a[p++]){
		do{
			if(isdigit(cin.peek()))
				cin>>a[p++];
			cin.get(m);
			if(m=='+'){
				a[p-2]=a[p-2]+a[p-1];
				p--;
			}
			if(m=='-'){
				a[p-2]=a[p-2]-a[p-1];
				p--;
			}
			if(m=='*'){
				a[p-2]=a[p-2]*a[p-1];
				p--;
			}
			if(m=='/'){
				a[p-2]=a[p-2]/a[p-1];
				p--;
			}
			if(m=='%'){
				a[p-2]=a[p-2]%a[p-1];
				p--;
			}
		}while(m!='\n');
			cout<<a[--p]<<endl;
	}
}