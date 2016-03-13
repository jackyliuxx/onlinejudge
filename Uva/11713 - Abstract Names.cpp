#include<iostream>
#include<string>
using namespace std;
int main(){
	string s1,s2;
	int n,i,ans;
	cin>>n;
	while(n--){
		ans=0;
		cin>>s1>>s2;
		if(s1.size()!=s2.size())
			ans=1;
		else{
			for(i=0;i<s1.size();i++)
				if(s1[i]!=s2[i])
					if((s1[i]!='a'&& s1[i]!='e'&& s1[i]!='i'&&s1[i]!='o'&& s1[i]!='u')||
						(s2[i]!='a'&& s2[i]!='e'&& s2[i]!='i'&&s2[i]!='o'&& s2[i]!='u'))
						ans=1;
		}
		if(ans)
			cout<<"No\n";
		else
			cout<<"Yes\n";
	}
}