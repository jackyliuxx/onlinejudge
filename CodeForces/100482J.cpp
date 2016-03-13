#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,tk=1;
	cin>>t;
	while(t--){
		int n,a[128];
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		int ans=0;
		int pi=-1;
		for(int i=n-1;i>=0;i--){
			if(a[i]==pi)
				continue;
			pi=a[i];
			int pj=-1;
			for(int j=0;j<i;j++){
				if(a[j]==pj)
					continue;
				pj=a[j];
				int pk=-1;
				for(int k=j+1;k<i;k++){
					if(a[k]==pk)
						continue;
					pk=a[k];
					if(a[j]+a[k]>a[i])
						ans++;
				}
			}
		}
		printf("Case #%d: %d\n",tk++,ans);
	}
}
