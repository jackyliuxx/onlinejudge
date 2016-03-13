#include<iostream>
#include<string>
using namespace std;
int o;
string pl(string a,string b){
	string ans,ans2;
	int i,j,t;
	ans=a;
	for(i=0;i<b.size();i++){
		if(ans.size()<=i)
			ans+='0',ans[ans.size()-1]-='0';
		ans[i]+=b[i];
	}
	ans+='0',ans[ans.size()-1]-='0';
	for(i=0;i<ans.size()-1;i++){
		ans[i+1]+=ans[i]/10;
		ans[i]%=10;
	}
	ans2="";
	t=0;
	for(i=ans.size()-1;i>=0;i--){
		t+=ans[i];
		if(t)
			ans2+=ans[i];
	}
	return ans2;
}
string wwww(string s,int n){                                  //*¥¼§¹
	if(s[n]>0)
		s[n]--;
	else{
		s[n]=9;
		s=wwww(s,n+1);
	}
	return s;
}
string mi(string a,string b){
	string ans;
	int i,j;
	if(b.size()>a.size())
		o=1;
	if(b.size()==a.size()){
		for(i=a.size()-1;i>=0;i--){
			if(b[i]<a[i])
				break;
			if(b[i]==a[i])
				continue;
			if(b[i]>a[i]){
				o=1;
				break;
			}
		}
	}
	if(o){
		ans=b;
		for(i=0;i<a.size();i++){
			if(ans.size()<=i)
				ans+='0',ans[ans.size()-1]-='0';
			if(a[i]>ans[i]){
				ans[i]+=10;
				ans=wwww(ans,i+1);
			}
			ans[i]-=a[i];
		}
	}
	else{
		ans=a;
		for(i=0;i<b.size();i++){
			if(ans.size()<=i)
				ans+='0',ans[ans.size()-1]-='0';
			if(b[i]>ans[i]){
				ans[i]+=10;
				ans=wwww(ans,i+1);
			}
			ans[i]-=b[i];
		}
	}
	string ans2="";
	int t=0;
	for(i=ans.size()-1;i>=0;i--){
		t+=ans[i];
		if(t)
			ans2+=ans[i];
	}
	return ans2;
}
string mu(string a,string b){
	string ans,c;
	int i,j,k;
	k=0;
	for(i=0;i<a.size()+b.size();i++)
		ans+='0',ans[ans.size()-1]-='0';
	for(i=0;i<b.size();i++)
		for(j=0;j<a.size();j++){
			ans[i+j]+=a[j]*b[i];
			for(int i=0;i<ans.size()-1;i++){
				ans[i+1]+=ans[i]/10;
				ans[i]%=10;
			}
		}
		string ans2="";
		int t=0;
		ans+='0',ans[ans.size()-1]-='0';
		for(i=0;i<ans.size()-1;i++){
			ans[i+1]+=ans[i]/10;
			ans[i]%=10;
		}
		for(i=ans.size()-1;i>=0;i--){
			t+=ans[i];
			if(t)
				ans2+=ans[i];
		}
		return ans2;
}
string ex(string a,string b){
	string ans,p,s,s2,b2;
	char p2;
	int i,j,k,l;
	for(i=0;i<int(a.size()-b.size()+1);i++)
		ans+='0',ans[ans.size()-1]-='0';
	for(i=a.size()-b.size();i>=0;i--){
		b2=b;
		k=0;
		s2="0";
		s2[0]-='0';
		for(j=0;j<i;j++)
			b2="0"+b2,b2[0]-='0';
		for(j=1;j<10;j++){
			p="0";
			p[0]-='0';
			p[0]+=j;
			s=mu(p,b2);
			for(int f=0;f<s.size()/2;f++)
				swap(s[f],s[s.size()-1-f]);
			if(a.size()<s.size())
				k=1;
			if(a.size()==s.size()){
				for(l=a.size()-1;l>=0;l--){
					if(s[l]<a[l])
						break;
					if(s[l]==a[l])
						continue;
					if(s[l]>a[l]){
						k=1;
						break;
					}
				}
			}
			if(k)
				break;
			s2=s;
		}
		ans[i]=j-1;
		a=mi(a,s2);
		for(int f=0;f<a.size()/2;f++)
			swap(a[f],a[a.size()-1-f]);
		o=0;
	}
	string ans2="";
	int t=0;
	for(i=ans.size()-1;i>=0;i--){
		t+=ans[i];
		if(t)
			ans2+=ans[i];
	}
	return ans2;
}
int main(){
	string a,b,ans,a2,b2;
	int i,j;
	char ch;
	while(cin>>a>>ch>>b){
		ans="";
		o=0;
		a2=a;
		b2=b;
		for(i=0;i<a.size();i++)
			a[i]=a2[a.size()-i-1];
		for(i=0;i<a.size();i++)
			a[i]-='0';
		for(i=0;i<b.size();i++)
			b[i]=b2[b.size()-i-1];
		for(i=0;i<b.size();i++)
			b[i]-='0';
		if(ch=='+')
			ans=pl(a,b);
		if(ch=='-')
			ans=mi(a,b);
		if(ch=='*')
			ans=mu(a,b);
		if(ch=='/')
			ans=ex(a,b);
		if(o)
			cout<<'-';
		for(i=0;i<ans.size();i++)
			ans[i]+='0';
		int t=0;
		for(i=0;i<ans.size();i++){
			t+=ans[i]-'0';
			if(t)
				cout<<ans[i];
		}
		if(t==0)
			cout<<0;
		cout<<endl;
	}
}