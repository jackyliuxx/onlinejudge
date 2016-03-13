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
string s[10000],ans,now;

void cp(int n){
	int i;
	now="";
	for(i=0;i<n;i++)
		now+=s[i];
}

int main () {
	int n;
	while(cin>>n){
		int i;
		ans="";
		for(i=0;i<n;i++)
			cin>>s[i];
		sort(s,s+n);
		do{
			cp(n);
			if(now>ans)
				ans=now;
		}while(next_permutation(s,s+n));
		cout<<ans<<endl;
	}
}
