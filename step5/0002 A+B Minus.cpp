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
#include <ctime>
using namespace std;

int main () {
	int a,b;
	int r;
	srand(time(0));
	while(scanf("%d%d",&a,&b)!=EOF)
		printf("%d\n",rand()%(a+b));
}
