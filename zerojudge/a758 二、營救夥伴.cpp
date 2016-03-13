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
using namespace std;

bool rv(int a,int b){
	return a>b;
}

bool vs(vector<int> a,vector<int> b){
	if(a.size()<b.size())
		return true;
	if(a.size()>b.size())
		return false;
	int i;
	for(i=0;i<a.size();i++){
		if(a[i]<b[i])
			return true;
		if(a[i]>b[i])
			return false;
	}
	return true;
}

vector< vector< int > > sans;

int trytry(int *fm,int nm,int m,int s,int nw,int w,int n,vector<int> ans){
	if(nm>=m)
		return 0;
	int rt=0;
	int i;
	for(i=s;i<=n && fm[i]*(m-nm)>=(w-nw);i++){
		if(m-nm==1 && nw+fm[i]==w){
			ans.push_back(fm[i]);
			sans.push_back(ans);
			ans.pop_back();
			rt++;
		}
		else if(nw+fm[i]<w){
			ans.push_back(fm[i]);
			rt+=trytry(fm,nm+1,m,i+1,nw+fm[i],w,n,ans);
			ans.pop_back();
		}
	}
	return rt;
}


int main(){
	vector<int> ans;
	sans.clear();
	int w,n;
	int i,j;
	cin>>w>>n;
	int fm[100];
	for(i=0;i<n;i++)
		cin>>fm[i];
	sort(fm,fm+n,rv);
	int ls,ln;
	for(i=1;i<=n;i++){
		ans.clear();
		ln=trytry(fm,0,i,0,0,w,n,ans);
		if(ln){
			ls=i;
			break;
		}
	}
	for(i=0;i<sans.size();i++)
		sort(sans[i].begin(),sans[i].end());
	sort(sans.begin(),sans.end(),vs);
	printf("%d %d\n",ls,ln);
	for(i=0;i<sans.size();i++){
		for(j=0;j<sans[i].size();j++){
			if(j)
				putchar(' ');
			printf("%d",sans[i][j]);
		}
		puts("");
	}
}



