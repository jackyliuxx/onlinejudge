#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include "test.h"
using namespace std;

int main () {
	int a,b;
	init();
	a=get_a()+get_b();
	b=a%3;
	if(b==0)
		zero();
	else if(b==1)
		one();
	else
		two();
}
