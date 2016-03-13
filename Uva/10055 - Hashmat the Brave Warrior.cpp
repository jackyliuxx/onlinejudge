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

int main () {
	long long a,b;
	while(~scanf("%lld%lld",&a,&b))
		printf("%lld\n",abs(a-b));
}
