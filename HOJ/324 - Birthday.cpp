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

int a[1100000],n;

vector<int> v;

void gans(int &ans){
	int i;
	v.clear();
	for(i=0; i<n; i++) {
		v.push_back(a[i]-(i+1));
		if(v.back()<0)
			v.push_back(v.back()+n);
		else if(v.back()>0)
			v.push_back(v.back()-n);
		else
			v.push_back(n);
	}
	sort(v.begin(),v.end());
	for(i=0;i<=n;i++){
		int nk=abs(v[i]-v[i+n-1]);
		ans=min(ans,nk/2+nk%2);
	}
}


int main () {
	scanf("%d",&n);
	int i;
	int ans=99999999;
	for(i=0; i<n; i++)
		scanf("%d",a+i);
	gans(ans);
	reverse(a,a+n);
	gans(ans);
	printf("%d",ans);

}
