//by jackyliuxx
#include <bits/stdc++.h>
using namespace std;

int main () {
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		vector<string> ss;
		ss.clear();
		string s;
		int x;
		char c;
		ss.push_back("");
		for(int i=1;i<=n;i++){
			cin>>s;
			if(s=="pushfront"){
				cin>>c;
				ss.push_back(c+ss.back());
			}
			if(s=="pushback"){
				cin>>c;
				ss.push_back(ss.back()+c);
			}
			if(s=="undo"){
				cin>>x;
				ss.push_back(ss[i-x-1]);
			}
			cout<<ss.back()<<endl;
		}
	}
}
