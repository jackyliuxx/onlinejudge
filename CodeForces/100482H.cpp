#include<bits/stdc++.h>
using namespace std;

int d[11000];

int fd(int x){
	return d[x]==x ? x : d[x]=fd(d[x]);
}

void uni(int x,int y){
	d[fd(x)]=fd(y);
}

int main(){
	int t,tk=1;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			d[i]=i;
		while(m--){
			int x,y;
			cin>>x>>y;
			uni(x,y);
		}
		int tm[11000]={};
		for(int i=1;i<=n;i++)
			tm[fd(i)]++;
		printf("Case #%d:\n",tk++);
		for(int i=1;i<=n;i++){
			if(i>1)
				putchar(' ');
			printf("%d",tm[fd(i)]-1);
		}
		puts("");
	}
}
