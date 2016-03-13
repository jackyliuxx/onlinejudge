#include<iostream>
#include<string>
using namespace std;
int main(){
	string s,s1="one";
	int n,one,i;
	cin>>n;
	while(n--){
		cin>>s;
		if(s.size()==5)
			cout<<"3\n";
		else{
			one=0;
			for(i=0;i<3;i++)
				if(s[i]==s1[i])
					one++;
			if(one>=2)
				cout<<"1\n";
			else
				cout<<"2\n";
		}
	}
}