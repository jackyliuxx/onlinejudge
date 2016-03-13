#include<iostream>
using namespace std;
int main(){
	int p,i,a[25],n,ans;
	cin>>p;
	for(i=0;i<25;i++)
		cin>>a[i];
	while((p--)-1){
		ans=0;
		for(i=0;i<25;i++){
			cin>>n;
			if(a[i]==1)
				if(n==1)
					ans+=1;
				else
					ans+=7;
			else
				if(n==1)
					ans+=2;
				else
					ans+=5;
			a[i]=n;
		}
		cout<<ans<<endl;
	}
}