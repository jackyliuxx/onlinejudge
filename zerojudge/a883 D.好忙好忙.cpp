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
#include <map>
#include <set>
using namespace std;

int main () {
	int x,y;
	int t=3;
	set<int> s;
	set<int>::iterator it;
	s.clear();
	bool fail=false;
	while(t--){
		scanf("%d%d",&x,&y);
		s.insert(x);
		s.insert(y);
		it=s.find(x);
		it++;
		if(it!=s.find(y))
			fail=true;
	}
	if(fail)
		puts("QQ");
	else
		puts("Happy");
}
