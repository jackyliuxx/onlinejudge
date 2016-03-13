#include<iostream>
using namespace std;
int a[500000],b[500000];
long long ans;
void ms(int x,int y){
	int i,j;
	if(x==y)
		return;
	ms(x,(x+y)/2);
	ms((x+y)/2+1,y);
	i=x,j=(x+y)/2+1;
	while(i<=(x+y)/2){
		if(j>y){
			while(i<=(x+y)/2)
				b[i+(y-(x+y)/2)]=a[i++];
			break;
		}
		if(a[i]>a[j]){
			ans+=(x+y)/2-i+1;
			b[i+j-((x+y)/2+1)]=a[j++];
		}
		else
			b[i+j-((x+y)/2+1)]=a[i++];
	}
	while(x<j)
		a[x]=b[x++];
}
int main(){
	int n;
	while(cin>>n,n){
		ans=0;
		for(int i=0;i<n;i++)
			cin>>a[i];
		ms(0,n-1);
		cout<<ans<<endl;
	}
}