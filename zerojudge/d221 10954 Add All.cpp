#include<iostream>
#include<string>
#include<queue>
using namespace std;
int main(){
	long long n,i,a,b,ans;
	priority_queue<int,vector<int>,greater<int> > q;
	while(cin>>n,n){
		while(n--){
			cin>>i;
			q.push(i);
		}
		ans=0;
		while(!q.empty()){
			a=q.top();
			q.pop();
			if(q.empty())
				break;
			b=q.top();
			q.pop();
			ans+=(a+b);
			q.push(a+b);
		}
		cout<<ans<<endl;
	}
}