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
	char c;
	int d=0,t=0;
	int ansd=99999999,anst=99999999;
	while(cin>>c) {
		if((c>='a' && c<='z')||(c>='A' && c<='Z')) {
			int g;
			g=c%3;
			d=d%10000000*10+t/100000;
			t=t%100000*10+g;
			if(d>20130918){
				int dm=(d/100)%100,dd=d%100;
				int th=t/10000,tm=(t/100)%100,ts=t%100;
				if( dm*dd && dm<=12)
					if(d<ansd || (d==ansd && t<anst))
						ansd=d,anst=t;
			}
		}
	}
	int dy=ansd/10000,dm=(ansd/100)%100,dd=ansd%100;
	int th=anst/10000,tm=(anst/100)%100,ts=anst%100;
	printf("%04d/%02d/%02d %02d:%02d:%02d\n",dy,dm,dd,th,tm,ts);
}
