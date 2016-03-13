//by jackyliuxx
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <deque>
using namespace std;

int main () {
	string s,ss;
	deque<string> dq;
	while(getline(cin,s)){
		dq.clear();
		int w=1,i;
		ss="";
		for(i=0;i<s.size();i++){
			if(s[i]=='['){
				if(w)
					dq.push_back(ss);
				else
					dq.push_front(ss);
				ss="";
				w=0;
			}
			else if(s[i]==']'){
				if(!w)
					dq.push_front(ss),ss="";
				w=1;
			}
			else
				ss+=s[i];
		}
		if(w)
			dq.push_back(ss);
		else
			dq.push_front(ss);
		while(dq.size()){
			cout<<dq.front();
			dq.pop_front();
		}
		puts("");
	}
}
