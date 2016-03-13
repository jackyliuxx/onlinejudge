#include<iostream>
using namespace std;
int main(){
	int n1,n2,ans,s;
	while(cin>>n1>>n2){
		ans=0;
		for(int i=n1;i<=n2;i++){
			if(i==1)
				continue;
			if(i==2 || i==3 || i==5 || i==7)
				ans++;
			else if(i%2 && i%3 && i%5 && i%7){
				for(s=11;s*s<=i;s++)
					if(i%s==0)
						break;
				if(s*s>i)
					ans++;
			}
		}
		cout<<ans<<endl;
	}
}