#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	unsigned long long x,y,z,ans;
	while(~scanf("%llu%llu%llu",&x,&y,&z)){
		if(x>y)
			swap(x,y);
		if(y>z)
			swap(y,z);
		if(x>y)
			swap(x,y);
		printf("%llu\n",z+(y-x));
	}
}