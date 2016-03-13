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

int main () {
	static int a[1001000],pa[1001000];
	int i;
	for(i=0;scanf("%d",a+i)!=EOF;i++);
	int n=i;
	vector<int> lg;
	lg.clear();
	lg.push_back(a[0]);
	pa[0]=0;
	for(i=1;i<n;i++){
		if(a[i]>lg.back()){
			lg.push_back(a[i]);
			pa[i]=lg.size()-1;
		}
		else{
			vector<int>::iterator p=lower_bound(lg.begin(),lg.end(),a[i]);
			*p=a[i];
			pa[i]=p-lg.begin();
		}
	}
	printf("%d\n-\n",lg.size());
	vector<int> ans;
	ans.clear();
	int now=lg.size();
	for(i=n-1;i>=0;i--){
		if(pa[i]==now-1){
			ans.push_back(a[i]);
			now=pa[i];
		}
	}
	for(i=ans.size()-1;i>=0;i--)
		printf("%d\n",ans[i]);
}
