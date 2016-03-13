#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

int a[1001000],maxn;
vector<int> s[10];

int main () {
	int i,n,t;
	while(~scanf("%d",&n)){
		maxn=0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i]>maxn)
				maxn=a[i];
		}
		t=1;
		do{
			for(i=0;i<10;i++)
				s[i].clear();
			for(i=0;i<n;i++)
				s[(a[i]/t)%10].push_back(a[i]);
			int k=0;
			for(i=0;i<10;i++)
				for(int j=0;j<s[i].size();j++)
					a[k++]=s[i][j];
			t*=10;
		}while(maxn/t);
		for(i=0;i<n;i++){
			if(i)
				printf(" ");
			printf("%d",a[i]);
		}
		puts("");
	}
}
