#include<bits/stdc++.h>
using namespace std;

bool cmp(char a[],char b[],int n,int mk[]){
	for(int i=0;i<n;i++){
		if(mk[i])
			continue;
		if(a[i]>b[i])
			return true;
		if(a[i]<b[i])
			return false;
	}
	return false;
}

int gd(char a[][110],int x,int n,int m,int mk[]){
	if(x==m)
		return 0;
	for(int i=0;i<n;i++){
		if(cmp(a[i-1],a[i],x+1,mk)){
			mk[x]=1;
			return 1+gd(a,x+1,n,m,mk);
		}
	}
	return gd(a,x+1,n,m,mk);
}

int main(){
	int n,m;
	char a[110][110];
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	int mk[110]={};
	cout<<gd(a,0,n,m,mk)<<endl;
}
