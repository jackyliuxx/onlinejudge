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

vector<int> road[1000];

int main () {
	int m,n,i,j,a,b;
	while(cin>>m>>n) {
		for(i=0; i<1000; i++)
			road[i].clear();
		for(i=0; i<n; i++) {
			cin>>a>>b;
			road[a].push_back(b);
		}
		cin>>a>>b;
		queue<int> q;
		while(q.empty()==false)
			q.pop();
		q.push(a);
		while(q.empty()==false) {
			a=q.front();
			if(a==b)
				break;
			for(i=0; i<road[a].size(); i++)
				q.push(road[a][i]);
			q.pop();
		}
		if(q.empty()==true)
			puts("No!!!");
		else
			puts("Yes!!!");
	}
}
