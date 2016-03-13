#include <iostream>
using namespace std;

int main() {
	int tc,p,i;
	char ch,a[100];
	cin >> tc >> ws;
	while (tc--) {
		for(i=0;i<100;i++)
			a[i]=0;
		p=0;
		while (cin.get(ch) && ch!='\n') {
			if(ch>='0' && ch<='9')
				cout<<ch;
			else if(ch=='(')
				a[p++]=ch;
			else if(ch=='+' || ch=='-'){
				while(--p>=0){
					if(a[p]!='('){
						cout<<a[p];
					}
					else
						break;
				}
				p++;
				a[p++]=ch;
			}
			else if(ch=='*' || ch=='/'){
				while(--p>=0){
					if(a[p]=='*' || a[p]=='/'){
						cout<<a[p];
					}
					else
						break;
				}
				p++;
				a[p++]=ch;
			}
			else if(ch==')'){
				while(--p>=0){
					if(a[p]!='('){
						cout<<a[p];
					}
					else{
						p--;
						break;
					}
				}
				p++;
			}
			cin.get();
		}
		while(--p>=0)
			cout<<a[p];
		if (tc) cout << endl;
	}
}