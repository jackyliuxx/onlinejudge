#include<bits/stdc++.h>
using namespace std;

bool blbl(bool a[][1200],int x,int y){
	if(a[x][y] && a[x+1][y] && a[x][y+1] && a[x+1][y+1])
		return true;
	return false;
}

int main(){
	bool a[1200][1200]={};
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int ans=999999;
	for(int i=0;i<k;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		a[x][y]=true;
		if(blbl(a,x-1,y-1) || blbl(a,x,y-1) || blbl(a,x-1,y) || blbl(a,x,y))
			ans=min(ans,i+1);
	}
	if(ans==999999)
		ans=0;
	printf("%d\n",ans);
}
