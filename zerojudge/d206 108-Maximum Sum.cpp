#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int main(){
	int n,a[100][100],t,ans,now,i,k,l,j,b[101][101]={};
	while(cin>>n){
		ans=0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&a[i][j]),ans+=a[i][j];
			}
		}
		for(i=0;i<n;i++){
			now=0;
			for(j=0;j<n;j++){
				for(k=0;k<=i;k++)
					now+=a[k][j];
				b[i+1][j+1]=now;
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				for(k=i;k<n;k++){
					for(l=j;l<n;l++){
						now=b[k+1][l+1]-b[i][l+1]-b[k+1][j]+b[i][j];
						ans=max(now,ans);
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}