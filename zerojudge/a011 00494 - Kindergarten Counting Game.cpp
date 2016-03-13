#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	int i,ans;
	char now,before;
	while(getline(cin,s)){
		before=' ';
		ans=0;
		for(i=0;i<s.size();i++){
			now=s[i];
			if(isalpha(now) && !isalpha(before))
				ans++;
			before=now;
		}
		cout<<ans<<endl;
	}
}