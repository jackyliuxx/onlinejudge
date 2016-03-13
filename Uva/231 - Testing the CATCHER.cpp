#include<iostream>
#include<stdio.h>
#include<cmath>
#include<vector>
using namespace std;
vector<int> a;
int LIS(int n){
	int i;
	for(i=0;i<a.size();i++){
		if(a[i]<n){
			a[i]=n;
			return i;
		}
	}
	if(i==a.size())
		a.push_back(n);
	return 0;
}

int main(){
	int k=1,n,i;
	while(scanf("%d",&n),n>=0){
		a.clear();
		a.push_back(n);
		while(scanf("%d",&n),n>=0)
			LIS(n);
		if(k>1)
			puts("");
		printf("Test #%d:\n  maximum possible interceptions: %d\n",k++,a.size());
	}
}