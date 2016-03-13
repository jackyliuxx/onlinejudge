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
using namespace std;

int main () {
	int n,ans,xx;
	while(cin>>n){
		if(n<0)
			xx=-1,n=-n;
		else
			xx=1;
		ans=0;
		while(n){
			ans*=10;
			ans+=n%10;
			n/=10;
		}
		ans*=xx;
		cout<<ans<<endl;
	}
}
