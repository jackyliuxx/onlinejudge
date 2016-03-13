#include<iostream>
#include<stdio.h>
using namespace std;
int a[310][310];
int main() {
	int t,m,n,x[50],y[50],i,j,k,ans;
	cin>>t;
	while(t--) {
		cin>>n>>m;
		for(i=0; i<310; i++)
			for(j=0; j<310; j++)
				a[i][j]=-1;
		a[0][0]=0;
		for(i=0; i<n; i++)
			cin>>x[i]>>y[i];
		for(i=0; i<n; i++)
			for(j=0; j<=m-x[i]; j++)
				for(k=0; k<=m-y[i]; k++)
					if(a[j][k]!=-1)
                        if(a[j+x[i]][k+y[i]]==-1 || a[j+x[i]][k+y[i]]>a[j][k]+1)
                            a[j+x[i]][k+y[i]]=a[j][k]+1;
		ans=999999;
		for(i=0; i<=m; i++)
			for(j=0; j<=m; j++)
				if(a[i][j]!=-1 && i*i+j*j==m*m && a[i][j]<ans)
					ans=a[i][j];
		if(ans==999999)
			printf("not possible\n");
		else
			printf("%d\n",ans);
	}
}
