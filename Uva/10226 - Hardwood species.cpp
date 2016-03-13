//by jackyliuxx
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <list>
#include <map>
using namespace std;

map<string,int> m;
map<string,int>::iterator it;

int main () {
	int n;
	char gbg[200];
	string x;
	scanf("%d",&n);
	gets(gbg);
	gets(gbg);
	double all=0;
	int bk=0;
	while(getline(cin,x)){
		if(x==""){
			if(bk)
				puts("");
			for(it=m.begin();it!=m.end();it++){
				cout<< it->first << " ";
				printf("%.4lf\n",it->second*100/all);
			}
			m.clear();
			all=0;
			bk=1;
		}
		else{
			all++;
			m[x]++;
		}
	}
	if(all){
		if(bk)
			puts("");
		for(it=m.begin();it!=m.end();it++){
			cout<< it->first << " ";
			printf("%.4lf\n",it->second*100/all);
		}
		m.clear();
		all=0;
	}
}
