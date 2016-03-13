#include<iostream>
#include<stdio.h>
#include<map>
#include<string>
using namespace std;
int main(){
	int n,k;
	string s;
	map<string,int> m;
	map<string,int>::iterator i;
	cin>>n;
	cin>>ws;
	while(n--){
		k=0;
		m.clear();
		while(getline(cin,s),s!="")
			m[s]++,k++;
		for(i=m.begin();i!=m.end();i++){
			cout<< (i->first) <<' ';
			printf("%.4lf\n",double (i->second)*100 / k);
		}
	}
}