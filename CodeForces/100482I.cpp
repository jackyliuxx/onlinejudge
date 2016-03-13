#include<bits/stdc++.h>
using namespace std;

class mystring{
	private:
		string s;
	public:
		mystring(string ss):s(ss){};
		mystring(){}
		bool operator==(mystring s2){
			return s==s2.s;
		}
		bool equil(mystring s2){
			int df=abs(s.size()-s2.s.size());
			if(df)
				return false;
			int ms=min(s.size(),s2.s.size());
			for(int i=0;i<ms;i++)
				if(s[i]!=s2.s[i])
					df++;
			return df<2;
		}
		friend istream& operator>>(istream &in,mystring& ss){
			in>>ss.s;
			return in;
		}
};

int main(){
	int t,tk=1;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		mystring s[20];
		for(int i=0;i<n;i++)
			cin>>s[i];
		mystring x;
		cout<<"Case #"<<tk++<<":\n";
		while(q--){
			cin>>x;
			int ys=0;
			for(int i=0;i<n;i++){
				if(x==s[i]){
					ys=1;
					break;
				}
			}
			if(!ys){
				for(int i=0;i<n;i++){
					if(x.equil(s[i])){
						ys++;
					}
				}
			}
			if(ys==1)
				puts("yes");
			else
				puts("no");
		}
	}
}
