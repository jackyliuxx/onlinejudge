#include<bits/stdc++.h>
using namespace std;
static int n,p[514],a[514][514];
bool hs[514];

void gg(int x){
	if(hs[x])
		return;
	hs[x]=true;
	for(int i=0;i<n;i++)
		if(a[x][i])
			gg(i);
}

struct wt{
	int x,y;
	wt(){}
	wt(int _x,int _y):x(_x),y(_y){}
	bool operator<(const wt b)const{
		return x<b.x;
	}
};

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",p+i);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%1d",&a[i][j]);
	for(int i=0;i<n;i++){
		memset(hs,0,sizeof(hs));
		gg(i);
		for(int j=0;j<n;j++)
			if(hs[j])
				a[i][j]=a[j][i]=1;
	}
	/*
	puts("---");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<a[i][j];
		puts("");
	}
	puts("---");
	*/
	wt w[514];
	for(int i=0;i<n;i++)
		w[i]=wt(p[i],i);
	sort(w,w+n);
	/*
	puts("***");
	for(int i=0;i<n;i++)
		cout<<w[i].x<<' ';
	cout<<endl;
	puts("***");
	*/
	int ans[514]={};
	for(int i=0;i<n;i++)
		ans[i]=-1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[w[i].y][j] && ans[j]==-1){
				ans[j]=w[i].x;
				break;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(i)
			putchar(' ');
		printf("%d",ans[i]);
	}
	puts("");
}
