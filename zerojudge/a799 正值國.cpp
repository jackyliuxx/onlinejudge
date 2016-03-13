#include <cstdio>
#include <cstring>
using namespace std;

int main () {
	char s[20];
	gets(s);
	if(s[0]=='-')
		puts(s+1);
	else
		puts(s);
}
