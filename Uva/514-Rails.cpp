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
using namespace std;

vector<int> stk;

int main () {
	int n;
	int i;
	while(scanf("%d",&n),n) {
		int x,ans;
		while(scanf("%d",&x),x) {
			stk.clear();
			int cnt=1;
			ans=1;
			i=0;
			do {
				if(i)
					scanf("%d",&x);
				if(ans) {
					while(stk.empty() || stk.back()<x)
						stk.push_back(cnt++);
					if(stk.back()==x)
						stk.pop_back();
					else if(stk.back()>x)
						ans=0;
				}
				i++;
			} while(i<n);
			if(ans)
				puts("Yes");
			else
				puts("No");
		}
		puts("");
	}
}
